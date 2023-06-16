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

    bool CheckCriteria(Story& story) const;
    
    int GetWeight() const;

private:
    Query _criteria;
}

#endif // CONVERSATION_NODE_H