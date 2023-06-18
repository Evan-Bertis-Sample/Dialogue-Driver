#include <iostream>

#include "gtest/gtest.h"
#include "dialogue_driver/driver.h"
#include "dialogue_driver/fact.h"

// Fact Constructor Tests
TEST(Facts, Fact_Construction)
{
    Fact intFact(5);
    ASSERT_EQ(intFact.Get<int>(), 5);

    Fact floatFact(3.14f);
    ASSERT_FLOAT_EQ(floatFact.Get<float>(), 3.14f);

    Fact stringFact("Hello");
    ASSERT_EQ(stringFact.Get<std::string>(), "Hello");

    Fact boolFact(true);
    ASSERT_TRUE(boolFact.Get<bool>());

    Fact copyFact(intFact);
    ASSERT_EQ(copyFact.Get<int>(), 5);

    Fact nullFact;
    EXPECT_ANY_THROW(nullFact.Get<int>());
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

// Fact Comparisons Across Types
TEST(Facts, Fact_Comparison_Across_Types)
{
    Fact intFact(5);
    Fact floatFact(5.0f);
    Fact floatFact2(5.5f);
    Fact stringFact("5");
    Fact boolFact(true);

    ASSERT_TRUE(intFact == floatFact);
    ASSERT_FALSE(intFact == floatFact2);
    ASSERT_FALSE(intFact == stringFact);
    ASSERT_FALSE(intFact == boolFact);
}

// Fact Invalid Comparisons
TEST(Facts, Fact_Invalid_Comparisons)
{
    Fact intFact(5);
    Fact stringFact("Hello");
    Fact nullFact;

    ASSERT_FALSE(intFact == stringFact);
    ASSERT_FALSE(intFact < stringFact);
    ASSERT_FALSE(intFact > stringFact);
    ASSERT_FALSE(intFact <= stringFact);
    ASSERT_FALSE(intFact >= stringFact);

    ASSERT_FALSE(intFact == nullFact);
    ASSERT_FALSE(intFact < nullFact);
    ASSERT_FALSE(intFact > nullFact);
    ASSERT_FALSE(intFact <= nullFact);
    ASSERT_FALSE(intFact >= nullFact);
}

// Fact Copy Constructor Tests
TEST(Facts, Fact_Copy_Constructor)
{
    Fact originalIntFact(5);
    Fact copiedIntFact(originalIntFact);

    ASSERT_EQ(originalIntFact.Get<int>(), copiedIntFact.Get<int>());

    Fact originalStringFact("Hello");
    Fact copiedStringFact(originalStringFact);

    ASSERT_EQ(originalStringFact.Get<std::string>(), copiedStringFact.Get<std::string>());
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
    ASSERT_TRUE(intFact == 20);

    Fact floatFact = Fact();
    floatFact.Set(20.0f);
    ASSERT_TRUE(floatFact.Get<float>() == 20.0f);

    Fact stringFact = Fact();
    stringFact.Set(std::string("New String"));
    ASSERT_TRUE(stringFact.Get<std::string>() == "New String");
}

// Fact Bad Variant Access Test
TEST(Facts, Fact_Bad_Variant_Access)
{
    Fact intFact = Fact(5);
    ASSERT_THROW(intFact.Get<float>(), std::bad_variant_access);
}

// Fact Comparisons with different integer and floating point values
TEST(Facts, Fact_Complex_Comparison_Int_Float)
{
    Fact intFact1(5);
    Fact floatFact1(5.0f);
    Fact floatFact2(5.5f);

    ASSERT_TRUE(intFact1 == floatFact1);
    ASSERT_FALSE(intFact1 == floatFact2);
    ASSERT_TRUE(intFact1 < floatFact2);
    ASSERT_FALSE(intFact1 > floatFact2);
    ASSERT_TRUE(intFact1 <= floatFact2);
    ASSERT_FALSE(intFact1 >= floatFact2);
}

// Fact Comparisons with different integer values
TEST(Facts, Fact_Complex_Comparison_Int)
{
    Fact intFact1(5);
    Fact intFact2(7);
    Fact intFact3(5);

    ASSERT_FALSE(intFact1 == intFact2);
    ASSERT_TRUE(intFact1 == intFact3);
    ASSERT_TRUE(intFact1 < intFact2);
    ASSERT_FALSE(intFact1 > intFact2);
    ASSERT_TRUE(intFact1 <= intFact2);
    ASSERT_FALSE(intFact1 >= intFact2);
}

// Fact Comparisons with different boolean values
TEST(Facts, Fact_Complex_Comparison_Bool)
{
    Fact boolFact1(true);
    Fact boolFact2(false);
    Fact boolFact3(true);

    ASSERT_FALSE(boolFact1 == boolFact2);
    ASSERT_TRUE(boolFact1 == boolFact3);
    ASSERT_FALSE(boolFact1 < boolFact2);
    ASSERT_TRUE(boolFact1 > boolFact2);
    ASSERT_FALSE(boolFact1 <= boolFact2);
    ASSERT_TRUE(boolFact1 >= boolFact2);
}

// Fact Comparisons with different string values
TEST(Facts, Fact_Complex_Comparison_String)
{
    Fact stringFact1("apple");
    Fact stringFact2("banana");
    Fact stringFact3("apple");

    ASSERT_FALSE(stringFact1 == stringFact2);
    ASSERT_TRUE(stringFact1 == stringFact3);
    ASSERT_TRUE(stringFact1 < stringFact2);
    ASSERT_FALSE(stringFact1 > stringFact2);
    ASSERT_TRUE(stringFact1 <= stringFact2);
    ASSERT_FALSE(stringFact1 >= stringFact2);
}

// Fact Comparisons with integer constants
TEST(Facts, Fact_Comparison_With_Integer_Constants)
{
    Fact intFact(10);

    ASSERT_TRUE(intFact == 10);
    ASSERT_FALSE(intFact == 20);
    ASSERT_TRUE(intFact < 20);
    ASSERT_FALSE(intFact > 20);
    ASSERT_TRUE(intFact <= 10);
    ASSERT_FALSE(intFact < 10);
    ASSERT_TRUE(intFact >= 10);
    ASSERT_FALSE(intFact > 10);
}

// Fact Comparisons with float constants
TEST(Facts, Fact_Comparison_With_Float_Constants)
{
    Fact floatFact(10.5f);

    ASSERT_TRUE(floatFact == 10.5f);
    ASSERT_FALSE(floatFact == 20.5f);
    ASSERT_TRUE(floatFact < 20.5f);
    ASSERT_FALSE(floatFact > 20.5f);
    ASSERT_TRUE(floatFact <= 10.5f);
    ASSERT_FALSE(floatFact < 10.5f);
    ASSERT_TRUE(floatFact >= 10.5f);
    ASSERT_FALSE(floatFact > 10.5f);
}

// Fact Comparisons with boolean constants
TEST(Facts, Fact_Comparison_With_Boolean_Constants)
{
    Fact boolFact(true);

    ASSERT_TRUE(boolFact == true);
    ASSERT_FALSE(boolFact == false);
}

// Fact Comparisons with string constants
TEST(Facts, Fact_Comparison_With_String_Constants)
{
    Fact stringFact("Hello, world!");

    ASSERT_TRUE(stringFact == std::string("Hello, world!"));
    ASSERT_FALSE(stringFact == std::string("Goodbye, world!"));
}

// Fact Comparisons with mismatching integer constants
TEST(Facts, Fact_Comparison_With_Mismatching_Integer_Constants)
{
    Fact floatFact(10.5f);

    ASSERT_FALSE(floatFact == 10);
    ASSERT_FALSE(floatFact != 10);
    ASSERT_FALSE(floatFact < 10);
    ASSERT_FALSE(floatFact > 10);
    ASSERT_FALSE(floatFact <= 10);
    ASSERT_FALSE(floatFact >= 10);
}

// Fact Comparisons with mismatching float constants
TEST(Facts, Fact_Comparison_With_Mismatching_Float_Constants)
{
    Fact intFact(10);

    ASSERT_FALSE(intFact == 10.5f);
    ASSERT_FALSE(intFact != 10.5f);
    ASSERT_FALSE(intFact < 10.5f);
    ASSERT_FALSE(intFact > 10.5f);
    ASSERT_FALSE(intFact <= 10.5f);
    ASSERT_FALSE(intFact >= 10.5f);
}

// Fact Comparisons with mismatching boolean constants
TEST(Facts, Fact_Comparison_With_Mismatching_Boolean_Constants)
{
    Fact intFact(1);

    ASSERT_FALSE(intFact == true);
    ASSERT_FALSE(intFact != true);
}

// Fact Comparisons with mismatching string constants
TEST(Facts, Fact_Comparison_With_Mismatching_String_Constants)
{
    Fact intFact(1234);

    ASSERT_FALSE(intFact == std::string("1234"));
    ASSERT_FALSE(intFact != std::string("1234"));
}

