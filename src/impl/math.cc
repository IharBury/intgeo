#include "math.h"

#include <cassert>
#include <cstdlib>

namespace iharbury {
namespace intgeo {
namespace impl { // Internal, not part of the API.

// Euclidian algorithm.
int32_t gcd(const int32_t value1, const int32_t value2) {
  assert((value1 != 0) || (value2 != 0));
  assert(value1 != INT32_MIN);
  assert(value2 != INT32_MIN);

  int32_t dividend = abs(value1);
  int32_t divisor = abs(value2);

  while (divisor != 0) {
    int32_t mod = dividend % divisor;
    dividend = divisor;
    divisor = mod;
  }

  return dividend;
}

} // namespace impl
} // namespace intgeo
} // namespace iharbury
