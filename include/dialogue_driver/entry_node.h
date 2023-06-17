#ifndef ENTRY_NODE_H
#define ENTRY_NODE_H
#pragma once

#include <map>
#include <string>
#include <functional>
#include <vector>
#include <memory>

#include "story.h"
#include "conversation_node.h"
#include "query.h"

class EntryNode : public ConversationNode
{
public:
    EntryNode(Query criteria):
        _criteria(criteria) {}

    virtual std::shared_ptr<ConversationNode> Next(Story& story) const override;
    virtual void OnNode() = 0;

    bool CheckCriteria(Story& story) const;

    bool ConnectNode(std::shared_ptr<ConversationNode> node) override;
    bool DisconnectNode(std::shared_ptr<ConversationNode> node) override;

    int GetWeight() const;

private:
    Query _criteria;
    std::vector<std::shared_ptr<ConversationNode>> _successors;
}

#endif // CONVERSATION_NODE_H