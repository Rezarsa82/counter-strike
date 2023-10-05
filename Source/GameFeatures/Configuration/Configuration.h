#ifndef COUNTER_STRIKE_GAMEFEATURES_CONFIGURATION_CONFIGURATION_H_
#define COUNTER_STRIKE_GAMEFEATURES_CONFIGURATION_CONFIGURATION_H_

#include <string>
#include <map>

#include "../../Team/Weapon/Weapon.h"
#include "../../Team/Weapon/WeaponsData.h"
#include "../../Data.pb.h"

class Configuration {
 public:
  Configuration();
  Configuration(const Configuration&) = delete;
  Configuration operator=(const Configuration&) = delete;
  static int GetMaxMembers();
  static int GetMaxMoney();
  static int GetStartMoney();
  static int GetWinAward();
  static int GetLoseAward();
  static std::string GetEndGame();
  static std::string GetBuyLimit();
  static std::string GetAddLimit();
  static std::string TeamString(GameData::GameData::Team);
  static GameData::GameData::Team TeamEnum(const std::string&);
  static std::string WeaponString(GameData::GameData::KWeaponType);
  static GameData::GameData::KWeaponType WeaponEnum(const std::string&);
  static const Weapon *KKnife();
 private:
  static const int KMaxMembers_ = 10;
  static const int KMaxMoney_ = 10000;
  static const int KStartMoney_ = 1000;
  static const int KWinAward_ = 2700;
  static const int KLoseAward_ = 2400;
  static const std::string KEndGame_;
  static const std::string KBuyLimit_;
  static const std::string KAddLimit_;
  static const Weapon *KKnife_;
};

#endif //COUNTER_STRIKE_GAMEFEATURES_CONFIGURATION_CONFIGURATION_H_
