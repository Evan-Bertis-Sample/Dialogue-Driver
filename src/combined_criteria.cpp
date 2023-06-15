/* expression.cpp */

#include <map>
#include <string>
#include <functional>
#include <stdexcept>
#include <type_traits>
#include <memory>

#include "dialogue_driver/combined_criteria.h"
#include "dialogue_driver/operator.h"

bool CombinedCriteria::VerifyCriteria(const FactCollection &state) const
{
    bool lhs = this->_lhs->VerifyCriteria(state);
    bool rhs = this->_rhs->VerifyCriteria(state);

    return this->_verifyFunction(lhs, rhs);
}

std::function<bool(bool, bool)> CombinedCriteria::_BuildExpression(LOGICAL_OPERATOR op)
{
    switch (op)
    {
        case LOP_AND:
            return [](bool lhs, bool rhs)
            {
                return lhs && rhs;
            };
        case LOP_OR:
            return [](bool lhs, bool rhs)
            {
                return lhs || rhs;
            };
        default:
            return nullptr;
    }
}