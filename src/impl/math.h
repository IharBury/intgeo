#ifndef IHARBURY_INTGEO_IMPL_MATH_H_
#define IHARBURY_INTGEO_IMPL_MATH_H_

#include <cstdint> // int32_t

namespace iharbury {
namespace intgeo {
namespace impl { // Internal, not part of the API.

// Greatest common divisor.
// At least one value must be non-zero.
// If any of the values is negative, its absolute value must fit into int32_t.
int32_t gcd(int32_t, int32_t);

} // namespace impl
} // namespace intgeo
} // namespace iharbury

#endif // IHARBURY_INTGEO_IMPL_MATH_H_
