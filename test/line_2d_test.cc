#include <sstream>

#include "gtest/gtest.h"

#include "line_2d.h"
#include "point_2d.h"

namespace {

using ::iharbury::intgeo::Line2D;
using ::iharbury::intgeo::Point2D;

TEST(line_2d_test, a_line_can_be_initialized_with_two_of_its_points) {
  Line2D line(Point2D(1, 5), Point2D(3, 3));
  EXPECT_EQ(Point2D(1, 5), line.point1());
  EXPECT_EQ(Point2D(3, 3), line.point2());
}

TEST(line_2d_test, a_line_can_be_copied) {
  Line2D line(Point2D(1, 5), Point2D(3, 3)), copy(line);
  EXPECT_EQ(Point2D(1, 5), copy.point1());
  EXPECT_EQ(Point2D(3, 3), copy.point2());
}

TEST(line_2d_test, a_line_can_be_assigned) {
  Line2D line(Point2D(1, 5), Point2D(3, 3));
  Line2D assigned(Point2D(0, 0), Point2D(1, 1));
  assigned = line;
  EXPECT_EQ(Point2D(1, 5), assigned.point1());
  EXPECT_EQ(Point2D(3, 3), assigned.point2());
}

} // namespace