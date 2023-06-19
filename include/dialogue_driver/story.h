#ifndef STORY_H
#define STORY_H

#pragma once

#include <map>
#include <string>
#include <functional>
#include <vector>
#include <memory>
#include <string>

#include "expression.h"
#include "query.h"
#include "fact_collection.h"
#include "conversation.h"
#include "story_entity.h"

//
// Stories are comprised of symbols, which can represent characters, locations, etc.
//
class Story
{
public:
    // Create a Story given a fact collection.
    // Once a story is made around a fact collection, you are unable to add facts that the story is comprised of.
    Story(FactCollection factTemplate) :
        _state(factTemplate) {}

    // Story(const Story &other) :
    //     _state(other._state), _symbols {};

    void AddSymbol(std::string collectionName, std::string symbol);
    void GetSymbol(std::string collectionName, int symbolID) const;

    StoryEntity GetActor(std::string actorName);
    void Converse(StoryEntity entryPoint) const;

    template <typename T>
    void UpdateFact(std::string name, T value);
    bool CheckQuery(Query query) const;

private:
    FactCollection _state;

    typedef std::vector<std::string> _SymbolCollection;
    std::map<std::string, _SymbolCollection> _symbols;
    
    std::map<std::string, StoryEntity> _actors;
    std::map<StoryEntity, std::shared_ptr<Conversation>> _conversations;
};

#endif // STORY