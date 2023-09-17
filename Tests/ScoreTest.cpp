#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include "../Source/Team/Warrior/Score/Score.h"

TEST(Score, GetKill){
  Score h1;
  EXPECT_EQ(h1.GetKill(), 0);
}

TEST(Score, GetDeath){
  Score h1;
  EXPECT_EQ(h1.GetDeath(), 0);
}

TEST(Score, AddDeath){
  Score h1;
  EXPECT_EQ(h1.GetDeath(), 0);
  h1.AddDeath();
  EXPECT_EQ(h1.GetDeath(), 1);
}

TEST(Score, AddKill){
  Score h1;
  EXPECT_EQ(h1.GetKill(), 0);
  h1.AddKill();
  EXPECT_EQ(h1.GetKill(), 1);
}