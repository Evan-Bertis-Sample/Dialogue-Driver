#ifndef NODE_BUILDER_H
#define NODE_BUILDER_H

#pragma once

#include <memory>
#include <vector>

#include "../dialogue_driver/conversation_node.h"
#include "../dialogue_driver/i_conversation_command.h"
#include "../dialogue_driver/output_command.h"
#include "../dialogue_driver/story_entity.h"
#include "../dialogue_driver/choice_command.h"

// A collection of handy functions to build nodes
class NodeBuilder
{
public:
    // Build a simple node that only outputs text to the IOBridge
    static std::shared_ptr<ConversationNode> BuildOutputNode(StoryEntity &actor, std::string &content);

    // Build a simple node that only outputs text to the IOBridge
    static std::shared_ptr<ConversationNode> BuildChoiceNode(StoryEntity &actor, std::vector<Choice> &choices);

    // Build a compound node that:
    //  1) Outputs text to the IOBridge
    //  2) Prompts the IOBridge with choices
    static std::shared_ptr<ConversationNode> BuildBranchNode(StoryEntity &actor, std::string &content, std::vector<Choice> &choices);
};

#endif // NODE_BUILDER_H