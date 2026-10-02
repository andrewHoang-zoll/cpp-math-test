#include <gtest/gtest.h>
#include "../cpp-math-class/Math.h"
#include <cmath>

const double TOLERANCE = 1e-6;

// Basic Arithmetic Tests
class ArithmeticTest : public ::testing::Test {};

TEST_F(ArithmeticTest, Addition) {
    EXPECT_DOUBLE_EQ(Math::add(2.0, 3.0), 5.0);
    EXPECT_DOUBLE_EQ(Math::add(-2.0, 3.0), 1.0);
    EXPECT_DOUBLE_EQ(Math::add(0.0, 0.0), 0.0);
    EXPECT_DOUBLE_EQ(Math::add(-5.5, 5.5), 0.0);
}

TEST_F(ArithmeticTest, Subtraction) {
    EXPECT_DOUBLE_EQ(Math::subtract(5.0, 3.0), 2.0);
    EXPECT_DOUBLE_EQ(Math::subtract(3.0, 5.0), -2.0);
    EXPECT_DOUBLE_EQ(Math::subtract(0.0, 0.0), 0.0);
    EXPECT_DOUBLE_EQ(Math::subtract(-5.0, -3.0), -2.0);
}

TEST_F(ArithmeticTest, Multiplication) {
    EXPECT_DOUBLE_EQ(Math::multiply(2.0, 3.0), 6.0);
    EXPECT_DOUBLE_EQ(Math::multiply(-2.0, 3.0), -6.0);
    EXPECT_DOUBLE_EQ(Math::multiply(0.0, 100.0), 0.0);
    EXPECT_DOUBLE_EQ(Math::multiply(-2.0, -3.0), 6.0);
}

TEST_F(ArithmeticTest, Division) {
    EXPECT_DOUBLE_EQ(Math::divide(6.0, 2.0), 3.0);
    EXPECT_DOUBLE_EQ(Math::divide(5.0, 2.0), 2.5);
    EXPECT_DOUBLE_EQ(Math::divide(-6.0, 2.0), -3.0);
}

TEST_F(ArithmeticTest, DivisionByZero) {
    EXPECT_THROW(Math::divide(5.0, 0.0), std::invalid_argument);
}

TEST_F(ArithmeticTest, Modulo) {
    EXPECT_EQ(Math::modulo(10, 3), 1);
    EXPECT_EQ(Math::modulo(10, 5), 0);
    EXPECT_EQ(Math::modulo(7, 2), 1);
}

TEST_F(ArithmeticTest, ModuloByZero) {
    EXPECT_THROW(Math::modulo(5, 0), std::invalid_argument);
}

// Power and Root Tests
class PowerAndRootTest : public ::testing::Test {};

TEST_F(PowerAndRootTest, Power) {
    EXPECT_NEAR(Math::power(2.0, 3.0), 8.0, TOLERANCE);
    EXPECT_NEAR(Math::power(5.0, 2.0), 25.0, TOLERANCE);
    EXPECT_NEAR(Math::power(2.0, 0.0), 1.0, TOLERANCE);
    EXPECT_NEAR(Math::power(10.0, -1.0), 0.1, TOLERANCE);
}

TEST_F(PowerAndRootTest, SquareRoot) {
    EXPECT_NEAR(Math::squareRoot(4.0), 2.0, TOLERANCE);
    EXPECT_NEAR(Math::squareRoot(9.0), 3.0, TOLERANCE);
    EXPECT_NEAR(Math::squareRoot(2.0), std::sqrt(2.0), TOLERANCE);
}

TEST_F(PowerAndRootTest, SquareRootNegative) {
    EXPECT_THROW(Math::squareRoot(-1.0), std::invalid_argument);
}

TEST_F(PowerAndRootTest, CubeRoot) {
    EXPECT_NEAR(Math::cubeRoot(8.0), 2.0, TOLERANCE);
    EXPECT_NEAR(Math::cubeRoot(27.0), 3.0, TOLERANCE);
    EXPECT_NEAR(Math::cubeRoot(-8.0), -2.0, TOLERANCE);
}

// Trigonometric Tests
class TrigonometricTest : public ::testing::Test {};

TEST_F(TrigonometricTest, Sine) {
    EXPECT_NEAR(Math::sine(0.0), 0.0, TOLERANCE);
    EXPECT_NEAR(Math::sine(M_PI / 6), 0.5, TOLERANCE);
    EXPECT_NEAR(Math::sine(M_PI / 2), 1.0, TOLERANCE);
}

TEST_F(TrigonometricTest, Cosine) {
    EXPECT_NEAR(Math::cosine(0.0), 1.0, TOLERANCE);
    EXPECT_NEAR(Math::cosine(M_PI / 3), 0.5, TOLERANCE);
    EXPECT_NEAR(Math::cosine(M_PI), -1.0, TOLERANCE);
}

TEST_F(TrigonometricTest, Tangent) {
    EXPECT_NEAR(Math::tangent(0.0), 0.0, TOLERANCE);
    EXPECT_NEAR(Math::tangent(M_PI / 4), 1.0, TOLERANCE);
}

// Utility Tests
class UtilityTest : public ::testing::Test {};

TEST_F(UtilityTest, Absolute) {
    EXPECT_DOUBLE_EQ(Math::absolute(5.0), 5.0);
    EXPECT_DOUBLE_EQ(Math::absolute(-5.0), 5.0);
    EXPECT_DOUBLE_EQ(Math::absolute(0.0), 0.0);
}

TEST_F(UtilityTest, Factorial) {
    EXPECT_EQ(Math::factorial(0), 1);
    EXPECT_EQ(Math::factorial(1), 1);
    EXPECT_EQ(Math::factorial(5), 120);
    EXPECT_EQ(Math::factorial(10), 3628800);
}

TEST_F(UtilityTest, FactorialNegative) {
    EXPECT_THROW(Math::factorial(-1), std::invalid_argument);
}

TEST_F(UtilityTest, Average) {
    double values1[] = {1.0, 2.0, 3.0};
    EXPECT_NEAR(Math::average(values1, 3), 2.0, TOLERANCE);
    
    double values2[] = {10.0, 20.0, 30.0, 40.0};
    EXPECT_NEAR(Math::average(values2, 4), 25.0, TOLERANCE);
}

TEST_F(UtilityTest, AverageInvalidCount) {
    double values[] = {1.0, 2.0};
    EXPECT_THROW(Math::average(values, 0), std::invalid_argument);
    EXPECT_THROW(Math::average(values, -1), std::invalid_argument);
}

TEST_F(UtilityTest, Maximum) {
    double values1[] = {1.0, 5.0, 3.0};
    EXPECT_DOUBLE_EQ(Math::maximum(values1, 3), 5.0);
    
    double values2[] = {-10.0, -5.0, -20.0};
    EXPECT_DOUBLE_EQ(Math::maximum(values2, 3), -5.0);
}

TEST_F(UtilityTest, MaximumInvalidCount) {
    double values[] = {1.0, 2.0};
    EXPECT_THROW(Math::maximum(values, 0), std::invalid_argument);
}

TEST_F(UtilityTest, Minimum) {
    double values1[] = {1.0, 5.0, 3.0};
    EXPECT_DOUBLE_EQ(Math::minimum(values1, 3), 1.0);
    
    double values2[] = {-10.0, -5.0, -20.0};
    EXPECT_DOUBLE_EQ(Math::minimum(values2, 3), -20.0);
}

TEST_F(UtilityTest, MinimumInvalidCount) {
    double values[] = {1.0, 2.0};
    EXPECT_THROW(Math::minimum(values, 0), std::invalid_argument);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
