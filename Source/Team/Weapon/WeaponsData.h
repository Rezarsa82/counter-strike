#ifndef COUNTER_STRIKE_TEAM_WEAPON_WEAPONSDATA_H_
#define COUNTER_STRIKE_TEAM_WEAPON_WEAPONSDATA_H_

#include <map>
#include <string>

#include "Weapon.h"
#include "../../GameFeatures/Exception/Exception.h"

class WeaponsData {
 public:
  WeaponsData() = default;
  static Weapon *GetWeapon(const std::string&, GameData::GameData::Access);
 private:
  static std::map<std::string, Weapon *> weapons_;
};

#endif //COUNTER_STRIKE_TEAM_WEAPON_WEAPONSDATA_H_
