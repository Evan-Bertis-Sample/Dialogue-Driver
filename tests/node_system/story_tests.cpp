#include <iostream>
#include <vector>

#include "gtest/gtest.h"
#include "dialogue_driver/story.h"
#include "dialogue_driver/story_entity.h"
#include "dialogue_driver/expression.h"
#include "dialogue_driver/iobridge.h"
#include "dialogue_driver/query.h"
#include "dialogue_driver/expression.h"
#include "dialogue_driver/operator.h"
#include "dialogue_driver/constant_expression.h"

class StoryTest : public ::testing::Test
{
protected:
    // Set up variables for tests
    FactCollection factTemplate;
    Story testStory = Story(factTemplate);
    StoryEntity actor1 = StoryEntity("Actor1");
    StoryEntity actor2 = StoryEntity("Actor2");
    Scene scene1;
    IOBridge bridge = IOBridge(
        [](std::string output)
        { std::cout << output << std::endl; },
        [](std::vector<std::string> choices)
        { return 0; });
    std::shared_ptr<ConversationNode> nextNode1 = std::make_shared<ConversationNode>(actor1);
    EntryNode entryNode1 = EntryNode(nextNode1);
};

TEST_F(StoryTest, AddAndRetrieveActor)
{
    testStory.AddActor("Actor1", actor1);
    EXPECT_EQ(testStory.GetActor("Actor1"), actor1);
}

TEST_F(StoryTest, RemoveActor)
{
    testStory.AddActor("Actor2", actor2);
    testStory.RemoveActor("Actor2");
    EXPECT_THROW(testStory.GetActor("Actor2"), std::exception);
}

TEST_F(StoryTest, AddAndRetrieveSymbol)
{
    testStory.AddSymbol("collection1", "symbol1");
    EXPECT_EQ(testStory.GetSymbol("collection1", 0), "symbol1");
}

TEST_F(StoryTest, UpdateSymbol)
{
    testStory.AddSymbol("collection1", "symbol1");
    testStory.UpdateSymbol("collection1", 0, "symbol2");
    EXPECT_EQ(testStory.GetSymbol("collection1", 0), "symbol2");
}

TEST_F(StoryTest, AddAndRemoveEntryPoint)
{
    testStory.AddEntryPoint(actor1, entryNode1);
    testStory.RemoveEntryPoint(actor1, entryNode1);
    // Test will pass if no exception is thrown
}

TEST_F(StoryTest, Converse)
{
    testStory.AddActor("Actor1", actor1);
    testStory.AddEntryPoint(actor1, entryNode1);
    testStory.Converse(actor1, scene1, bridge);
    // Test will pass if no exception is thrown
}

TEST_F(StoryTest, AddMultipleActors) {
    testStory.AddActor("Actor1", actor1);
    testStory.AddActor("Actor2", actor2);
    EXPECT_EQ(testStory.GetActor("Actor1"), actor1);
    EXPECT_EQ(testStory.GetActor("Actor2"), actor2);
}

TEST_F(StoryTest, AddMultipleSymbols) {
    testStory.AddSymbol("collection1", "symbol1");
    testStory.AddSymbol("collection1", "symbol2");
    EXPECT_EQ(testStory.GetSymbol("collection1", 0), "symbol1");
    EXPECT_EQ(testStory.GetSymbol("collection1", 1), "symbol2");
}

TEST_F(StoryTest, CheckQuery) {
    Query query;
    EXPECT_TRUE(testStory.CheckQuery(query));
}

TEST_F(StoryTest, UpdateFact) {
    FactCollection collection;
    collection.AddFact("fact1", std::string("Invalid"));

    Story tempStory(collection);
    tempStory.UpdateFact("fact1", std::string("newFact1"));

    Query query;
    query.AddCriteria(ConstantExpression("fact1", COP_EQUAL, std::string("newFact1")));
    EXPECT_TRUE(tempStory.CheckQuery(query));
}

TEST_F(StoryTest, ConverseMultipleTimes) {
    testStory.AddActor("Actor1", actor1);
    testStory.AddEntryPoint(actor1, entryNode1);
    testStory.Converse(actor1, scene1, bridge);
    testStory.Converse(actor1, scene1, bridge);
    // Test will pass if no exception is thrown
}

TEST_F(StoryTest, ConverseWithDifferentActors) {
    std::shared_ptr<ConversationNode> nextNode2 = std::make_shared<ConversationNode>(actor2);
    EntryNode entryNode2 = EntryNode(nextNode2);
    testStory.AddActor("Actor1", actor1);
    testStory.AddActor("Actor2", actor2);
    testStory.AddEntryPoint(actor1, entryNode1);
    testStory.AddEntryPoint(actor2, entryNode2);
    testStory.Converse(actor1, scene1, bridge);
    testStory.Converse(actor2, scene1, bridge);
    // Test will pass if no exception is thrown
}
