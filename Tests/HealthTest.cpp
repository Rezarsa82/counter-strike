#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include "../Source/Team/Warrior/Health/Health.h"

TEST(Health, GetHealth){
  Health h1;
  EXPECT_EQ(h1.GetHealth(), 100);
}

TEST(Health, ReduceHealth){
  Health h1;
  h1.ReduceHealth(20);
  EXPECT_EQ(h1.GetHealth(), 80);
}

TEST(Health, SetHealth){
  Health h1;
  h1.SetHealth(50);
  EXPECT_EQ(h1.GetHealth(), 50);
}