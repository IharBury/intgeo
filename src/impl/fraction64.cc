#include "impl/fraction64.h"

#include <cassert> // assert
#include <cstdlib> // std::abs
#include <cstdint> // int64_t, INT64_MIN

#include "impl/math.h" // iharbury::intgeo::impl::gcd

namespace iharbury {
namespace intgeo {
namespace impl { // Internal, not part of the API.

using ::std::abs;

Fraction64 Fraction64::FromNonCanonical(int64_t numerator,
                                        int64_t denominator) {
  assert(numerator != INT64_MIN);
  assert(denominator != 0);
  assert(denominator != INT64_MIN);

  int64_t fraction_gcd = gcd(numerator, denominator);
  int64_t canonical_numerator =
    denominator < 0 ? -numerator / fraction_gcd : numerator / fraction_gcd;
  int64_t canonical_denominator = abs(denominator / fraction_gcd);
  return Fraction64(canonical_numerator, canonical_denominator);
}

} // namespace impl
} // namespace intgeo
} // namespace iharbury
