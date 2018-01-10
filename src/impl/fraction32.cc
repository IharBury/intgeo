#include "fraction32.h"

#include <cassert> // assert
#include <cstdlib> // std::abs
#include <cstdint> // int32_t, INT32_MIN

#include "impl/math.h" // iharbury::intgeo::impl::gcd

namespace iharbury {
namespace intgeo {
namespace impl { // Internal, not part of the API.

using ::std::abs;

Fraction32 Fraction32::FromNonCanonical(int32_t numerator, int32_t denominator) {
  assert(numerator != INT32_MIN);
  assert(denominator != 0);
  assert(denominator != INT32_MIN);

  int32_t fractionGcd = gcd(numerator, denominator);
  int32_t canonicalNumerator =
    denominator < 0 ? -numerator / fractionGcd : numerator / fractionGcd;
  int32_t canonicalDenominator = abs(denominator / fractionGcd);
  return Fraction32(canonicalNumerator, canonicalDenominator);
}

} // namespace impl
} // namespace intgeo
} // namespace iharbury
