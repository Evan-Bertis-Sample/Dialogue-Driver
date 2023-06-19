#ifndef CONVERSATION_NODE_H
#define CONVERSATION_NODE_H

#pragma once

#include <map>
#include <string>
#include <vector>
#include <memory>
#include <set>

#include "story.h"
#include "i_conversation_command.h"
#include "story_entity.h"
#include "scene.h"

typedef struct PriorityNode
{
    int priority;
    std::shared_ptr<ConversationNode> node;
}

class PriorityNodeCompare {
public:
    bool operator()(PriorityNode &below, PriorityNode &above)
    {
        return below.priority > above.priority;
    }
}

class ConversationNode
{
public:
    StoryEntity Speaker;

    ConversationNode() {};
    ConversationNode(const ConversationNode &other):
    _successorsByPriority(other._successorsByPriority), _successors(other._successors), _processCommands(other._processCommands){};

    std::shared_ptr<ConversationNode> Next(Story &story, Scene &scene) const;
    std::vector<std::shared_ptr<ConversationNode>> GetPlausibleNext(Story &story, Scene &scene) const;
    bool IsPlausible(Scene &scene) const;

    void Process(Story &story);

    bool ConnectNode(std::shared_ptr<ConversationNode> node);
    bool DisconnectNode(std::shared_ptr<ConversationNode> node);

    template <typename T>
    void AddCommand(T command);
    template <typename T>
    void RemoveCommand(T command);

    void UpdateSuccessorPriority(std::shared_ptr<ConversationNode>, int newPriority);

private:
    std::set<PriorityNode, PriorityNodeCompare> _successorsByWeight;
    
    std::vector<std::shared_ptr<ConversationNode>> _successors;
    std::vector<std::shared_ptr<IConversationCommand>> _processCommands;
}

#endif // CONVERSATION_NODE_H