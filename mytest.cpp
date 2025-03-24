#include <gtest/gtest.h>

#include "Calculator.h"

class CalculatorTest : public ::testing::Test
{
protected:
    Calculator calc;
    void SetUp() override
    {
        this->calc = Calculator(); // Fixed initialization
    }
};

// Test case name, TestName
TEST_F(CalculatorTest, TestAddMethod)
{
    EXPECT_EQ(5, calc.add(2, 3));
    EXPECT_EQ(1, calc.add(-2, 3));
    EXPECT_EQ(-1, calc.add(2, -3));
    EXPECT_EQ(-5, calc.add(-2, -3));
}

TEST_F(CalculatorTest, DISABLED_TestFactorielleMethod) // Enabled test
{
    EXPECT_EQ(1*2, calc.factorielle(2));
    EXPECT_EQ(1*2*3, calc.factorielle(3));
    EXPECT_EQ(1*2*3*4, calc.factorielle(4));
    EXPECT_EQ(1*2*3*4*5, calc.factorielle(5));
}

TEST_F(CalculatorTest, TestSubMethod)
{
    EXPECT_EQ(-1, calc.sub(2, 3));
    EXPECT_EQ(-5, calc.sub(-2, 3));
    EXPECT_EQ(5, calc.sub(2, -3));
    EXPECT_EQ(1, calc.sub(-2, -3));
}

TEST_F(CalculatorTest, TestDivMethod) // Enabled test
{
    EXPECT_DOUBLE_EQ(2./3., calc.div(2, 3));
    EXPECT_DOUBLE_EQ(-2./3., calc.div(-2, 3));
    EXPECT_DOUBLE_EQ(2./(-3.), calc.div(2, -3));
    EXPECT_DOUBLE_EQ(2./3., calc.div(-2, -3));
    EXPECT_DOUBLE_EQ(2./3., calc.div(-2, -3));
    EXPECT_NEAR(2.333, calc.div(7, 3), 0.001);
    EXPECT_ANY_THROW(calc.div(7, 0));
    // ASSERT_EXIT(calc.div(7, 0), ::testing::ExitedWithCode(255), "Error: Division by 0 not possible");
}