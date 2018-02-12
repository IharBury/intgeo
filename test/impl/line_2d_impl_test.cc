// Copyright 2018 Ihar Bury

#include "gtest/gtest.h"

#include "src/line_2d.h"  // iharbury::intgeo::Line2D
#include "src/point_2d.h"  // iharbury::intgeo::Point2D
#include "src/impl/fraction64.h"  // iharbury::intgeo::impl::Fraction64

// iharbury::intgeo::impl::GetSlope,
// iharbury::intgeo::impl::GetXOfXAxisCrossing
#include "src/impl/line_2d_impl.h"

namespace {

using ::iharbury::intgeo::Line2D;
using ::iharbury::intgeo::Point2D;
using ::iharbury::intgeo::impl::Fraction64;
using ::iharbury::intgeo::impl::GetSlope;
using ::iharbury::intgeo::impl::GetXOfXAxisCrossing;

TEST(line_2d_test, the_slope_of_a_line_can_be_calculated) {
  Line2D line(Point2D(4, 7), Point2D(10, 17));
  EXPECT_EQ(Fraction64(5, 3), GetSlope(line));
}

TEST(line_2d_test, the_slope_of_a_horizontal_line_is_zero) {
  Line2D line(Point2D(4, 7), Point2D(10, 7));
  EXPECT_EQ(Fraction64(0, 1), GetSlope(line));
}

TEST(line_2d_test, the_x_of_the_x_axis_crossing_point_of_a_line_can_be_calculated) {
  Line2D line(Point2D(4, 7), Point2D(10, 17));
  EXPECT_EQ(Fraction64(-1, 5), GetXOfXAxisCrossing(line));
}

TEST(line_2d_test, the_x_of_the_x_axis_crossing_point_of_a_vertical_line_can_be_calculated) {
  Line2D line(Point2D(4, 7), Point2D(4, 17));
  EXPECT_EQ(Fraction64(4, 1), GetXOfXAxisCrossing(line));
}

}  // namespace
