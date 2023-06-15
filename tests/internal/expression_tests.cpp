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