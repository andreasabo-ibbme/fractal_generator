#include <gtest/gtest.h>

TEST(HelloTest, BasicAssertions_v2) {
  // Expect two strings not to be equal.
  EXPECT_STRNE("hello", "world");
  // Expect equality.
  EXPECT_EQ(7 * 6, 42);
}