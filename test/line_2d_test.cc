// Copyright 2018 Ihar Bury

#include <cstdint>  // INT16_MIN, INT16_MAX

#include "gtest/gtest.h"

#include "src/line_2d.h"  // iharbury::intgeo::Line2D
#include "src/point_2d.h"  // iharbury::intgeo::Point2D

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

TEST(line_2d_test, a_line_can_detect_a_point_on_it) {
  Line2D line(Point2D(1, 4), Point2D(10, 19));
  EXPECT_TRUE(line.HasPoint(Point2D(4, 9)));
}

TEST(line_2d_test, a_line_can_detect_a_point_not_on_it) {
  Line2D line(Point2D(1, 4), Point2D(10, 19));
  EXPECT_FALSE(line.HasPoint(Point2D(4, 10)));
}

TEST(line_2d_test, point1_of_a_line_is_on_the_line) {
  Line2D line(Point2D(1, 4), Point2D(10, 19));
  EXPECT_TRUE(line.HasPoint(Point2D(1, 4)));
}

TEST(line_2d_test, point2_of_a_line_is_on_the_line) {
  Line2D line(Point2D(1, 4), Point2D(10, 19));
  EXPECT_TRUE(line.HasPoint(Point2D(10, 19)));
}

TEST(line_2d_test, a_line_can_detect_a_point_on_it_for_large_coordinates) {
  Line2D line(Point2D(INT16_MIN, INT16_MAX), Point2D(INT16_MAX, INT16_MIN));
  EXPECT_TRUE(line.HasPoint(Point2D(INT16_MIN + 1, INT16_MAX - 1)));
}

TEST(line_2d_test, a_line_can_detect_a_point_not_on_it_for_large_coordinates) {
  Line2D line(Point2D(INT16_MIN, INT16_MAX), Point2D(INT16_MAX, INT16_MIN));
  EXPECT_FALSE(line.HasPoint(Point2D(INT16_MIN, INT16_MIN)));
}

TEST(line_2d_test, a_horizonal_line_can_detect_a_point_on_it) {
  Line2D line(Point2D(1, 3), Point2D(-10, 3));
  EXPECT_TRUE(line.HasPoint(Point2D(18, 3)));
}

TEST(line_2d_test, a_horizonal_line_can_detect_a_point_not_on_it) {
  Line2D line(Point2D(1, 3), Point2D(-10, 3));
  EXPECT_FALSE(line.HasPoint(Point2D(1, 4)));
}

TEST(line_2d_test, a_vertical_line_can_detect_a_point_on_it) {
  Line2D line(Point2D(1, 3), Point2D(1, -7));
  EXPECT_TRUE(line.HasPoint(Point2D(1, -15)));
}

TEST(line_2d_test, a_vertical_line_can_detect_a_point_not_on_it) {
  Line2D line(Point2D(1, 3), Point2D(1, -7));
  EXPECT_FALSE(line.HasPoint(Point2D(2, 3)));
}

TEST(line_2d_test, equal_lines_can_be_detected) {
  Line2D line1(Point2D(2, 4), Point2D(5, 7)),
         line2(Point2D(3, 5), Point2D(4, 6));
  EXPECT_TRUE(line1 == line2);
  EXPECT_FALSE(line1 != line2);
}

TEST(line_2d_test, not_equal_lines_can_be_detected) {
  Line2D line1(Point2D(2, 4), Point2D(5, 7)),
         line2(Point2D(3, 5), Point2D(4, 7));
  EXPECT_FALSE(line1 == line2);
  EXPECT_TRUE(line1 != line2);
}

TEST(line_2d_test, line_is_equal_to_itself) {
  Line2D line(Point2D(2, 4), Point2D(5, 7));
  EXPECT_TRUE(line == line);
  EXPECT_FALSE(line != line);
}

TEST(line_2d_test, parallel_lines_are_not_equal) {
  Line2D line1(Point2D(2, 4), Point2D(5, 7)),
         line2(Point2D(3, 4), Point2D(6, 7));
  EXPECT_FALSE(line1 == line2);
  EXPECT_TRUE(line1 != line2);
}

TEST(line_2d_test, horizonal_equal_lines_can_be_detected) {
  Line2D line1(Point2D(2, 4), Point2D(5, 4)),
         line2(Point2D(3, 4), Point2D(4, 4));
  EXPECT_TRUE(line1 == line2);
  EXPECT_FALSE(line1 != line2);
}

TEST(line_2d_test, vertical_equal_lines_can_be_detected) {
  Line2D line1(Point2D(2, 4), Point2D(2, 7)),
         line2(Point2D(2, 5), Point2D(2, 6));
  EXPECT_TRUE(line1 == line2);
  EXPECT_FALSE(line1 != line2);
}

TEST(line_2d_test, a_vertical_line_can_be_detected) {
  EXPECT_TRUE(Line2D(Point2D(2, 4), Point2D(2, 7)).is_vertical());
}

TEST(line_2d_test, a_non_vertical_line_can_be_detected) {
  EXPECT_FALSE(Line2D(Point2D(2, 4), Point2D(3, 7)).is_vertical());
}

TEST(line_2d_test, a_horizontal_line_can_be_detected) {
  EXPECT_TRUE(Line2D(Point2D(2, 4), Point2D(5, 4)).is_horizontal());
}

TEST(line_2d_test, a_non_horizontal_line_can_be_detected) {
  EXPECT_FALSE(Line2D(Point2D(2, 4), Point2D(5, 3)).is_horizontal());
}

TEST(line_2d_test, equal_lines_have_the_same_hash) {
  Line2D line1(Point2D(2, 4), Point2D(5, 7)),
         line2(Point2D(3, 5), Point2D(4, 6));
  Line2D::Hasher hasher;
  EXPECT_EQ(hasher(line1), hasher(line2));
}

}  // namespace
