/* conversation_node.cpp */

#include <map>
#include <string>
#include <vector>
#include <memory>

#include "i_conversation_command.h"
#include "story_entity.h"
#include "scene.h"
#include "conversation_node.h"

std::shared_ptr<ConversationNode> ConversationNode::Next(Story &story, Scene &scene) const
{
    std::shared_ptr<ConversationNode> next = nullptr;

    while (!this->_successorsByPriority.empty())
    {
        next = this->_successorsByWeight.top();
        if (next->IsPlausible(scene)) break;
    }

    return next;
}

std::vector<std::shared_ptr<ConversationNode>> ConversationNode::GetPlausibleNext(Story &story, Scene &scene)
{
    std::vector<std::shared_ptr<ConversationNode>> plausible;

    for (auto &node : this->_successors)
    {
        if (node->IsPlausible(scene))
        {
            plausible.push_back(node);
        }
    }

    return plausible;
}

bool ConversationNode::IsPlausible(Scene &scene) const
{
    bool thisNodePlausible = scene.IsAvailable(this->Speaker);
    if (!thisNodePlausible) return false;

    if (this->_successors.size() == 0) return true; // No successors

    // Recursively check the next nodes to see
    for (const auto &node : this->_successors)
    {
        bool plausible = node->IsPlausible(scene);
        if (plausible) return true; // This means at least one successor is available
    }

    return false; // No plausible successors, therefore this branch is void
}

void ConversationNode::Process(Story &story)
{
    for (auto &command : this->_processCommands)
    {
        command->Execute(*this, story);
    }
}

bool ConversationNode::ConnectNode(std::shared_ptr<ConversationNode> node)
{
    auto found = std::find(this->_successors.begin(), this->_successors.end(), node);
    if (found == this->_successors.end()) return false;

    this->_successors.push_back(node);
    return true;
}

bool ConversationNode::DisconnectNode(std::shared_ptr<ConversationNode> node)
{
    auto found = std::find(this->_successors.begin(), this->_successors.end(), node);
    if (found == this->_successors.end()) return false;

    this->_successors.erase(found);
    return true;
}

void ConversationNode::UpdateSuccessorPriority(std::shared_ptr<ConversationNode>, int newPriority)
{
    
}