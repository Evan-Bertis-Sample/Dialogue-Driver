#ifndef FACT_COLLECTION_H
#define FACT_COLLECTION_H

#pragma once

#include <map>
#include <string>
#include <functional>
#include <vector>
#include <memory>

#include "icriteria.h"
#include "expression.h"
#include "query.h"

/// @brief Stores a collection of facts
class FactCollection {
public:
    // * Public Methods
    bool CheckQuery(const Query &query) const
    {
        Query::CriteriaCollection criteria = query.GetCriteria();

        for (const auto &crit : criteria)
        {
            if (crit->VerifyCriteria(*this) == false)
                return false;
        }

        return true;
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

    Fact GetFact(std::string factName) const
    {
        if (!this->_ContainsFact(factName))
            throw std::out_of_range("Cannot find Fact1");

        Fact fact = this->_facts.at(factName);
        return fact;
    }

    // * Operators
    bool operator ==(const FactCollection &other) const
    {
        for (const auto &[key, value] : other._facts)
        {
            if (this->_ContainsFact(key) == false) return false;
        }

        return true;
    }

private:
    std::map<std::string, Fact> _facts;

    bool _ContainsFact(std::string factName) const;
};

#endif // STORY_STATE