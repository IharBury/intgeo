// Copyright 2018 Ihar Bury

#include "src/impl/math.h"

#include <cassert>  // assert
#include <cstdlib>  // int64_t, INT64_MIN, std::abs

namespace iharbury {
namespace intgeo {
namespace impl {  // Internal, not part of the API.

using ::std::abs;

// Euclidian algorithm.
int64_t gcd(const int64_t value1, const int64_t value2) {
  assert((value1 != 0) || (value2 != 0));
  assert(value1 != INT64_MIN);
  assert(value2 != INT64_MIN);

  int64_t dividend = abs(value1);
  int64_t divisor = abs(value2);

  while (divisor != 0) {
    int64_t mod = dividend % divisor;
    dividend = divisor;
    divisor = mod;
  }

  return dividend;
}

}  // namespace impl
}  // namespace intgeo
}  // namespace iharbury
