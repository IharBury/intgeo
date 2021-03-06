// Copyright 2018 Ihar Bury

#ifndef SRC_POINT_2D_H_
#define SRC_POINT_2D_H_

#include <cstddef>  // std::size_t
#include <cstdint>  // int16_t
#include <functional>  // std::hash
#include <ostream>  // std::basic_ostream

namespace iharbury {
namespace intgeo {

// Represents a 2D point with 16-bit integer Cartesian coordinates.
// Supports equality comparison and hashing.
class Point2D final {
 public:
  class Hasher;

  inline Point2D() : x_(0), y_(0) {}
  inline Point2D(int16_t x, int16_t y) : x_(x), y_(y) {}

  inline int16_t x() const { return x_; }
  inline int16_t y() const { return y_; }

 private:
  int16_t x_;
  int16_t y_;
};

// Should be used instead of std::hash to calculates hashes of Point2D values.
class Point2D::Hasher final {
 public:
  inline std::size_t operator()(const Point2D &point) const {
    std::hash<int16_t> coordinate_hasher{};
    return coordinate_hasher(point.x()) * std::size_t(37987) +
           coordinate_hasher(point.y());
  }
};

inline bool operator==(const Point2D &point1, const Point2D &point2) {
  return (point1.x() == point2.x()) && (point1.y() == point2.y());
}

inline bool operator!=(const Point2D &point1, const Point2D &point2) {
  return !(point1 == point2);
}

template<class Traits> std::basic_ostream<char, Traits>& operator<<(
    std::basic_ostream<char, Traits>& x, const Point2D &point) {
  return x << '(' << point.x() << ", " << point.y() << ')';
}

}  // namespace intgeo
}  // namespace iharbury

#endif  // SRC_POINT_2D_H_
