#include <iostream>

#include "gtest/gtest.h"
#include "dialogue_driver/driver.h"
#include "dialogue_driver/fact.h"

TEST(TestDriver, DoSomething) {
    std::cout << "Running Internal Tests..." << std::endl;
    Fact f = Fact();
    assert(f.VerifyType(INT));
    assert(f.GetFloat() == 0);

    Fact floatFace = Fact(1.0f);
    assert(f.VerifyType(FLOAT));
    assert(f.GetFloat() == 1.0f);


    // assert(Fact::GetFactType(1) == INT);
    // assert(Fact::GetFactType(1.0f) == FLOAT);
    // assert(Fact::GetFactType(true) == BOOL);
    // assert(Fact::GetFactType("Hola!") == STRING);
}
