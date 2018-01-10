#ifndef IHARBURY_INTGEO_IMPL_FRACTION32_H_
#define IHARBURY_INTGEO_IMPL_FRACTION32_H_

#include <cassert> // assert
#include <cstddef> // std::site_t
#include <cstdint> // int32_t, INT32_MIN

#include "impl/math.h" // iharbury::intgeo::impl::gcd

namespace iharbury {
namespace intgeo {
namespace impl { // Internal, not part of the API.

// A fraction in its canonical representation
// with 32-bit coprime numerator and denominator
// where the denominator is positive.
class Fraction32 final {
 public:
  class Hasher;

  // Creates the fraction from the numerator and the denominator
  // of one of the representations of the fraction
  // which does not have to be canonical.
  // The numerator and the denominator do not have to be coprime.
  // The denominator can be negative but cannot be zero.
  // If any of the values is negative, its absolute value must fit into int32_t.
  static Fraction32 FromNonCanonical(int32_t numerator, int32_t denominator);

  inline Fraction32(int32_t numerator, int32_t denominator) :
      numerator_(numerator), denominator_(denominator) {
    assert(numerator != INT32_MIN);
    assert(denominator > 0);
    assert(gcd(numerator, denominator) == 1);
  }

  inline int32_t numerator() const { return numerator_; }
  inline int32_t denominator() const { return denominator_; }

 private:
  int32_t numerator_;
  int32_t denominator_;
};

class Fraction32::Hasher final {
 public:
  inline std::size_t operator()(const Fraction32 &fraction) const {
    return std::size_t(fraction.numerator()) * std::size_t(37987) +
      std::size_t(fraction.denominator());
  }
};

inline bool operator==(const Fraction32 &fraction1,
                       const Fraction32 &fraction2) {
  return (fraction1.numerator() == fraction2.numerator()) &&
    (fraction1.denominator() == fraction2.denominator());
}

inline bool operator!=(const Fraction32 &fraction1,
                       const Fraction32 &fraction2) {
  return !(fraction1 == fraction2);
}

} // namespace impl
} // namespace intgeo
} // namespace iharbury

#endif // IHARBURY_INTGEO_IMPL_FRACTION32_H_
