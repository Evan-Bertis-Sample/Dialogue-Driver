/* entry_node.cpp */

#include "dialogue_driver/entry_node.h"
#include "dialogue_driver/scene.h"
#include "dialogue_driver/conversation_node.h"
#include "dialogue_driver/query.h"
#include "dialogue_driver/fact_collection.h"

bool EntryNode::IsPlausible(Scene &scene) const
{
    return this->Next->IsPlausible(scene);
}

int EntryNode::GetPriority() const
{
    return this->_criteria.GetWeight();
}

bool EntryNode::MeetsCriteria(FactCollection &state)
{
    return state.CheckQuery(_criteria);
}

bool EntryNode::operator ==(const EntryNode &other) const
{
    return Next.get() == other.Next.get() && this->_criteria == other._criteria;
}

bool EntryCompare::operator()(const EntryNode &below, const EntryNode &above) const
{
    return below.GetPriority() > above.GetPriority();
}