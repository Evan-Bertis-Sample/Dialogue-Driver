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

    Fact intFact = Fact(1);
    assert(floatFact == intFact);
    assert(intFact == floatFact);
}

TEST(Facts, Fact_String)
{
    std::string str = "Hi!";
    Fact stringFact = Fact(str);
    assert(stringFact.Get<std::string>() == "Hi!");

    assert(stringFact == str);
}

// Fact Comparison Operators Tests
TEST(Facts, Fact_Comparison_Operators)
{
    Fact intFact1 = Fact(5);
    Fact intFact2 = Fact(10);
    Fact floatFact1 = Fact(5.0f);
    Fact floatFact2 = Fact(10.0f);
    Fact stringFact1 = Fact("Hello");
    Fact stringFact2 = Fact("World");

    // Test with integer Facts
    ASSERT_FALSE(intFact1 > intFact2);
    ASSERT_TRUE(intFact2 > intFact1);
    ASSERT_TRUE(intFact1 < intFact2);
    ASSERT_FALSE(intFact2 < intFact1);
    ASSERT_TRUE(intFact1 <= intFact2);
    ASSERT_FALSE(intFact2 <= intFact1);
    ASSERT_FALSE(intFact1 >= intFact2);
    ASSERT_TRUE(intFact2 >= intFact1);

    // Test with float Facts
    ASSERT_FALSE(floatFact1 > floatFact2);
    ASSERT_TRUE(floatFact2 > floatFact1);
    ASSERT_TRUE(floatFact1 < floatFact2);
    ASSERT_FALSE(floatFact2 < floatFact1);
    ASSERT_TRUE(floatFact1 <= floatFact2);
    ASSERT_FALSE(floatFact2 <= floatFact1);
    ASSERT_FALSE(floatFact1 >= floatFact2);
    ASSERT_TRUE(floatFact2 >= floatFact1);

    // Test between int and float Facts
    ASSERT_TRUE(intFact1 == floatFact1);
    ASSERT_FALSE(intFact1 != floatFact1);

    // Test with string Facts
    ASSERT_TRUE(stringFact1 < stringFact2);
    ASSERT_FALSE(stringFact1 > stringFact2);
}

// Fact Assignment and Get Methods Tests
TEST(Facts, Fact_Assignment_and_Get_Methods)
{
    Fact intFact = Fact();
    intFact.Set(20);
    ASSERT_TRUE(intFact.Get<int>() == 20);

    // Fact floatFact = Fact();
    // floatFact.Set(20.0f);
    // ASSERT_TRUE(floatFact.Get<float>() == 20.0f);

    // Fact stringFact = Fact();
    // stringFact.Set(std::string("New String"));
    // ASSERT_TRUE(stringFact.Get<std::string>() == "New String");
}

// Fact Bad Variant Access Test
TEST(Facts, Fact_Bad_Variant_Access)
{
    Fact intFact = Fact(5);
    ASSERT_THROW(intFact.Get<float>(), std::bad_variant_access);
}

