/* conversation_node.cpp */

#include <map>
#include <string>
#include <vector>
#include <memory>

#include "dialogue_driver/i_conversation_command.h"
#include "dialogue_driver/story_entity.h"
#include "dialogue_driver/scene.h"
#include "dialogue_driver/conversation_node.h"
#include "dialogue_driver/story.h"

std::shared_ptr<ConversationNode> ConversationNode::Next(Story &story, Scene &scene) const
{
    for (auto &pNode : this->_successorsByWeight)
    {
        if (pNode.node->IsPlausible(scene))
        {
            return pNode.node;   
        }
    }

    return nullptr;
}

std::vector<std::shared_ptr<ConversationNode>> ConversationNode::GetPlausibleNext(Story &story, Scene &scene) const
{
    std::vector<std::shared_ptr<ConversationNode>> plausible;

    for (auto node : this->_successors)
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

// void ConversationNode::ProcessCommands(Story &story)
// {
//     for (auto &command : this->_processCommands)
//     {
//         command->Execute(*this, story);
//     }
// }

bool ConversationNode::ConnectNode(std::shared_ptr<ConversationNode> node)
{
    auto found = std::find(this->_successors.begin(), this->_successors.end(), node);
    if (found == this->_successors.end()) return false;

    this->_successors.push_back(node);
    int priority = this->_successors.size();
    PriorityNode tempNode { priority, node };
    this->_successorsByWeight.insert(tempNode);
    return true;
}

bool ConversationNode::DisconnectNode(std::shared_ptr<ConversationNode> node)
{
    auto found = std::find(this->_successors.begin(), this->_successors.end(), node);
    if (found == this->_successors.end()) return false;

    this->_successors.erase(found);
    this->_DeleteNodeFromSet(node);
    return true;
}

std::shared_ptr<ConversationNode> ConversationNode::GetNode(int nodeIndex)
{
    if (nodeIndex > this->_successors.size())
    {
        throw std::out_of_range("Successor Node cannot be found!");
    }

    return this->_successors[nodeIndex];
}

void ConversationNode::UpdateSuccessorPriority(std::shared_ptr<ConversationNode> nodePtr, int newPriority)
{
    this->_DeleteNodeFromSet(nodePtr);

    // Create a temporary PriorityNode with the new priority and shared_ptr
    PriorityNode tempPriorityNode{ newPriority, nodePtr };
    // Insert the new PriorityNode with updated priority
    this->_successorsByWeight.insert(tempPriorityNode);
}

void ConversationNode::_DeleteNodeFromSet(std::shared_ptr<ConversationNode> nodePtr)
{
    // Find the existing PriorityNode in the set with the same node
    auto it = std::find_if(this->_successorsByWeight.begin(), this->_successorsByWeight.end(), [nodePtr](const PriorityNode& pNode) {
        return pNode.node.get() == nodePtr.get();
    });

    if (it != this->_successorsByWeight.end()) {
        // Erase the existing PriorityNode from the set
        this->_successorsByWeight.erase(it);
    }
}