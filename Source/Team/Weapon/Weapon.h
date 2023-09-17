#ifndef COUNTER_STRIKE_TEAM_WEAPON_WEAPON_H_
#define COUNTER_STRIKE_TEAM_WEAPON_WEAPON_H_

#include <string>
#include <utility>
#include "../../Data.pb.h"

class Weapon {
 public:
  Weapon(std::string, int, int, int, GameData::GameData::KWeaponType, GameData::GameData::Access);
  Weapon(const Weapon&) = delete;
  Weapon operator=(const Weapon&) = delete;
  int GetPrice() const;
  int GetMoney() const;
  int GetPower() const;
  GameData::GameData::KWeaponType GetType() const;
 private:
  const std::string name_;
  const int price_;
  const int power_;
  const int money_;
  const GameData::GameData::Access access_level_;
  const GameData::GameData::KWeaponType type_;
};

#endif //COUNTER_STRIKE_TEAM_WEAPON_WEAPON_H_
