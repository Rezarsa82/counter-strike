#ifndef COUNTER_STRIKE_TEAM_TEAM_H_
#define COUNTER_STRIKE_TEAM_TEAM_H_

#include <string>
#include <map>
#include <vector>
#include <algorithm>

#include "Weapon/Weapon.h"
#include "Warrior/Warrior.h"
#include "Weapon/WeaponsData.h"
#include "../GameFeatures/Exception/Exception.h"
#include "../Data.pb.h"

class Team {
 public:
  explicit Team(GameData::GameData::Access);
  Team(const Team&) = delete;
  Team operator=(const Team&) = delete;
  void AddWarrior(const std::string&, const Time&);
  Warrior *GetWarrior(const std::string&) const;
  void NewSet();
  std::vector<Warrior *> GetScoreBoard() const;
  bool IsTeammate(const std::string&) const;
  void Won() const;
  void Lose() const;
  int GetAliveNum() const;
  std::string GetName() const;
  ~Team();
 private:
  std::string name;
  std::map<std::string, std::reference_wrapper<Warrior> > warriors_;
  const GameData::GameData::Access KAccessLevel_;
};


#endif //COUNTER_STRIKE_TEAM_TEAM_H_
