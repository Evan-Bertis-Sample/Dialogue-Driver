#ifndef ICRITERIA_H
#define ICRITERIA_H

#pragma once

#include <string>

#include "fact.h"
#include "operator.h"
#include "fact_collection.h"

// Notify the compiler that this class will be defined
class FactCollection;

class ICriteria
{
public:
    // Given a StoryState, verify if the given criteria is met
    virtual bool VerifyCriteria(const FactCollection &state) const
    {
        return false;
    }

    virtual int GetWeight() const
    {
        return 0;
    }
};

#endif // ICRITERIA_H