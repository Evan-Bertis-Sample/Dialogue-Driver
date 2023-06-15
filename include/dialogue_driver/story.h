#ifndef STORY_H
#define STORY_H

#pragma once

#include <map>
#include <string>
#include <functional>
#include <vector>
#include <memory>

#include "icriteria.h"
#include "expression.h"
#include "query.h"
#include "fact_collection.h"
#include "conversation.h"

//
// Stories are comprised of symbols, which can represent characters, locations, etc.
//
class Story
{
public:
    void AddSymbol(std::string collectionName, std::string symbol);
    void GetSymbol(std::string collectionName, int symbolID) const;

    void Converse(std::string entryPoint) const;

private:
    FactCollection _state;

    typedef std::vector<std::string> _SymbolCollection;
    std::map<std::string, _SymbolCollection> _symbolMap;

    std::map<std::string, std::shared_ptr<Conversation>> _conversations;
}

#endif // STORY