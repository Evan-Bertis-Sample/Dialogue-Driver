#include "gtest/gtest.h"
#include "dialogue_driver/driver.h"
#include "dialogue_driver/fact.h"

TEST(TestDriver, DoSomething) {
    assert(Fact::GetFactType(1) == INT);
    assert(Fact::GetFactType(1.0f) == FLOAT);
    assert(Fact::GetFactType(true) == BOOL);
    assert(Fact::GetFactType("Hola!") == STRING);
}
