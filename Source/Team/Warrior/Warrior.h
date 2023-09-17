#ifndef COUNTER_STRIKE_TEAM_WARRIOR_H
#define COUNTER_STRIKE_TEAM_WARRIOR_H

#include <string>
#include <map>
#include <iostream>

#include "../../GameFeatures/Configuration/Configuration.h"
#include "../../Time/Time.h"
#include "../Weapon/Weapon.h"
#include "Money/Money.h"
#include "Health/Health.h"
#include "Score/Score.h"

class Warrior {
 public:
  explicit Warrior(std::string, const Time&, GameData::GameData::Access);
  Warrior operator=(const Warrior&) = delete;
  std::string GetName() const;
  int GetHealth() const;
  int GetMoney() const;
  void AddWinPrize();
  void AddLosePrize();
  void EndGame();
  void AddMoney(int);
  void PrintWarrior() const;
  void AddKill(GameData::GameData::KWeaponType);
  void Buy(const std::string&);
  bool IsAlive() const;
  bool CanAttack(int);
  bool CheckWeapon(GameData::GameData::KWeaponType) const;
  bool IsBetter(Warrior*) const;
  Weapon *GetWeapon(GameData::GameData::KWeaponType) const;
 private:
  const std::string name_;
  Money money_;
  Health health_;
  Score score_;
  std::map<GameData::GameData::KWeaponType, const Weapon *> weapons_;
  const GameData::GameData::Access access_level_;
  Time join_time_;
};


#endif //COUNTER_STRIKE_TEAM_WARRIOR_H
