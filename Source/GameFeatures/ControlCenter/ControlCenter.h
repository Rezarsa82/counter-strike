#ifndef COUNTER_STRIKE_GAMEFEATURES_CONTROLCENTER_CONTROLCENTER_H_
#define COUNTER_STRIKE_GAMEFEATURES_CONTROLCENTER_CONTROLCENTER_H_

#include <iostream>
#include <string>

#include "../../Time/Time.h"
#include "../Exception/Exception.h"
#include "../../Team/Team.h"
#include "../../Data.pb.h"

class ControlCenter {
 public:
  ControlCenter operator=(const ControlCenter&) = delete;
  std::string AddUser(const std::string&, GameData::GameData::Team, const std::string&);
  std::string Tap(const std::string&, const std::string&, GameData::GameData::KWeaponType) const;
  std::string Buy(const std::string&, const std::string&, const std::string&) const;
  int GetMoney(const std::string&) const;
  int GetHealth(const std::string&) const;
  void ScoreBoard() const;
  void NewRound();
  Warrior *Find(const std::string&) const;
  bool IsWarrior(const std::string&) const;
  ~ControlCenter();
 private:
  int round_ = 1;
  Team *terrorist_ = new Team(GameData::GameData::Access::GameData_Access_terrorist);
  Team *counter_terrorist_ = new Team(GameData::GameData::Access::GameData_Access_counter_terrorist);
};


#endif //COUNTER_STRIKE_GAMEFEATURES_CONTROLCENTER_CONTROLCENTER_H_
