#include "fraction32.h"

#include <cstdlib>

namespace iharbury {
namespace intgeo {
namespace impl { // Internal, not part of the API.

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
