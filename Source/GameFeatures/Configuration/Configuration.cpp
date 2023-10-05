#include "Configuration.h"

const std::string Configuration::KEndGame_ = "02:15:000";
const std::string Configuration::KBuyLimit_ = "00:45:000";
const std::string Configuration::KAddLimit_ = "00:03:000";
const Weapon *Configuration::KKnife_ = WeaponsData::GetWeapon("knife", GameData::GameData::setting);

Configuration::Configuration() = default;

GameData::GameData::Team Configuration::TeamEnum(const std::string &team) {
  if (team == "Counter-Terrorist")
    return GameData::GameData::Team::GameData_Team_Counter_Terrorist;
  else if (team == "Terrorist")
    return GameData::GameData::Team::GameData_Team_Terrorist;
  else
    throw Exception("Invalid Team named " + team);
}

GameData::GameData::KWeaponType Configuration::WeaponEnum(const std::string &weapon_type) {
  if (weapon_type == "heavy")
    return GameData::GameData::KWeaponType::GameData_KWeaponType_heavy;
  else if (weapon_type == "pistol")
    return GameData::GameData::KWeaponType::GameData_KWeaponType_pistol;
  else if (weapon_type == "knife")
    return GameData::GameData::KWeaponType::GameData_KWeaponType_knife;
  else
    throw Exception("Invalid gun type " + weapon_type);
}

std::string Configuration::TeamString(GameData::GameData::Team team) {
  if (team == GameData::GameData::Team::GameData_Team_Counter_Terrorist)
    return "Counter-Terrorist";
  else if (team == GameData::GameData::Team::GameData_Team_Terrorist)
    return "Terrorist";
  else
    throw Exception("Invalid Team enum ");
}

std::string Configuration::WeaponString(GameData::GameData::KWeaponType weapon_type) {
  if (weapon_type == GameData::GameData_KWeaponType_heavy)
    return "heavy";
  else if (weapon_type == GameData::GameData_KWeaponType_pistol)
    return "pistol";
  else if (weapon_type == GameData::GameData_KWeaponType_knife)
    return "knife";
  else
    throw Exception("Invalid gun type enum");
}

int Configuration::GetStartMoney() {
  return Configuration::KStartMoney_;
}

int Configuration::GetMaxMoney() {
  return Configuration::KMaxMoney_;
}

int Configuration::GetWinAward() {
  return Configuration::KWinAward_;
}

int Configuration::GetLoseAward() {
  return Configuration::KLoseAward_;
}

std::string Configuration::GetEndGame() {
  return Configuration::KEndGame_;
}

std::string Configuration::GetBuyLimit() {
  return Configuration::KBuyLimit_;
}

std::string Configuration::GetAddLimit() {
  return Configuration::KAddLimit_;
}

const Weapon *Configuration::KKnife() {
  return Configuration::KKnife_;
}

int Configuration::GetMaxMembers() {
  return Configuration::KMaxMembers_;
}
