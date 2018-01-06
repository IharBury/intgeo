#ifndef IHARBURY_INTGEO_LINE_2D_H
#define IHARBURY_INTGEO_LINE_2D_H

#include <cassert>

#include "point_2d.h"

namespace iharbury {
namespace intgeo {

class Line2D final {
 public:
  inline Line2D(const Point2D &point1, const Point2D& point2) :
      point1_(point1), point2_(point2) {
    assert(point1 != point2);
  }

  inline const Point2D &point1() { return point1_; }
  inline const Point2D &point2() { return point2_; }

 private:
  Point2D point1_;
  Point2D point2_;
};

} // namespace intgeo
} // namespace iharbury


#endif IHARBURY_INTGEO_LINE_2D_H