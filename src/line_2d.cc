#include "line_2d.h"

namespace iharbury {
namespace intgeo {

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
  int32_t xDifference1 = int32_t(point.x()) - int32_t(point1_.x());
  int32_t yDifference1 = int32_t(point.y()) - int32_t(point1_.y());
  int32_t xDifference2 = int32_t(point.x()) - int32_t(point2_.x());
  int32_t yDifference2 = int32_t(point.y()) - int32_t(point2_.y());

  // Using int64_t to avoid overflow when multiplying 17-bit values
  // resulting in 34-bit values.
  return int64_t(xDifference1) * int64_t(yDifference2) ==
    int64_t(yDifference1) * int64_t(xDifference2);
}

} // namespace intgeo
} // namespace iharbury