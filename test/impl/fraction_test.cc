#include "gtest/gtest.h"

#include "impl/fraction32.h"

namespace {

using ::iharbury::intgeo::impl::Fraction32;

TEST(impl_fraction_test, a_fraction_can_be_initialized_to_the_given_canonical_numerator_and_denominator) {
  Fraction32 fraction(4, 9);
  EXPECT_EQ(4, fraction.numerator());
  EXPECT_EQ(9, fraction.denominator());
}

TEST(impl_fraction_test, a_negative_fraction_can_be_initialized_to_the_given_canonical_numerator_and_denominator) {
  Fraction32 fraction(-4, 9);
  EXPECT_EQ(-4, fraction.numerator());
  EXPECT_EQ(9, fraction.denominator());
}

TEST(impl_fraction_test, the_zero_fraction_can_be_initialized_to_its_canonical_representation) {
  Fraction32 fraction(0, 1);
  EXPECT_EQ(0, fraction.numerator());
  EXPECT_EQ(1, fraction.denominator());
}

TEST(impl_fraction_test, a_fraction_can_be_copied) {
  Fraction32 fraction(4, 9), copy(fraction);
  EXPECT_EQ(4, copy.numerator());
  EXPECT_EQ(9, copy.denominator());
}

TEST(impl_fraction_test, a_fraction_can_be_assigned) {
  Fraction32 fraction(4, 9), assigned(1, 1);
  assigned = fraction;
  EXPECT_EQ(4, assigned.numerator());
  EXPECT_EQ(9, assigned.denominator());
}

TEST(impl_fraction_test, a_fraction_can_be_created_from_its_non_canonical_representation) {
  Fraction32 fraction = Fraction32::FromNonCanonical(4, 10);
  EXPECT_EQ(2, fraction.numerator());
  EXPECT_EQ(5, fraction.denominator());
}

TEST(impl_fraction_test, a_negative_fraction_can_be_created_from_its_non_canonical_representation) {
  Fraction32 fraction = Fraction32::FromNonCanonical(-4, 10);
  EXPECT_EQ(-2, fraction.numerator());
  EXPECT_EQ(5, fraction.denominator());
}

TEST(impl_fraction_test, a_negative_fraction_can_be_created_from_its_non_canonical_representation_with_negative_denominator) {
  Fraction32 fraction = Fraction32::FromNonCanonical(4, -10);
  EXPECT_EQ(-2, fraction.numerator());
  EXPECT_EQ(5, fraction.denominator());
}

TEST(impl_fraction_test, the_zero_fraction_can_be_created_from_its_non_canonical_representation) {
  Fraction32 fraction = Fraction32::FromNonCanonical(0, 10);
  EXPECT_EQ(0, fraction.numerator());
  EXPECT_EQ(1, fraction.denominator());
}

TEST(impl_fraction_test, the_zero_fraction_can_be_created_from_its_non_canonical_representation_with_negative_denominator) {
  Fraction32 fraction = Fraction32::FromNonCanonical(0, -10);
  EXPECT_EQ(0, fraction.numerator());
  EXPECT_EQ(1, fraction.denominator());
}

TEST(impl_fraction_test, fractions_are_equal_when_both_their_numerators_and_denominators_match) {
  EXPECT_TRUE(Fraction32(4, 9) == Fraction32(4, 9));
}

TEST(impl_fraction_test, fractions_are_not_equal_when_their_numerators_do_not_match) {
  EXPECT_FALSE(Fraction32(4, 9) == Fraction32(5, 9));
}

TEST(impl_fraction_test, fractions_are_not_equal_when_their_denominators_do_not_match) {
  EXPECT_FALSE(Fraction32(4, 9) == Fraction32(4, 7));
}

TEST(impl_fraction_test, fractions_are_not_inequal_when_both_their_numerators_and_denominators_match) {
  EXPECT_FALSE(Fraction32(4, 9) != Fraction32(4, 9));
}

TEST(impl_fraction_test, fractions_are_inequal_when_their_numerators_do_not_match) {
  EXPECT_TRUE(Fraction32(4, 9) != Fraction32(5, 9));
}

TEST(impl_fraction_test, fractions_are_inequal_when_their_denominators_do_not_match) {
  EXPECT_TRUE(Fraction32(4, 9) != Fraction32(4, 7));
}

TEST(impl_fraction_test, fractions_have_the_same_hash_when_both_their_numerators_and_denominators_match) {
  Fraction32::Hasher hasher;
  EXPECT_EQ(hasher(Fraction32(4, 9)), hasher(Fraction32(4, 9)));
}

} // namespace