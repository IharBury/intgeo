#ifndef IHARBURY_INTGEO_POINT_2D_H
#define IHARBURY_INTGEO_POINT_2D_H

#include <cstddef>
#include <functional>
#include <ostream>

namespace iharbury {
namespace intgeo {

class Point2D final {
 public:
  class Hasher;

  inline Point2D() : x_(0), y_(0) {}
  inline Point2D(int x, int y) : x_(x), y_(y) {}

  inline int x() const { return x_; }
  inline int y() const { return y_; }

 private:
  int x_;
  int y_;
};

class Point2D::Hasher final {
 public:
  inline std::size_t operator()(const Point2D &point) const {
    return coordinateHasher(point.x()) * std::size_t(37987) +
      coordinateHasher(point.y());
  }

 private:
  std::hash<int> coordinateHasher;
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
