#ifndef ENTRY_NODE_H
#define ENTRY_NODE_H

#pragma once

#include <memory>

#include "conversation_node.h"
#include "query.h"
#include "scene.h"
#include "fact_collection.h"

class EntryNode
{
public:
    std::shared_ptr<ConversationNode> Next;

    EntryNode(std::shared_ptr<ConversationNode> next) : Next(next) {};

    struct EntryCompare
    {
        bool operator()(const EntryNode &below, const EntryNode &above) const
        {
            return below.GetPriority() > above.GetPriority();
        }
    };

    bool IsPlausible(Scene &scene) const
    {
        return this->Next->IsPlausible(scene);
    }

    int GetPriority() const
    {
        return this->_criteria.GetWeight();
    }

    bool MeetsCriteria(FactCollection &state)
    {
        return state.CheckQuery(_criteria);
    }

    // * Operators
    bool operator ==(const EntryNode &other) const
    {
        return *(this->Next) == *(this->Next) && this->_criteria == other._criteria;
    }

private:
    Query _criteria;
};

#endif // ENTRY_NODE_H