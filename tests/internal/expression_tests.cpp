#include <iostream>

#include "gtest/gtest.h"
#include "dialogue_driver/fact.h"
#include "dialogue_driver/story_state.h"
#include "dialogue_driver/icriteria.h"
#include "dialogue_driver/operator.h"
#include "dialogue_driver/expression.h"

TEST(Expression, Expression_Basic)
{
    StoryState state;
    state.AddFact("lhs", 1.0f);
    state.AddFact("rhs", 1.0f);

    Expression expression("lhs", COP_EQUAL, "rhs");

    assert(expression.VerifyCriteria(state));
}

TEST(Expression, Expression_NotEqual)
{
    StoryState state;
    state.AddFact("lhs", 1.0f);
    state.AddFact("rhs", 2.0f);

    Expression expression("lhs", COP_NOT_EQUAL, "rhs");

    assert(expression.VerifyCriteria(state));
}

TEST(Expression, Expression_LessThan)
{
    StoryState state;
    state.AddFact("lhs", 1.0f);
    state.AddFact("rhs", 2.0f);

    Expression expression("lhs", COP_LT, "rhs");

    assert(expression.VerifyCriteria(state));
}

TEST(Expression, Expression_GreaterThan)
{
    StoryState state;
    state.AddFact("lhs", 3.0f);
    state.AddFact("rhs", 2.0f);

    Expression expression("lhs", COP_GT, "rhs");

    assert(expression.VerifyCriteria(state));
}

TEST(Expression, Expression_GreaterThanOrEqual)
{
    StoryState state;
    state.AddFact("lhs", 2.0f);
    state.AddFact("rhs", 2.0f);

    Expression expression("lhs", COP_GTE, "rhs");

    assert(expression.VerifyCriteria(state));
}

TEST(Expression, Expression_LessThanOrEqual)
{
    StoryState state;
    state.AddFact("lhs", 2.0f);
    state.AddFact("rhs", 2.0f);

    Expression expression("lhs", COP_LTE, "rhs");

    assert(expression.VerifyCriteria(state));
}

TEST(Expression, Expression_CopyConstructor)
{
    StoryState state;
    state.AddFact("lhs", 2.0f);
    state.AddFact("rhs", 2.0f);

    Expression expression1("lhs", COP_EQUAL, "rhs");
    Expression expression2 = expression1;

    assert(expression2.VerifyCriteria(state));
}

// Test with std::string
TEST(Expression, Expression_String)
{
    StoryState state;
    state.AddFact("lhs", std::string("test"));
    state.AddFact("rhs", std::string("test"));

    Expression expression("lhs", COP_EQUAL, "rhs");

    assert(expression.VerifyCriteria(state));
}

// Test with bool
TEST(Expression, Expression_Bool)
{
    StoryState state;
    state.AddFact("lhs", true);
    state.AddFact("rhs", true);

    Expression expression("lhs", COP_EQUAL, "rhs");

    assert(expression.VerifyCriteria(state));
}

// Test with int
TEST(Expression, Expression_Int)
{
    StoryState state;
    state.AddFact("lhs", 123);
    state.AddFact("rhs", 123);

    Expression expression("lhs", COP_EQUAL, "rhs");

    assert(expression.VerifyCriteria(state));
}

// Test with float
TEST(Expression, Expression_Float)
{
    StoryState state;
    state.AddFact("lhs", 123.456f);
    state.AddFact("rhs", 123.456f);

    Expression expression("lhs", COP_EQUAL, "rhs");

    assert(expression.VerifyCriteria(state));
}

// Test when lhs fact is not in the state
TEST(Expression, Expression_MissingLHSFact)
{
    StoryState state;
    state.AddFact("rhs", 123);

    Expression expression("lhs", COP_EQUAL, "rhs");

    assert(!expression.VerifyCriteria(state));
}

// Test when rhs fact is not in the state
TEST(Expression, Expression_MissingRHSFact)
{
    StoryState state;
    state.AddFact("lhs", 123);

    Expression expression("lhs", COP_EQUAL, "rhs");

    assert(!expression.VerifyCriteria(state));
}

// Test when both facts are not in the state
TEST(Expression, Expression_MissingBothFacts)
{
    StoryState state;

    Expression expression("lhs", COP_EQUAL, "rhs");

    assert(!expression.VerifyCriteria(state));
}
