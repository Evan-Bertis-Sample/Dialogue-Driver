#ifndef STORY_STATE_H
#define STORY_STATE_H

#pragma once

#include <map>
#include <string>
#include <functional>
#include <vector>

#include "icriteria.h"

/// @brief Stores the state of a "story"
class StoryState {
public:
    // ! template methods are my enemy
    template<typename T>
    bool CheckQuery(std::vector<ICriteria> criteria) const
    {
        for (const ICriteria &crit : criteria)
        {
            if (crit.VerifyCriteria(*this) == false)
                return false;
        }

        return false;
    }

    template<typename T>
    void AddFact(std::string factName, T data)
    {
        if (this->_ContainsFact(factName)) return;

        Fact value(data);
        this->_facts[factName] = value;
    }
    
    template<typename T>
    void UpdateFact(std::string factName, T data)
    {
        if (this->_ContainsFact(factName)) this->_facts[factName].Set<T>(data);
    }

    template<typename T>
    T GetFact(std::string factName) const
    {
        if (!this->_ContainsFact(factName))
            throw std::out_of_range("Cannot find Fact!");

        Fact fact = this->_facts.at(factName);
        return fact.Get<T>();
    }

private:
    std::map<std::string, Fact> _facts;

    bool _ContainsFact(std::string factName) const;
};

#endif // STORY_STATE