#ifndef SYMBOL_ENTITY_H
#define SYMBOL_ENTITY_H
#pragma once

#include <map>
#include <string>
#include <vector>
#include <memory>

#include "query.h"
#include "fact_collection.h"

class StoryEntity
{
public:
    StoryEntity(std::string name):
        _name(name) {};
    
    StoryEntity(const StoryEntity &other):
        _name(other._name), _attributes(other._attributes) {};

    StoryEntity():
        _name(std::string("")), _attributes(FactCollection()) {};

    std::string GetName() const;

    bool CheckQuery(const Query &query) const
    {
        return this->_attributes.CheckQuery(query);
    }

    template<typename T>
    void AddAttribute(std::string attribute, T value)
    {
        this->_attributes.AddFact(attribute, value);
    }

    template<typename T>
    T GetAttribute(std::string attribute) const
    {
        return this->_attributes.GetFact<T>(attribute);
    }
    
    template<typename T>
    void UpdateAttribute(std::string attribute, T value)
    {
        this->_attributes.UpdateFact(attribute, value);
    }

private:
    std::string _name;
    FactCollection _attributes;
};

#endif // Story_Entity