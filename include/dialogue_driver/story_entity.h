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
    // * Constructors 
    StoryEntity(std::string name):
        _name(name) {};
    
    StoryEntity(const StoryEntity &other):
        _name(other._name), _attributes(other._attributes) {};

    StoryEntity():
        _name(std::string("")), _attributes(FactCollection()) {};

    // * Public Methods
    std::string GetName() const
    {
        return this->_name;
    }

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

    // * Operators
    bool operator ==(const StoryEntity &other) const
    {
        return (this->_name == other._name) && (this->_attributes == this->_attributes);
    }

    bool operator !=(const StoryEntity &other) const
    {
        return !(*this == other);
    }

    bool operator<(const StoryEntity& other) const
    {
        // You can define the order as per your requirements.
        // Here's a simple example, ordering by name.
        return this->_name < other._name;
    }

private:
    std::string _name;
    FactCollection _attributes;
};

#endif // Story_Entity