#ifndef QUERY_H
#define QUERY_H

#pragma once

#include <vector>
#include <memory>
#include <type_traits>

#include "icriteria.h"

class Query
{
public:
    typedef std::vector<std::shared_ptr<ICriteria>> CriteriaCollection;

    template <typename T>
    void AddCriteria(T criteria)
    {
        if (!std::is_base_of<ICriteria, T>::value) return;

        _collection.push_back(std::make_shared<T>(criteria));
    }

    CriteriaCollection GetCriteria() const
    {
        return _collection;
    }

    int GetWeight() const
    {
        int weight = 0;
        for(auto &crit : _collection)
        {
            weight += crit->GetWeight();
        }

        return weight;
    }

private:
    CriteriaCollection _collection;
};

#endif // QUERY_H