#ifndef I_CONVERSATION_COMMAND_H
#define I_CONVERSATION_COMMAND_H

#pragma once

#include <map>
#include <string>
#include <functional>
#include <vector>
#include <memory>

#include "story.h"
#include "conversation_node.h"

class IConversationCommand
{
public:
    virtual void Execute(ConversationNode &node, Story &story) = 0;
}

#endif // I_CONVERSATION_COMMAND_H