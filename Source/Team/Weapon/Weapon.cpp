#include "Weapon.h"
///
/// \param name name of the weapon
/// \param price price of the weapon
/// \param power power of the weapon that reduce the health of another warrior
/// \param money money of the weapon that to a warrior if kill someone
/// \param type type of the weapon(heavy or light)
/// \param accessLevel team that can use the weapon
Weapon::Weapon(std::string name, int price, int power, int money, GameData::GameData::KWeaponType type, GameData::GameData::Access accessLevel) :
    name_(std::move(name)), price_(price), power_(power), money_(money), type_(type), access_level_(accessLevel) {}
///
/// \return price of the weapon
int Weapon::GetPrice() const {
  return this->price_;
}
///
/// \return type of the weapon
GameData::GameData::KWeaponType Weapon::GetType() const {
  return this->type_;
}
///
/// \return money of the weapon
int Weapon::GetMoney() const {
  return this->money_;
}
///
/// \return power of the weapon
int Weapon::GetPower() const {
  return this->power_;
}

