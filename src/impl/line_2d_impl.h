#ifndef IHARBURY_INTGEO_IMPL_LINE_2D_IMPL_H_
#define IHARBURY_INTGEO_IMPL_LINE_2D_IMPL_H_

#include <cassert> // assert
#include <cstddef> // std::size_t
#include <cstdint> // int32_t, int64_t

#include "line_2d.h" // iharbury::intgeo::Line2D
#include "impl/fraction64.h" // iharbury::intgeo::impl::Fraction64

namespace iharbury {
namespace intgeo {
namespace impl { // Internal, not part of the API.

inline Fraction64 GetSlope(const Line2D &line) {
  assert(!line.is_vertical());

  // Using int32_t to avoid overflow when subtracting 16-bit values
  // resulting in 17-bit values.
  int32_t x_difference = int32_t(line.point2().x()) -
                         int32_t(line.point1().x());
  int32_t y_difference = int32_t(line.point2().y()) -
                         int32_t(line.point1().y());

  return Fraction64::FromNonCanonical(y_difference, x_difference);
}

inline Fraction64 GetXOfXAxisCrossing(const Line2D &line) {
  assert(!line.is_horizontal());

  // Using int32_t to avoid overflow when subtracting 16-bit values
  // resulting in 17-bit values.
  int32_t x_difference = int32_t(line.point2().x()) -
                         int32_t(line.point1().x());
  int32_t y_difference = int32_t(line.point2().y()) -
                         int32_t(line.point1().y());

  return Fraction64::FromNonCanonical(
    int64_t(line.point1().x()) * int64_t(y_difference) -
      int64_t(line.point1().y()) * int64_t(x_difference),
    y_difference);
}

} // namespace impl
} // namespace intgeo
} // namespace iharbury


#endif // IHARBURY_INTGEO_IMPL_LINE_2D_IMPL_H_