#include "gtest/gtest.h"
#include "dialogue_driver/driver.h"
#include "dialogue_driver/fact.h"

TEST(TestDriver, DoSomething) {
    assert(true);
    Fact f = Fact();
    assert(f.VerifyType(INT));
    assert(f.GetFloat() == 0);

    assert(Fact::GetFactType(1) == INT);
    assert(Fact::GetFactType(1.0f) == FLOAT);
    assert(Fact::GetFactType(true) == BOOL);
    assert(Fact::GetFactType("Hola!") == STRING);
}
