// Copyright 2018 Ihar Bury

#include <sstream>  // std::stringstream
#include <string>  // std::string

#include "gtest/gtest.h"

#include "src/point_2d.h"  // iharbury::intgeo::Point2D

namespace {

using ::iharbury::intgeo::Point2D;
using ::std::string;
using ::std::stringstream;

TEST(point_2d_test, a_point_is_initialized_to_origin_of_coordinates_by_default) {
  Point2D point;
  EXPECT_EQ(0, point.x());
  EXPECT_EQ(0, point.y());
}

TEST(point_2d_test, a_point_can_be_initialized_to_the_given_coordinates) {
  Point2D point(4, 10);
  EXPECT_EQ(4, point.x());
  EXPECT_EQ(10, point.y());
}

TEST(point_2d_test, a_point_can_be_copied) {
  Point2D point(4, 10), copy(point);
  EXPECT_EQ(4, copy.x());
  EXPECT_EQ(10, copy.y());
}

TEST(point_2d_test, a_point_can_be_assigned) {
  Point2D point(4, 10), assigned;
  assigned = point;
  EXPECT_EQ(4, assigned.x());
  EXPECT_EQ(10, assigned.y());
}

TEST(point_2d_test, points_are_equal_when_both_their_coordinates_match) {
  Point2D point1(4, 10), point2(4, 10);
  EXPECT_TRUE(point1 == point2);
  EXPECT_FALSE(point1 != point2);
}

TEST(point_2d_test, points_are_not_equal_when_their_x_coordinates_do_not_match) {
  Point2D point1(4, 10), point2(6, 10);
  EXPECT_FALSE(point1 == point2);
  EXPECT_TRUE(point1 != point2);
}

TEST(point_2d_test, points_are_not_equal_when_their_y_coordinates_do_not_match) {
  Point2D point1(4, 10), point2(4, 8);
  EXPECT_FALSE(point1 == point2);
  EXPECT_TRUE(point1 != point2);
}

TEST(point_2d_test, points_have_the_same_hash_when_both_their_coordinates_match) {
  Point2D::Hasher hasher;
  EXPECT_EQ(hasher(Point2D(4, 10)), hasher(Point2D(4, 10)));
}

TEST(point_2d_test, a_point_can_be_written_to_a_stream) {
  stringstream stream;
  stream << Point2D(4, 10);
  EXPECT_EQ("(4, 10)", stream.str());
}

}  // namespace
