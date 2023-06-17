#ifndef CONVERSATION_NODE_H
#define CONVERSATION_NODE_H

#pragma once

#include <map>
#include <string>
#include <functional>
#include <vector>
#include <memory>

#include "story.h"

class ConversationNode
{
public:
    virtual std::shared_ptr<ConversationNode> Next(Story& Story) const = 0;
    virtual void OnNode() = 0;
    
    bool ConnectNode(std::shared_ptr<ConversationNode> node);
    bool DisconnectNode(std::shared_ptr<ConversationNode> node);
}

#endif // CONVERSATION_NODE_H