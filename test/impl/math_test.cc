#include "gtest/gtest.h"

#include "impl/math.h" // iharbury::intgeo::impl::gcd

namespace {

using ::iharbury::intgeo::impl::gcd;

TEST(impl_math_gcd_test, gcd_of_1_and_1_is_1) {
  EXPECT_EQ(1, gcd(1, 1));
}

TEST(impl_math_gcd_test, gcd_of_minus_1_and_1_is_1) {
  EXPECT_EQ(1, gcd(-1, 1));
}

TEST(impl_math_gcd_test, gcd_of_1_and_minus_1_is_1) {
  EXPECT_EQ(1, gcd(1, -1));
}

TEST(impl_math_gcd_test, gcd_of_1_and_0_is_1) {
  EXPECT_EQ(1, gcd(1, 0));
}

TEST(impl_math_gcd_test, gcd_of_minus_1_and_0_is_1) {
  EXPECT_EQ(1, gcd(-1, 0));
}

TEST(impl_math_gcd_test, gcd_of_0_and_1_is_1) {
  EXPECT_EQ(1, gcd(0, 1));
}

TEST(impl_math_gcd_test, gcd_of_0_and_minus_1_is_1) {
  EXPECT_EQ(1, gcd(0, -1));
}

TEST(impl_math_gcd_test, gcd_of_2_and_4_is_2) {
  EXPECT_EQ(2, gcd(2, 4));
}

TEST(impl_math_gcd_test, gcd_of_4_and_2_is_2) {
  EXPECT_EQ(2, gcd(4, 2));
}

TEST(impl_math_gcd_test, gcd_of_3_and_4_is_1) {
  EXPECT_EQ(1, gcd(3, 4));
}

TEST(impl_math_gcd_test, gcd_of_4_and_3_is_1) {
  EXPECT_EQ(1, gcd(4, 3));
}

TEST(impl_math_gcd_test, gcd_of_4_and_10_is_2) {
  EXPECT_EQ(2, gcd(4, 10));
}

TEST(impl_math_gcd_test, gcd_of_10_and_4_is_2) {
  EXPECT_EQ(2, gcd(10, 4));
}

TEST(impl_math_gcd_test, gcd_of_4_and_210_is_2) {
  EXPECT_EQ(2, gcd(4, 210));
}

} // namespace