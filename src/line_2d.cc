#include "line_2d.h"

#include <cstddef> // std::size_t
#include <cstdint> // int32_t, int64_t
#include <functional> // std::hash

#include "point_2d.h" // iharbury::intgeo::Point2D
#include "impl/fraction64.h" // iharbury::intgeo::impl::Fraction64
#include "impl/line_2d_impl.h" // iharbury::intgeo::impl::GetXOfXAxisCrossing,
                               // iharbury::intgeo::impl::GetSlope

namespace iharbury {
namespace intgeo {

using ::std::hash;
using ::std::size_t;
using ::iharbury::intgeo::impl::Fraction64;
using ::iharbury::intgeo::impl::GetSlope;
using ::iharbury::intgeo::impl::GetXOfXAxisCrossing;

bool Line2D::HasPoint(const Point2D &point) const {
  // Ignoring the case when the point is equal
  // to either the point1 or the point2,
  // the point lies on the line defined by the point1 and the point2,
  // iff the line defined by the point and the point1 has the same slope
  // as the line defined by the point and the point2.
  // To avoid division (which is slower than multiplication)
  // and especially division by zero for vertical lines,
  // we rewrite the slope equality equation using multiplication.
  // That also takes care of the case when the point is equal
  // to either the point1 or the point2.
  // Both sides of the equation become zero in that case.

  // Using int32_t to avoid overflow when subtracting 16-bit values
  // resulting in 17-bit values.
  int32_t x_difference1 = int32_t(point.x()) - int32_t(point1_.x());
  int32_t y_difference1 = int32_t(point.y()) - int32_t(point1_.y());
  int32_t x_difference2 = int32_t(point.x()) - int32_t(point2_.x());
  int32_t y_difference2 = int32_t(point.y()) - int32_t(point2_.y());

  // Using int64_t to avoid overflow when multiplying 17-bit values
  // resulting in 34-bit values.
  return int64_t(x_difference1) * int64_t(y_difference2) ==
    int64_t(y_difference1) * int64_t(x_difference2);
}

size_t Line2D::Hasher::operator()(const Line2D &line) const {
  if (line.is_vertical()) {
    // A vertical line is completely described by its x coordinate.
    hash<int16_t> coordinateHasher{};
    return coordinateHasher(line.point1_.x());
  }

  if (line.is_horizontal()) {
    // A horizontal line is completely described by its y coordinate.
    hash<int16_t> coordinate_hasher{};
    return coordinate_hasher(line.point1_.y()) * size_t(37987);
  }

  // The slope together with the x axis crossing point
  // form a canonical representation of the line.
  Fraction64::Hasher fraction_hasher{};
  return fraction_hasher(GetSlope(line)) * size_t(37987) +
    fraction_hasher(GetXOfXAxisCrossing(line));
}

} // namespace intgeo
} // namespace iharbury