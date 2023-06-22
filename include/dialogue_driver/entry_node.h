#ifndef ENTRY_NODE_H
#define ENTRY_NODE_H

#pragma once

#include <memory>

#include "conversation_node.h"
#include "query.h"
#include "scene.h"
#include "fact_collection.h"

class ConversationNode;

class EntryNode
{
public:
    std::shared_ptr<ConversationNode> Next;

    EntryNode(std::shared_ptr<ConversationNode> next) : Next(next) {};

    bool IsPlausible(Scene &scene) const;
    int GetPriority() const;
    bool MeetsCriteria(FactCollection &state);
    bool operator ==(const EntryNode &other) const;

private:
    Query _criteria;
};

struct EntryCompare
{
    bool operator()(const EntryNode &below, const EntryNode &above) const;
};

#endif // ENTRY_NODE_H