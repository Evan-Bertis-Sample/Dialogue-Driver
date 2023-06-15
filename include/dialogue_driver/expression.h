#ifndef EXPRESSION_H
#define EXPRESSION_H

#pragma once

#include <string>
#include <functional>

#include "fact.h"
#include "operator.h"
#include "fact_collection.h"
#include "icriteria.h"

class Expression : public ICriteria
{
public:
    // * Constructors
    Expression(std::string lhsFact, COMPARISON_OPERATOR op, std::string rhsFact) : _lhsFactName(lhsFact), _operation(op), _rhsFactName(rhsFact)
    {
        this->_verifyFunction = _BuildExpression(op);
    };

    Expression() : _lhsFactName(std::string()), _operation(COP_EQUAL), _rhsFactName(std::string()) {};

    Expression(const Expression &other)
    {
        this->_lhsFactName = other._lhsFactName;
        this->_operation = other._operation;
        this->_rhsFactName = other._rhsFactName;
        this->_verifyFunction = other._verifyFunction;
    }

    // * Methods
    bool VerifyCriteria(const FactCollection &state) const override;

private:
    std::string _lhsFactName;
    COMPARISON_OPERATOR _operation;
    std::string _rhsFactName;
    std::function<bool(Fact&, Fact&)> _verifyFunction;

    std::function<bool(Fact&, Fact&)> _BuildExpression(COMPARISON_OPERATOR op);
};

#endif // EXPRESSION_H