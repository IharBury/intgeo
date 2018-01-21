#ifndef IHARBURY_INTGEO_IMPL_FRACTION64_H_
#define IHARBURY_INTGEO_IMPL_FRACTION64_H_

#include <cassert> // assert
#include <cstddef> // std::site_t
#include <cstdint> // int64_t, INT64_MIN
#include <functional> // std::hash

#include "impl/math.h" // iharbury::intgeo::impl::gcd

namespace iharbury {
namespace intgeo {
namespace impl { // Internal, not part of the API.

// A fraction in its canonical representation
// with 64-bit coprime numerator and denominator
// where the denominator is positive.
class Fraction64 final {
 public:
  class Hasher;

  // Creates the fraction from the numerator and the denominator
  // of one of the representations of the fraction
  // which does not have to be canonical.
  // The numerator and the denominator do not have to be coprime.
  // The denominator can be negative but cannot be zero.
  // If any of the values is negative, its absolute value must fit into int64_t.
  static Fraction64 FromNonCanonical(int64_t numerator, int64_t denominator);

  inline Fraction64(int64_t numerator, int64_t denominator) :
      numerator_(numerator), denominator_(denominator) {
    assert(numerator != INT64_MIN);
    assert(denominator > 0);
    assert(gcd(numerator, denominator) == 1);
  }

  inline int64_t numerator() const { return numerator_; }
  inline int64_t denominator() const { return denominator_; }

 private:
  int64_t numerator_;
  int64_t denominator_;
};

class Fraction64::Hasher final {
 public:
  inline std::size_t operator()(const Fraction64 &fraction) const {
    std::hash<int64_t> int64_hasher{};
    return int64_hasher(fraction.numerator()) * std::size_t(37987) +
      int64_hasher(fraction.denominator());
  }
};

inline bool operator==(const Fraction64 &fraction1,
                       const Fraction64 &fraction2) {
  return (fraction1.numerator() == fraction2.numerator()) &&
    (fraction1.denominator() == fraction2.denominator());
}

inline bool operator!=(const Fraction64 &fraction1,
                       const Fraction64 &fraction2) {
  return !(fraction1 == fraction2);
}

} // namespace impl
} // namespace intgeo
} // namespace iharbury

#endif // IHARBURY_INTGEO_IMPL_FRACTION64_H_
