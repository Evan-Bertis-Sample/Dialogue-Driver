#include <iostream>

#include "gtest/gtest.h"
#include "dialogue_driver/fact.h"
#include "dialogue_driver/fact_collection.h"
#include "dialogue_driver/icriteria.h"
#include "dialogue_driver/operator.h"
#include "dialogue_driver/expression.h"
#include "dialogue_driver/combined_criteria.h"


TEST(CombinedCriteria, Both_Valid)
{
    FactCollection state;
    state.AddFact("lhs", 1.0f);
    state.AddFact("rhs", 1.0f);

    Expression expr1("lhs", COP_EQUAL, "rhs");
    Expression expr2("rhs", COP_EQUAL, "lhs");

    CombinedCriteria andExpr(expr1, LOP_AND, expr2);

    assert(andExpr.VerifyCriteria(state));
}

TEST(CombinedCriteria, One_Invalid)
{
    FactCollection state;
    state.AddFact("A", 1.0f);
    state.AddFact("B", 2.0f);

    Expression expr1("A", COP_EQUAL, "B"); // This is false
    Expression expr2("B", COP_EQUAL, "B");

    CombinedCriteria andExpr(expr1, LOP_AND, expr2);

    assert(!andExpr.VerifyCriteria(state));
}

TEST(CombinedCriteria, Both_Invalid)
{
    FactCollection state;
    state.AddFact("A", 1.0f);
    state.AddFact("B", 2.0f);

    Expression expr1("A", COP_EQUAL, "B"); // This is false
    Expression expr2("A", COP_EQUAL, "B"); // This is also false

    CombinedCriteria andExpr(expr1, LOP_AND, expr2);

    assert(!andExpr.VerifyCriteria(state));
}

TEST(CombinedCriteria, Or_Operator)
{
    FactCollection state;
    state.AddFact("A", 1.0f);
    state.AddFact("B", 2.0f);

    Expression expr1("A", COP_EQUAL, "A"); // This is true
    Expression expr2("A", COP_EQUAL, "B"); // This is false

    CombinedCriteria orExpr(expr1, LOP_OR, expr2);

    assert(orExpr.VerifyCriteria(state)); // true OR false is true
}

TEST(CombinedCriteria, Or_Operator_AllInvalid)
{
    FactCollection state;
    state.AddFact("A", 1.0f);
    state.AddFact("B", 2.0f);

    Expression expr1("A", COP_EQUAL, "B"); // This is false
    Expression expr2("A", COP_EQUAL, "B"); // This is also false

    CombinedCriteria orExpr(expr1, LOP_OR, expr2);

    assert(!orExpr.VerifyCriteria(state)); // false OR false is false
}
