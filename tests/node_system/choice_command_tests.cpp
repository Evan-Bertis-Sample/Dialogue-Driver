/* choice_command_tests.cpp */

#include "gtest/gtest.h"
#include "dialogue_driver/fact.h"
#include "dialogue_driver/fact_collection.h"
#include "dialogue_driver/icriteria.h"
#include "dialogue_driver/operator.h"
#include "dialogue_driver/expression.h"
#include "dialogue_driver/combined_criteria.h"
#include "dialogue_driver/story.h"
#include "dialogue_driver/scene.h"
#include "dialogue_driver/output_command.h"
#include "dialogue_driver_utils/node_builder.h"

TEST(ChoiceCommandTests, AddChoiceByComponents)
{
    Query criteria;
    std::string previewText = "Preview Text";
    ChoiceCommand command;
    command.AddChoice(criteria, previewText);

    // Verify choice added successfully.
    Choice choice = command.GetChoice(0);
    EXPECT_EQ(choice.criteria, criteria);
    EXPECT_EQ(choice.previewText, previewText);
}

TEST(ChoiceCommandTests, RemoveChoice_ValidIndex)
{
    Query criteria;
    std::string previewText = "Preview Text";
    ChoiceCommand command;
    command.AddChoice(criteria, previewText);
    command.RemoveChoice(0);

    EXPECT_THROW(command.GetChoice(0), std::out_of_range);
}

TEST(ChoiceCommandTests, RemoveChoice_InvalidIndex)
{
    ChoiceCommand command;
    EXPECT_THROW(command.GetChoice(0), std::out_of_range);
}

TEST(ChoiceCommandTests, RemoveChoice_Multiple)
{
    Query criteria;
    std::string previewText = "Preview Text";
    ChoiceCommand command;
    command.AddChoice(criteria, previewText);
    command.AddChoice(criteria, previewText);
    command.RemoveChoice(1);
    command.RemoveChoice(0);

    EXPECT_THROW(command.GetChoice(0), std::out_of_range);
}

TEST(ChoiceCommandTests, Execute_Simple)
{
    // This is hella setup...

    StoryEntity actor("Evan");
    std::vector<Choice> choices;
    Query noReq;

    choices.push_back(Choice{noReq, std::string("First Option!")});
    choices.push_back(Choice{noReq, std::string("Second Option!")});

    auto choiceNodePtr = NodeBuilder::BuildChoiceNode(actor, choices);
    ASSERT_EQ(choiceNodePtr->Speaker.GetName(), actor.GetName());
    std::string output = "Second Node!";
    auto outputNodePtr = NodeBuilder::BuildOutputNode(actor, output);
    ASSERT_EQ(outputNodePtr->Speaker.GetName(), actor.GetName());

    choiceNodePtr->ConnectNode(outputNodePtr);

    IOBridge bridge = IOBridge(
        [](std::string output)
        { std::cout << output << std::endl; },
        [](std::vector<std::string> choices)
        { return 0; });

    Story mockStory;
    mockStory.AddActor("Evan", actor);

    Scene mockScene;
    mockScene.AddAvailableActor(actor);

    choiceNodePtr->ProcessCommands(mockStory, mockScene, bridge);
    auto next = choiceNodePtr->Next(mockStory, mockScene);

    ASSERT_EQ(next.get(), outputNodePtr.get());
}