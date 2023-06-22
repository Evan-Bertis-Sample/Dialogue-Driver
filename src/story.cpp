/* story.cpp */

#include <map>
#include <string>
#include <vector>
#include <string>

#include "dialogue_driver/story.h"
#include "dialogue_driver/story_entity.h"
#include "dialogue_driver/expression.h"
#include "dialogue_driver/iobridge.h"
#include "dialogue_driver/query.h"

void Story::AddSymbol(std::string collectionName, std::string symbol)
{
    if (this->_symbols.find(collectionName) == this->_symbols.end())
    {
        // Create a collection
        Story::_SymbolCollection collection;
        collection.emplace_back(symbol);
        this->_symbols[collectionName] = collection;
        return;
    }

    // Add to an existing collection
    this->_symbols[collectionName].emplace_back(symbol);
}

std::string Story::GetSymbol(std::string collectionName, int symbolID) const
{
    if (this->_symbols.find(collectionName) == this->_symbols.end())
        throw std::out_of_range("Symbol collection does not exist!");

    Story::_SymbolCollection collection = this->_symbols.at(collectionName);

    if (symbolID > collection.size() || symbolID < 0)
        throw std::out_of_range("Symbol ID cannot be found!");

    return collection[symbolID];
}

void Story::UpdateSymbol(std::string collectionName, int symbolID, std::string newSymbol)
{
    if (this->_symbols.find(collectionName) == this->_symbols.end())
        throw std::out_of_range("Symbol collection does not exist!");

    Story::_SymbolCollection &collection = this->_symbols[collectionName];

    if (symbolID > collection.size() || symbolID < 0)
        throw std::out_of_range("Symbol ID cannot be found!");

    collection[symbolID] = newSymbol;
}

void Story::AddActor(std::string actorName, StoryEntity &actor)
{
    if (this->_actors.find(actorName) != this->_actors.end())
        return; // No need to add actor
    this->_actors[actorName] = actor;
}

void Story::RemoveActor(std::string actorName)
{
    auto it = this->_actors.find(actorName);
    if (it == this->_actors.end())
        return; // No actor found
    this->_actors.erase(it);
}

StoryEntity &Story::GetActor(std::string actorName)
{
    if (this->_actors.find(actorName) == this->_actors.end())
        throw std::out_of_range("Cannot find Actor!");

    return this->_actors[actorName];
}

void Story::Converse(StoryEntity &entryPoint, Scene &scene, IOBridge &bridge)
{
    // Find the EntrySet for a given StoryEntity
    if (this->_conversations.find(entryPoint) == this->_conversations.end())
    {
        // there was no conversations associated
        return;
    }

    Story::_EntrySet set = this->_conversations[entryPoint];
    std::shared_ptr<ConversationNode> node = nullptr;

    // Now we must find the highest priority scene that meets criteria
    for (auto entry : set)
    {
        if (!entry.MeetsCriteria(this->_state))
            continue; // Criteria not met
        if (!entry.IsPlausible(scene))
            continue; // Actors not found

        // We have found our most specific entry point
        // Converse with this path
        node = entry.Next;
        break;
    }

    // "Converse"
    while (node != nullptr)
    {
        node->ProcessCommands(*this, scene, bridge);
        node = node->Next(*this, scene);
    }
}

void Story::AddEntryPoint(StoryEntity &actor, EntryNode &node)
{
    if (this->_conversations.find(actor) == this->_conversations.end())
    {
        // No entry points found for this actor
        Story::_EntrySet set;
        set.emplace(node);
        this->_conversations[actor] = set;
    }

    // Existing set of entry points
    this->_conversations[actor].emplace(node);
}

void Story::RemoveEntryPoint(StoryEntity &actor, EntryNode &node)
{
    if (this->_conversations.find(actor) == this->_conversations.end())
        throw std::out_of_range("Cannot find entry points for actor!");

    Story::_EntrySet set = this->_conversations[actor];

    auto it = std::find(set.begin(), set.end(), node);

    if (it == set.end())
        throw std::out_of_range("Cannot find entry point for deletion");

    set.erase(it);
    this->_conversations[actor] = set;
}

bool Story::CheckQuery(Query &query) const
{
    return this->_state.CheckQuery(query);
}