#include "WeaponsData.h"
/// store weapon's data that we have in the game
std::map<std::string, Weapon *> WeaponsData::weapons_ = {
    {"AK",           (new Weapon("AK", 2700, 31, 100, GameData::GameData_KWeaponType_heavy, GameData::GameData_Access_terrorist))},
    {"AWP",          (new Weapon("AWP", 4300, 110, 50, GameData::GameData_KWeaponType_heavy, GameData::GameData_Access_all))},
    {"Revolver",     (new Weapon("Revolver", 600, 51, 150, GameData::GameData_KWeaponType_pistol, GameData::GameData_Access_terrorist))},
    {"Glock-18",     (new Weapon("Glock-18", 300, 11, 200, GameData::GameData_KWeaponType_pistol, GameData::GameData_Access_terrorist))},
    {"M4A1",         {new Weapon("M4A1", 2700, 29, 100, GameData::GameData_KWeaponType_heavy, GameData::GameData_Access_counter_terrorist)}},
    {"Desert-Eagle", (new Weapon("Desert-Eagle", 600, 53, 175, GameData::GameData_KWeaponType_pistol, GameData::GameData_Access_counter_terrorist))},
    {"UPS-S",        (new Weapon("UPS-S", 300, 13, 225, GameData::GameData_KWeaponType_pistol, GameData::GameData_Access_counter_terrorist))},
    {"knife",        (new Weapon("knife", 0, 43, 500, GameData::GameData_KWeaponType_knife, GameData::GameData_Access_all))}
};
///
/// \param name name of the weapon
/// \param accessLevel team(s) that can use the weapon
/// \return weapon if exist

Weapon *WeaponsData::GetWeapon(const std::string &name, GameData::GameData::Access accessLevel) {
  /*
  return weapons_[name];
   */
}
