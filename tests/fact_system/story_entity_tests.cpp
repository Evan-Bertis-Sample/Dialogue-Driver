#include <iostream>
#include <string>
#include <memory>

#include "gtest/gtest.h"
#include "dialogue_driver/expression.h"
#include "dialogue_driver/constant_expression.h"
#include "dialogue_driver/story_entity.h"
#include "dialogue_driver/query.h"
#include "dialogue_driver/operator.h"
#include "dialogue_driver/combined_criteria.h"

TEST(StoryEntity, Basic_Operations)
{
    StoryEntity entity("Hero");

    entity.AddAttribute("Health", 100);
    entity.AddAttribute("Strength", 50);
    entity.AddAttribute("Magic", 25);
    entity.AddAttribute("Alive", true);

    ASSERT_EQ(entity.GetAttribute<int>("Health"), 100);
    ASSERT_EQ(entity.GetAttribute<int>("Strength"), 50);
    ASSERT_EQ(entity.GetAttribute<int>("Magic"), 25);
    ASSERT_EQ(entity.GetAttribute<bool>("Alive"), true);

    entity.UpdateAttribute("Health", 75);
    ASSERT_EQ(entity.GetAttribute<int>("Health"), 75);
}

TEST(StoryEntity, CheckQuery_Single_Criteria)
{
    StoryEntity entity("Hero");
    entity.AddAttribute("Health", 100);

    Query query;
    query.AddCriteria(ConstantExpression("Health", COP_EQUAL, 100));

    ASSERT_TRUE(entity.CheckQuery(query));
}

TEST(StoryEntity, CheckQuery_Multiple_Criteria)
{
    StoryEntity entity("Hero");
    entity.AddAttribute("Health", 100);
    entity.AddAttribute("Strength", 50);

    Query query;
    query.AddCriteria(ConstantExpression("Health", COP_GT, 50));
    query.AddCriteria(ConstantExpression("Strength", COP_LT, 100));

    ASSERT_TRUE(entity.CheckQuery(query));
}

TEST(StoryEntity, CheckQuery_Combined_Criteria)
{
    StoryEntity entity("Hero");
    entity.AddAttribute("Health", 100);
    entity.AddAttribute("Strength", 50);
    entity.AddAttribute("Magic", 25);

    ConstantExpression healthCriteria("Health", COP_EQUAL, 100);
    ConstantExpression strengthCriteria("Strength", COP_GT, 30);

    CombinedCriteria combined(healthCriteria, LOP_AND, strengthCriteria);

    Query query;
    query.AddCriteria(combined);

    ASSERT_TRUE(entity.CheckQuery(query));
}

TEST(StoryEntity, CheckQuery_Negative)
{
    StoryEntity entity("Hero");
    entity.AddAttribute("Health", 100);

    Query query;
    query.AddCriteria(ConstantExpression("Health", COP_EQUAL, 50)); // this is not true

    ASSERT_FALSE(entity.CheckQuery(query));
}

TEST(StoryEntity, CheckQuery_MissingAttribute)
{
    StoryEntity entity("Hero");
    entity.AddAttribute("Health", 100);

    Query query;
    query.AddCriteria(ConstantExpression("Magic", COP_EQUAL, 50)); // Magic attribute does not exist

    ASSERT_FALSE(entity.CheckQuery(query));
}

TEST(StoryEntity, UpdateAttribute_Single)
{
    StoryEntity entity("Hero");
    entity.AddAttribute("Health", 100);

    entity.UpdateAttribute("Health", 75);
    ASSERT_EQ(entity.GetAttribute<int>("Health"), 75);
}

TEST(StoryEntity, UpdateAttribute_Multiple)
{
    StoryEntity entity("Hero");
    entity.AddAttribute("Health", 100);
    entity.AddAttribute("Strength", 50);

    entity.UpdateAttribute("Health", 75);
    entity.UpdateAttribute("Strength", 60);

    ASSERT_EQ(entity.GetAttribute<int>("Health"), 75);
    ASSERT_EQ(entity.GetAttribute<int>("Strength"), 60);
}

TEST(StoryEntity, UpdateAttribute_TypeChange)
{
    StoryEntity entity("Hero");
    entity.AddAttribute("Name", std::string("OldName"));

    entity.UpdateAttribute("Name", std::string("NewName"));
    ASSERT_EQ(entity.GetAttribute<std::string>("Name"), "NewName");
}

TEST(StoryEntity, UpdateAttribute_Bool)
{
    StoryEntity entity("Hero");
    entity.AddAttribute("Alive", true);

    entity.UpdateAttribute("Alive", false);
    ASSERT_EQ(entity.GetAttribute<bool>("Alive"), false);
}

TEST(StoryEntity, UpdateAttribute_NonExistent)
{
    StoryEntity entity("Hero");

    ASSERT_NO_THROW(entity.UpdateAttribute("Health", 100));
}

TEST(StoryEntity, GetName)
{
    StoryEntity entity("Hero");
    ASSERT_EQ(entity.GetName(), "Hero");
}
