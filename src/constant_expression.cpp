/* expression.cpp */

#include <map>
#include <string>
#include <functional>
#include <stdexcept>
#include <type_traits>

#include "dialogue_driver/combined_criteria.h"
#include "dialogue_driver/constant_expression.h"
#include "dialogue_driver/operator.h"

bool ConstantExpression::VerifyCriteria(const FactCollection &state) const
{
    try
    {
        Fact lhs = state.GetFact(this->_lhsFactName);
        Fact rhs = this->_rhsFact;
        return this->_verifyFunction(lhs, rhs);
    }
    catch(const std::out_of_range& e)
    {
        return false;
    }

    return false;
}

int ConstantExpression::GetWeight() const
{
    return 1;
}

std::function<bool(Fact&, Fact&)> ConstantExpression::_BuildExpression(COMPARISON_OPERATOR op)
{
    switch (op)
    {
        case COP_EQUAL:
            return [](Fact& lhs, Fact& rhs) 
            {
                return lhs == rhs;
            };
        case COP_NOT_EQUAL:
            return [](Fact& lhs, Fact& rhs) 
            {
                return lhs != rhs;
            };
        case COP_LT:
            return [](Fact& lhs, Fact& rhs) 
            {
                return lhs < rhs;
            };
        case COP_LTE:
            return [](Fact& lhs, Fact& rhs) 
            {
                return lhs <= rhs;
            };
        case COP_GT:
            return [](Fact& lhs, Fact& rhs) 
            {
                return lhs > rhs;
            };
        case COP_GTE:
            return [](Fact& lhs, Fact& rhs)
            {
                return lhs >= rhs;
            };
        default:
            return [](Fact& lhs, Fact& rhs) {return false; };
    }
}