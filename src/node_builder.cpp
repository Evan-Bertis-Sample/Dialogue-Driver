/* node_builder.cpp */

#include <iostream>
#include <memory>
#include <vector>

#include "dialogue_driver_utils/node_builder.h"
#include "dialogue_driver/i_conversation_command.h"
#include "dialogue_driver/output_command.h"
#include "dialogue_driver/story_entity.h"
#include "dialogue_driver/choice_command.h"
#include "dialogue_driver/conversation_node.h"

std::shared_ptr<ConversationNode> NodeBuilder::BuildOutputNode(StoryEntity &actor, std::string &content)
{
    std::cout << "Building Output Node" << std::endl;
    ConversationNode node(actor);
    std::cout << node.Speaker.GetName() << std::endl;
    OutputCommand output(content);
    node.AddCommand(output);
    return std::make_shared<ConversationNode>(node);
}

std::shared_ptr<ConversationNode> NodeBuilder::BuildChoiceNode(StoryEntity &actor, std::vector<Choice> &choices)
{
    std::cout << "Building Choice Node" << std::endl;
    ConversationNode node(actor);
    std::cout << node.Speaker.GetName() << std::endl;
    ChoiceCommand choice(choices);
    node.AddCommand(choice);
    return std::make_shared<ConversationNode>(node);
}

std::shared_ptr<ConversationNode> NodeBuilder::BuildBranchNode(StoryEntity &actor, std::string &content, std::vector<Choice> &choices)
{
    ConversationNode node(actor);
    OutputCommand output(content);
    node.AddCommand(output);

    ChoiceCommand choice(choices);
    node.AddCommand(choice);
    return std::make_shared<ConversationNode>(node);
}