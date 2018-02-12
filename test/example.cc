#include <unordered_map> // std::unordered_map

#include "gtest/gtest.h"

#include "line_2d.h" // iharbury::intgeo::Line2D
#include "point_2d.h" // iharbury::intgeo::Point2D

namespace {

using ::iharbury::intgeo::Line2D;
using ::iharbury::intgeo::Point2D;

TEST(example, lines_can_be_used_as_keys_in_hash_map) {
  std::unordered_map<Line2D, int, Line2D::Hasher> map;
  map[Line2D{ Point2D(2, 4), Point2D(3, 5) }] = 1;
  map[Line2D{ Point2D(4, 6), Point2D(7, 9) }]++;
  int value = map[Line2D{ Point2D(1, 3), Point2D(0, 2) }];
  EXPECT_EQ(2, value);
}

} // namespace