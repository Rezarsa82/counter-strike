#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include "../Source/Team/Warrior/Money/Money.h"

TEST(Money, GetMoney){
  Money m1;
  EXPECT_EQ(m1.GetMoney(), 1000);
}

TEST(Health, AddMoney){
  Money m1;
  m1.AddMoney(50);
  EXPECT_EQ(m1.GetMoney(), 1050);
}

TEST(Money, ReduceMoney){
  Money m1;
  EXPECT_EQ(m1.GetMoney(), 1000);
  m1.ReduceMoney(100);
  EXPECT_EQ(m1.GetMoney(), 900);
}

TEST(Money, SetMoney){
  Money m1;
  EXPECT_EQ(m1.GetMoney(), 1000);
  m1.SetMoney(100);
  EXPECT_EQ(m1.GetMoney(), 100);
}