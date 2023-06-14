#include <iostream>

#include "gtest/gtest.h"
#include "dialogue_driver/driver.h"
#include "dialogue_driver/fact.h"

TEST(Facts, Fact_Construction) {
    Fact f = Fact();
    EXPECT_ANY_THROW(f.Get<int>());

    ASSERT_FALSE(f == 0);
    // ASSERT_FALSE(f == 1);
    // ASSERT_FALSE(f == "Hi!");
}

TEST(Facts, Fact_Float)
{
    Fact floatFact = Fact(1.0f);
    assert(floatFact.Get<float>() == 1.0f);

    assert(floatFact == 1.0f);
    assert(floatFact != 2.0f);

    Fact floatFactDup = Fact(1.0f);
    assert(floatFact == floatFactDup);

    Fact floatFactDif = Fact(2.0f);
    ASSERT_FALSE(floatFact == floatFactDif);
    // assert(floatFact != "Hi!");
}

TEST(Facts, Fact_String)
{
    std::string str = "Hi!";
    Fact stringFact = Fact(str);
    assert(stringFact.Get<std::string>() == "Hi!");

    assert(stringFact == str);
}

TEST(Facts, Fact_Static)
{

}
