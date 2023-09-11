#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "../Source/Team/Team.h"

TEST(Team, AddGet){
  Team t1(GameData::GameData_Access_terrorist);
  Time t("00:00:001");
  Warrior w("a", t, GameData::GameData_Access_terrorist);
  EXPECT_NO_THROW(t1.AddWarrior("a", t));
  EXPECT_ANY_THROW(t1.GetWarrior("b"));
  EXPECT_TRUE(t1.IsTeammate("a"));
  EXPECT_FALSE(t1.IsTeammate("b"));
}