#ifndef COMBINED_CRITERIA_H
#define COMBINED_CRITERIA_H

#pragma once

#include <string>
#include <functional>
#include <memory>
#include <exception>

#include "fact.h"
#include "operator.h"
#include "fact_collection.h"
#include "icriteria.h"

class CombinedCriteria : public ICriteria
{
public:
    // * Constructors
    template <typename T>
    CombinedCriteria(const T &lhs, LOGICAL_OPERATOR op,  const T &rhs):
        _operation(op)
    {
        if (!std::is_base_of<ICriteria, T>::value)
            throw std::logic_error("Invalid type for Combined Criteria!");

        this->_lhs = std::make_shared<T>(lhs);
        this->_rhs = std::make_shared<T>(rhs);

        this->_verifyFunction = this->_BuildExpression(op);
    }

    CombinedCriteria():
        _lhs(nullptr), _rhs(nullptr), _operation(LOP_AND), _verifyFunction(nullptr){}

    CombinedCriteria(const CombinedCriteria &other):
        _lhs(other._lhs), _rhs(other._rhs), _operation(other._operation), _verifyFunction(other._verifyFunction){}
    
    // * Methods   
    bool VerifyCriteria(const FactCollection &state) const;

private:
    std::shared_ptr<ICriteria> _lhs;
    std::shared_ptr<ICriteria> _rhs;
    LOGICAL_OPERATOR _operation;
    std::function<bool(bool, bool)> _verifyFunction;

    std::function<bool(bool,bool)> _BuildExpression(LOGICAL_OPERATOR op);
};

#endif // COMBINED_CRITERIA_H