#ifndef IHARBURY_INTGEO_IMPL_MATH_H_
#define IHARBURY_INTGEO_IMPL_MATH_H_

#include <cstdint> // int64_t

namespace iharbury {
namespace intgeo {
namespace impl { // Internal, not part of the API.

// Greatest common divisor.
// At least one value must be non-zero.
// If any of the values is negative, its absolute value must fit into int64_t.
int64_t gcd(int64_t, int64_t);

} // namespace impl
} // namespace intgeo
} // namespace iharbury

#endif // IHARBURY_INTGEO_IMPL_MATH_H_
