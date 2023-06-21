#ifndef STORY_H
#define STORY_H

#pragma once

#include <map>
#include <string>
#include <functional>
#include <vector>
#include <memory>
#include <string>
#include <set>

#include "expression.h"
#include "query.h"
#include "fact_collection.h"
#include "story_entity.h"
#include "iobridge.h"
#include "entry_node.h"
#include "scene.h"

//
// Stories are comprised of symbols, which can represent characters, locations, etc.
//
class Story
{
public:
    // Create a Story given a fact collection.
    // Once a story is made around a fact collection, you are unable to add facts that the story is comprised of.
    Story(FactCollection factTemplate) : _state(factTemplate) {}
    Story() {}
    Story(const Story &other) :
        _state(other._state), _symbols(other._symbols), _actors(other._actors), _conversations(other._conversations) {};

    void AddSymbol(std::string collectionName, std::string symbol);
    std::string GetSymbol(std::string collectionName, int symbolID) const;
    void UpdateSymbol(std::string collectionName, int symbolID, std::string newSymbol);

    void AddActor(std::string actorName, StoryEntity &actor);
    void RemoveActor(std::string actorName);
    StoryEntity &GetActor(std::string actorName);
    void Converse(StoryEntity &entryPoint, Scene &scene, IOBridge &bridge);

    void AddEntryPoint(StoryEntity &actor, EntryNode &node);
    void RemoveEntryPoint(StoryEntity &actor, EntryNode &node);

    template <typename T>
    void UpdateFact(std::string name, T value)
    {
        this->_state.UpdateFact(name, value);
    };

    bool CheckQuery(Query &query) const;


private:
    FactCollection _state;

    typedef std::vector<std::string> _SymbolCollection;
    std::map<std::string, _SymbolCollection> _symbols;

    std::map<std::string, StoryEntity> _actors;

    typedef std::set<EntryNode, EntryNode::EntryCompare> _EntrySet;
    std::map<StoryEntity, _EntrySet> _conversations;
};

#endif // STORY