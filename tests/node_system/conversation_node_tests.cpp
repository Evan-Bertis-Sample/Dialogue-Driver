#include <iostream>
#include <memory>
#include <vector>
#include <string>

#include "gtest/gtest.h"
#include "dialogue_driver/fact.h"
#include "dialogue_driver/fact_collection.h"
#include "dialogue_driver/icriteria.h"
#include "dialogue_driver/operator.h"
#include "dialogue_driver/expression.h"
#include "dialogue_driver/combined_criteria.h"
#include "dialogue_driver/iobridge.h"
#include "dialogue_driver/story.h"
#include "dialogue_driver/scene.h"
#include "dialogue_driver/output_command.h"

class ConversationNodeTests : public ::testing::Test
{
protected:
    StoryEntity actor1;
    StoryEntity actor2;

    std::shared_ptr<ConversationNode> node1Ptr;
    std::shared_ptr<ConversationNode> node2Ptr;

    Story story;
    Scene scene;

    std::string mockContent = std::string("Blah");

    IOBridge bridge = IOBridge(
        [](std::string output)
        { std::cout << output << std::endl; },
        [](std::vector<std::string> choices)
        { return 0; });

    void SetUp() override
    {
        actor1 = StoryEntity("actor1");
        actor2 = StoryEntity("actor2");

        node1Ptr = std::make_shared<ConversationNode>(actor1);
        node2Ptr = std::make_shared<ConversationNode>(actor2);
    }
};

TEST_F(ConversationNodeTests, CreateAndGetSpeaker)
{
    EXPECT_EQ(node1Ptr->Speaker, actor1);
}

TEST_F(ConversationNodeTests, AddAndRetrieveCommand)
{
    auto command = OutputCommand(mockContent);
    node1Ptr->AddCommand(command);
    auto retrievedCommands = node1Ptr->GetCommands();
    // EXPECT_EQ(retrievedCommands[0], command);
}

TEST_F(ConversationNodeTests, RemoveCommand)
{
    auto command = OutputCommand(mockContent);
    node1Ptr->AddCommand(command);
    node1Ptr->RemoveCommand(command);
    auto retrievedCommands = node1Ptr->GetCommands();
    EXPECT_TRUE(retrievedCommands.empty());
}

TEST_F(ConversationNodeTests, ConnectNodes)
{
    node1Ptr->ConnectNode(node2Ptr);
    EXPECT_EQ(node1Ptr->GetNode(0), node2Ptr);
}

TEST_F(ConversationNodeTests, DisconnectNodes)
{
    node1Ptr->ConnectNode(node2Ptr);
    node1Ptr->DisconnectNode(node2Ptr);
    EXPECT_THROW(node1Ptr->GetNode(0), std::out_of_range);
}

TEST_F(ConversationNodeTests, UpdateSuccessorPriority)
{
    node1Ptr->ConnectNode(node2Ptr);
    node1Ptr->UpdateSuccessorPriority(node2Ptr, 10);
    scene.AddAvailableActor(node2Ptr->Speaker);
    auto nextNode = node1Ptr->Next(story, scene);
    EXPECT_EQ(nextNode, node2Ptr);
}

TEST_F(ConversationNodeTests, CheckPlausibility)
{
    scene.AddAvailableActor(actor1);
    scene.AddAvailableActor(actor2);
    node1Ptr->ConnectNode(node2Ptr);
    EXPECT_TRUE(node1Ptr->IsPlausible(scene));
}

TEST_F(ConversationNodeTests, GetPlausibleNextNodes)
{
    scene.AddAvailableActor(actor1);
    scene.AddAvailableActor(actor2);
    node1Ptr->ConnectNode(node2Ptr);
    auto plausibleNodes = node1Ptr->GetPlausibleNext(story, scene);
    // EXPECT_EQ(plausibleNodes[0], node2Ptr);
}

TEST_F(ConversationNodeTests, ProcessCommands)
{
    auto command = OutputCommand(mockContent);
    node1Ptr->AddCommand(command);
    // EXPECT_CALL(*command, Execute(testing::Ref(*node1Ptr), testing::Ref(story), testing::Ref(bridge))).Times(1);
    node1Ptr->ProcessCommands(story, bridge);
}

TEST_F(ConversationNodeTests, GetNextNode) {
    scene.AddAvailableActor(actor1);
    scene.AddAvailableActor(actor2);
    node1Ptr->ConnectNode(node2Ptr);
    auto nextNode = node1Ptr->Next(story, scene);
    EXPECT_EQ(*nextNode, *node2Ptr);
}

TEST_F(ConversationNodeTests, ComparisonOperators) {
    auto node3Ptr = std::make_shared<ConversationNode>(actor1);
    EXPECT_TRUE(*node1Ptr == *node3Ptr);
    EXPECT_FALSE(*node1Ptr != *node3Ptr);
}
