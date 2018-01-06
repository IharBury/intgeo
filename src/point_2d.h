#ifndef IHARBURY_INTGEO_POINT_2D_H
#define IHARBURY_INTGEO_POINT_2D_H

#include <stdint.h>

#include <cstddef>
#include <ostream>

namespace iharbury {
namespace intgeo {

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

class Point2D::Hasher final {
 public:
  inline std::size_t operator()(const Point2D &point) const {
    return std::size_t(point.x()) * std::size_t(37987) + std::size_t(point.y());
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

} // namespace intgeo
} // namespace iharbury

#endif // IHARBURY_INTGEO_POINT_2D_H
