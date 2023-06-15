#include <iostream>

#include "gtest/gtest.h"
#include "dialogue_driver/driver.h"
#include "dialogue_driver/fact.h"
#include "dialogue_driver/story_state.h"

TEST(StoryState, State_Addition)
{
    StoryState state;
    state.AddFact("Name", std::string("Evan Bertis-Sample"));
    state.AddFact("Age", 19);
    state.AddFact("GPA", 3.6f);

    assert(state.GetFact<std::string>("Name") == "Evan Bertis-Sample");
    assert(state.GetFact<int>("Age") == 19);
    assert(state.GetFact<float>("GPA") == 3.6f);
}

TEST(StoryState, State_Update)
{
    StoryState state;
    state.AddFact("Name", std::string("Evan"));
    state.UpdateFact("Name", std::string("Ethan"));

    assert(state.GetFact<std::string>("Name") == "Ethan");
}

TEST(StoryState, State_GetFact)
{
    StoryState state;
    state.AddFact("Age", 20);
    
    EXPECT_EQ(state.GetFact<int>("Age"), 20);
    EXPECT_THROW(state.GetFact<std::string>("Age"), std::bad_variant_access);
}

TEST(StoryState, State_GetNonExistentFact)
{
    StoryState state; 
    
    EXPECT_THROW(state.GetFact<int>("NonExistent"), std::out_of_range);
}

TEST(StoryState, State_UpdateNonExistentFact)
{
    StoryState state;
    
    EXPECT_NO_THROW(state.UpdateFact("NonExistent", 30));
}

TEST(StoryState, State_UpdateFactDifferentType)
{
    StoryState state;
    state.AddFact("Age", 20);
    
    EXPECT_NO_THROW(state.UpdateFact("Age", std::string("Twenty")));
}

TEST(StoryState, State_BooleanFact)
{
    StoryState state;
    state.AddFact("IsAdult", true);
    
    EXPECT_TRUE(state.GetFact<bool>("IsAdult"));
}

TEST(StoryState, State_AddSameFactTwice)
{
    StoryState state;
    state.AddFact("Age", 20);
    state.AddFact("Age", 30);
    
    int age = state.GetFact<int>("Age");
    EXPECT_TRUE(age == 20);
}
