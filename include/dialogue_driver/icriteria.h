#ifndef ICRITERIA_H
#define ICRITERIA_H

#pragma once

#include <string>

#include "fact.h"
#include "operator.h"
#include "story_state.h"

class ICriteria
{
public:
    // Given a StoryState, verify if the given criteria is met
    virtual bool VerifyCriteria(const StoryState &state) const
    {
        return false;
    }
};

#endif // ICRITERIA_H