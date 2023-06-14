#ifndef EXPRESSION_H
#define EXPRESSION_H

#pragma once

#include <string>
#include <functional>

#include "fact.h"
#include "operator.h"
#include "story_state.h"
#include "icriteria.h"

class Expression : public ICriteria
{
public:
    // * Constructors
    template <typename T>
    Expression(std::string fact, COMPARISON_OPERATOR op, T _rhs);

    Expression();

    Expression(const Expression &other);

    // * Methods
    bool VerifyCriteria(const StoryState &state) const;

private:
    std::string _factName;
    COMPARISON_OPERATOR _operation;
    Fact _rhs;

    template <typename T>
    std::function<bool(T, T)> _BuildExpression(COMPARISON_OPERATOR op);
};

#endif // EXPRESSION_H