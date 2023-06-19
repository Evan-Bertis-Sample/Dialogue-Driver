#ifndef CONSTANT_EXPRESSION_H
#define CONSTANT_EXPRESSION_H

#pragma once

#include <string>
#include <functional>

#include "fact.h"
#include "operator.h"
#include "fact_collection.h"
#include "icriteria.h"

class ConstantExpression : public ICriteria
{
public:
    // * Constructors
    template <typename T>
    ConstantExpression(std::string lhsFact, COMPARISON_OPERATOR op, T constValue) : _lhsFactName(lhsFact), _operation(op), _rhsFact(Fact(constValue))
    {
        this->_verifyFunction = _BuildExpression(op);
    };

    ConstantExpression() : _lhsFactName(std::string()), _operation(COP_EQUAL), _rhsFact(Fact()) {};

    ConstantExpression(const ConstantExpression &other)
    {
        this->_lhsFactName = other._lhsFactName;
        this->_operation = other._operation;
        this->_rhsFact = other._rhsFact;
        this->_verifyFunction = other._verifyFunction;
    }

    // * Methods
    bool VerifyCriteria(const FactCollection &state) const override;

    int GetWeight() const override;

private:
    std::string _lhsFactName;
    COMPARISON_OPERATOR _operation;
    Fact _rhsFact;
    std::function<bool(Fact&, Fact&)> _verifyFunction;

    std::function<bool(Fact&, Fact&)> _BuildExpression(COMPARISON_OPERATOR op);
};

#endif // CONSTANT_EXPRESSION_H