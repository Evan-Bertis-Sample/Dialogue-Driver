#ifndef I_CONVERSATION_COMMAND_H
#define I_CONVERSATION_COMMAND_H

#pragma once

#include <map>
#include <string>
#include <functional>
#include <vector>
#include <memory>

#include "story.h"
#include "iobridge.h"

class ConversationNode;
class Story;

class IConversationCommand
{
public:
    // A method that can be called async that controls the flow of a conversation,
    // what may be output from a conversation, or anything else, really.
    virtual void Execute(ConversationNode &node, Story &story, IOBridge &bridge) = 0;
};

#endif // I_CONVERSATION_COMMAND_H