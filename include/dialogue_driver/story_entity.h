#ifndef SYMBOL_ENTITY_H
#define SYMBOL_ENTITY_H
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


class StoryEntity
{
public:
    std::string GetName() const;
    
    template<typename T>
    void AddAttribute(std::string attribute, T value);

    template<typename T>
    T GetAttribute(std::string attribute) const;
    
    template<typename T>
    void UpdateAttribute(std::string attribute, T value);

private:
    std::string _name;
    FactCollection _attributes;
}

#endif // Story_Entity