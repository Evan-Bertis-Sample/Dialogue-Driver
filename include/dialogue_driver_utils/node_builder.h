#ifndef NODE_BUILDER_H
#define NODE_BUILDER_H

#pragma once

#include <memory>
#include <vector>

#include "../dialogue_driver/conversation_node.h"
#include "../dialogue_driver/i_conversation_command.h"
#include "../dialogue_driver/output_command.h"
#include "../dialogue_driver/story_entity.h"
#include "../dialogue_driver/choice_command.h";

// A collection of handy functions to build nodes
class NodeBuilder
{
public:
    static std::shared_ptr<ConversationNode> BuildOutputNode(std::string context);
    static std::shared_ptr<ConversationNode> BuildChoiceNode(std::vector<>)
};

#endif // NODE_BUILDER_H