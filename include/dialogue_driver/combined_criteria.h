#ifndef COMBINED_CRITERIA_H
#define COMBINED_CRITERIA_H

#pragma once

#include <string>
#include <functional>

#include "fact.h"
#include "operator.h"
#include "story_state.h"
#include "icriteria.h"

class CombinedCriteria : public ICriteria
{
public:
    // * Constructors
    template <typename T>
    CombinedCriteria(const ICriteria &_lhs, COMPARISON_OPERATOR op,  const ICriteria &_rhs);

    CombinedCriteria();

    CombinedCriteria(const CombinedCriteria &other);

    // * Methods
    bool VerifyCriteria(const StoryState &state) const;

private:
    ICriteria _lhs;
    ICriteria _rhs;
    LOGICAL_OPERATOR _operation;

    std::function<bool(bool,bool)> _BuildExpression(LOGICAL_OPERATOR op);
};

#endif // COMBINED_CRITERIA_H