#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include "../Source/Team/Warrior/Warrior.h"

TEST(Warrior, CreateWarrior) {
  Time t1("00:00:001");
  Time t2("00:03:000");
  Warrior w1("a", t1, GameData::GameData_Access_terrorist);
  EXPECT_EQ(w1.GetHealth(), 100);
  Warrior w2("b", t2, GameData::GameData_Access_terrorist);
  EXPECT_EQ(w2.GetHealth(), 0);
  EXPECT_EQ(w2.GetMoney(), 1000);
  EXPECT_EQ(w1.GetMoney(), 1000);
}

TEST(Warrior, IsAlive){
  Time t1("00:00:001");
  Time t2("00:03:000");
  Warrior w1("a", t1, GameData::GameData_Access_terrorist);
  EXPECT_TRUE(w1.IsAlive());
  Warrior w2("b", t2, GameData::GameData_Access_terrorist);
  EXPECT_FALSE(w2.IsAlive());
}

TEST(Warrior, Comparsion){
  Time t1("00:00:001");
  Time t2("00:00:002");
  Warrior w1("a", t1, GameData::GameData_Access_terrorist);
  Warrior w2("b", t2, GameData::GameData_Access_terrorist);
  w1.AddKill(GameData::GameData_KWeaponType_knife);
  EXPECT_TRUE(w1.IsBetter(&w2));
}