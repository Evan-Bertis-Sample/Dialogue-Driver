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
#include "iobridge.h"

class ConversationNode;

struct PriorityNode
{
    int priority;
    std::shared_ptr<ConversationNode> node;

    struct Compare
    {
        bool operator()(const PriorityNode &below, const PriorityNode &above) const
        {
            return below.priority > above.priority;
        }
    };
};

class Story;
class IConversationCommand;
class Scene;

class ConversationNode
{
public:
    StoryEntity Speaker;

    ConversationNode(){};
    ConversationNode(StoryEntity speaker) : Speaker(speaker) {}
    ConversationNode(const ConversationNode &other) : _successorsByWeight(other._successorsByWeight), _successors(other._successors), _processCommands(other._processCommands) {}

    std::shared_ptr<ConversationNode> Next(Story &story, Scene &scene) const;

    std::vector<std::shared_ptr<ConversationNode>> GetPlausibleNext(Story &story, Scene &scene) const;

    bool IsPlausible(Scene &scene) const;

    void ProcessCommands(Story &story, Scene &scene, IOBridge &bridge);

    bool ConnectNode(std::shared_ptr<ConversationNode> node);
    bool DisconnectNode(std::shared_ptr<ConversationNode> node);
    std::shared_ptr<ConversationNode> GetNode(int nodeIndex);
    int NumNodes() const;

    template <typename T>
    void AddCommand(T command)
    {
        if (!std::is_base_of<IConversationCommand, T>::value)
        {
            throw std::logic_error("Invalid type of ConversationCommand!");
        }

        auto commandPtr = std::make_shared<T>(command);
        this->_processCommands.push_back(commandPtr);
    }
    template <typename T>
    void RemoveCommand(T command)
    {
        if (!std::is_base_of<IConversationCommand, T>::value)
        {
            throw std::logic_error("Invalid type of ConversationCommand!");
        }

        auto it = std::find_if(this->_processCommands.begin(), this->_processCommands.end(), [command] (const std::shared_ptr<IConversationCommand> &rhs)
        {
            // auto commandPtr = std::make_shared(command);
            // auto lhsCast = std::dynamic_pointer_cast<T>(commandPtr);
            auto rhsCast = std::dynamic_pointer_cast<T>(rhs);
            return command == *rhsCast;
        });
        if (it == this->_processCommands.end())
            return;

        this->_processCommands.erase(it);
    }

    std::vector<std::shared_ptr<IConversationCommand>> GetCommands()
    {
        return this->_processCommands;
    }

    void UpdateSuccessorPriority(std::shared_ptr<ConversationNode>, int newPriority);

    // * Operators
    bool operator==(const ConversationNode &other) const
    {
        if (this->Speaker != other.Speaker)
        {
            return false;
        }

        if (this->_successors.size() != other._successors.size())
        {
            return false;
        }
        for (size_t i = 0; i < this->_successors.size(); ++i)
        {
            if (*(this->_successors[i]) != *(other._successors[i]))
            {
                return false;
            }
        }

        if (this->_processCommands.size() != other._processCommands.size())
        {
            return false;
        }
        for (size_t i = 0; i < this->_processCommands.size(); ++i)
        {
            if ((this->_processCommands[i].get()) != (other._processCommands[i].get()))
            {
                return false;
            }
        }

        return true;
    }

    bool operator !=(const ConversationNode &other) const
    {
        return !(*this == other);
    }

private:
    std::set<PriorityNode, PriorityNode::Compare> _successorsByWeight;

    std::vector<std::shared_ptr<ConversationNode>> _successors;
    std::vector<std::shared_ptr<IConversationCommand>> _processCommands;

    void _DeleteNodeFromSet(std::shared_ptr<ConversationNode> nodePtr);
};

#endif // CONVERSATION_NODE_H