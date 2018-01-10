#ifndef IHARBURY_INTGEO_LINE_2D_H_
#define IHARBURY_INTGEO_LINE_2D_H_

#include <cassert> // assert

#include "point_2d.h" // iharbury::intgeo::Point2D

namespace iharbury {
namespace intgeo {

class Line2D final {
 public:
  inline Line2D(const Point2D &point1, const Point2D& point2) :
      point1_(point1), point2_(point2) {
    assert(point1 != point2);
  }

  inline const Point2D &point1() const { return point1_; }
  inline const Point2D &point2() const { return point2_; }
  inline bool is_horizontal() const { return point1_.y() == point2_.y(); }
  inline bool is_vertical() const { return point1_.x() == point2_.x(); }

  bool HasPoint(const Point2D &) const;

 private:
  Point2D point1_;
  Point2D point2_;
};

inline bool operator==(const Line2D &line1, const Line2D &line2) {
  return line1.HasPoint(line2.point1()) && line1.HasPoint(line2.point2());
}

inline bool operator!=(const Line2D &line1, const Line2D &line2) {
  return !(line1 == line2);
}

} // namespace intgeo
} // namespace iharbury


#endif // IHARBURY_INTGEO_LINE_2D_H_