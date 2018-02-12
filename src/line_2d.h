// Copyright 2018 Ihar Bury

#ifndef SRC_LINE_2D_H_
#define SRC_LINE_2D_H_

#include <cassert>  // assert
#include <cstddef>  // std::size_t

#include "src/point_2d.h"  // iharbury::intgeo::Point2D

namespace iharbury {
namespace intgeo {

// Represents a 2D line defined via a pair of its points
// with 16-bit integer Cartesian coordinates.
// Supports equality comparison and hashing.
// Equal lines can be defined via different pairs of points.
class Line2D final {
 public:
  class Hasher;

  // Constructs a new line given a pair of its points.
  // Points must be different.
  inline Line2D(const Point2D &point1, const Point2D& point2) :
      point1_(point1), point2_(point2) {
    assert(point1 != point2);
  }

  inline const Point2D &point1() const { return point1_; }
  inline const Point2D &point2() const { return point2_; }

  // Determines whether the line is horizontal,
  // i.e. parallel to the X coordinate axis.
  inline bool is_horizontal() const { return point1_.y() == point2_.y(); }

  // Determines whether the line is vertical,
  // i.e. parallel to the Y coordinate axis.
  inline bool is_vertical() const { return point1_.x() == point2_.x(); }

  // Determines whether the given point is on the line.
  bool HasPoint(const Point2D &) const;

 private:
  Point2D point1_;
  Point2D point2_;
};

// Should be used instead of std::hash to calculates hashes of Line2D values.
class Line2D::Hasher final {
 public:
  std::size_t operator()(const Line2D &) const;
};


inline bool operator==(const Line2D &line1, const Line2D &line2) {
  return line1.HasPoint(line2.point1()) && line1.HasPoint(line2.point2());
}

inline bool operator!=(const Line2D &line1, const Line2D &line2) {
  return !(line1 == line2);
}

}  // namespace intgeo
}  // namespace iharbury


#endif  // SRC_LINE_2D_H_
