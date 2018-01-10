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

  int32_t fraction_gcd = gcd(numerator, denominator);
  int32_t canonical_numerator =
    denominator < 0 ? -numerator / fraction_gcd : numerator / fraction_gcd;
  int32_t canonical_denominator = abs(denominator / fraction_gcd);
  return Fraction32(canonical_numerator, canonical_denominator);
}

} // namespace impl
} // namespace intgeo
} // namespace iharbury
