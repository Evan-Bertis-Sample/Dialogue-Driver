#ifndef CONVERSATION_NODE_H
#define CONVERSATION_NODE_H

#pragma once

#include <map>
#include <string>
#include <vector>
#include <memory>
#include <queue>

#include "story.h"
#include "i_conversation_command.h"
#include "story_entity.h"
#include "scene.h"

class ConversationNode
{
public:
    typedef struct
    {
        int priority;
        std::shared_ptr<ConversationNode> node;
    } PriorityNode;

    StoryEntity Speaker;

    ConversationNode();
    ConversationNode(const ConversationNode &other);

    void std::shared_ptr<ConversationNode> Next(Story &story, Scene &scene) const;
    void std::vector<std::shared_ptr<ConversationNode>> GetPlausibleNext(Story &story, Scene &scene) const;

    void Process(Story &story);

    bool ConnectNode(std::shared_ptr<ConversationNode> node);
    bool DisconnectNode(std::shared_ptr<ConversationNode> node);

    template <typename T>
    void AddCommand(T command);
    template <typename T>
    void RemoveCommand(T command);

    void UpdateSuccessorPriority(std::shared_ptr<ConversationNode>, )

private:
    typedef 
    std::vector<std::shared_ptr<ConversationNode>> _successors;
    std::vector<std::shared_ptr<IConversationCommand>> _processCommands;
}

#endif // CONVERSATION_NODE_H