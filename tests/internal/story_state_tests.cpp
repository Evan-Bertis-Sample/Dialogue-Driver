#include <iostream>
#include <string>
#include <memory>

#include "gtest/gtest.h"
#include "dialogue_driver/driver.h"
#include "dialogue_driver/fact.h"
#include "dialogue_driver/fact_collection.h"
#include "dialogue_driver/icriteria.h"
#include "dialogue_driver/expression.h"

TEST(FactCollection, State_Addition)
{
    FactCollection state;
    state.AddFact("Name", std::string("Evan Bertis-Sample"));
    state.AddFact("Age", 19);
    state.AddFact("GPA", 3.6f);

    assert(state.GetFact<std::string>("Name") == "Evan Bertis-Sample");
    assert(state.GetFact<int>("Age") == 19);
    assert(state.GetFact<float>("GPA") == 3.6f);
}

TEST(FactCollection, State_Update)
{
    FactCollection state;
    state.AddFact("Name", std::string("Evan"));
    state.UpdateFact("Name", std::string("Ethan"));

    assert(state.GetFact<std::string>("Name") == "Ethan");
}

TEST(FactCollection, State_GetFact)
{
    FactCollection state;
    state.AddFact("Age", 20);
    
    EXPECT_EQ(state.GetFact<int>("Age"), 20);
    EXPECT_THROW(state.GetFact<std::string>("Age"), std::bad_variant_access);
}

TEST(FactCollection, State_GetNonExistentFact)
{
    FactCollection state; 
    
    EXPECT_THROW(state.GetFact<int>("NonExistent"), std::out_of_range);
}

TEST(FactCollection, State_UpdateNonExistentFact)
{
    FactCollection state;
    
    EXPECT_NO_THROW(state.UpdateFact("NonExistent", 30));
}

TEST(FactCollection, State_UpdateFactDifferentType)
{
    FactCollection state;
    state.AddFact("Age", 20);
    
    EXPECT_NO_THROW(state.UpdateFact("Age", std::string("Twenty")));
}

TEST(FactCollection, State_BooleanFact)
{
    FactCollection state;
    state.AddFact("IsAdult", true);
    
    EXPECT_TRUE(state.GetFact<bool>("IsAdult"));
}

TEST(FactCollection, State_AddSameFactTwice)
{
    FactCollection state;
    state.AddFact("Age", 20);
    state.AddFact("Age", 30);
    
    int age = state.GetFact<int>("Age");
    EXPECT_TRUE(age == 20);
}

TEST(FactCollection, CheckQuery_AllValid)
{
    FactCollection state;
    state.AddFact("A", 5);
    state.AddFact("B", 10);
    state.AddFact("C", 15);

    Query query;
    query.AddCriteria(Expression("A", COP_LT, "B"));
    query.AddCriteria(Expression("B", COP_LT, "C"));

    assert(state.CheckQuery(query));
}

TEST(FactCollection, CheckQuery_OneInvalid)
{
    FactCollection state;
    state.AddFact("A", 5);
    state.AddFact("B", 10);
    state.AddFact("C", 15);

    Query query;
    query.AddCriteria(Expression("A", COP_GT, "B"));  // This is false
    query.AddCriteria(Expression("B", COP_LT, "C"));

    assert(!state.CheckQuery(query));
}

TEST(FactCollection, CheckQuery_MixedTypes)
{
    FactCollection state;
    state.AddFact("A", 5);
    state.AddFact("B", std::string("test"));

    Query query;
    query.AddCriteria(Expression("A", COP_EQUAL, "A"));
    query.AddCriteria(Expression("B", COP_EQUAL, "B"));

    assert(state.CheckQuery(query));
}

TEST(FactCollection, CheckQuery_MissingFact)
{
    FactCollection state;
    state.AddFact("A", 5);
    state.AddFact("B", 10);

    Query query;
    query.AddCriteria(Expression("A", COP_EQUAL, "C"));  // Fact "C" is not present

    assert(!state.CheckQuery(query));
}


