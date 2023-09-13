#include "Warrior.h"
/// create a new warrior in the game
/// \param name name of the warrior
/// \param time time that the warrior join the game
/// \param access_level team of the warrior
Warrior::Warrior(std::string name, const Time &time, GameData::GameData::Access access_level) :
    name_(std::move(name)), join_time_(time), access_level_(access_level) {
  weapons_[Configuration::KKnife()->GetType()] = Configuration::KKnife();
  if ((time % Time(Configuration::GetEndGame())) > Time(Configuration::GetAddLimit()))
    health_.SetHealth(0);
}
/// EndGame - change warrior data and prepare for new round
void Warrior::EndGame() {
  weapons_[Configuration::KKnife()->GetType()] = Configuration::KKnife();
  health_.SetHealth(100);
}
///
/// \param reduce_health  warrior's health should be reduced when attacked
/// \return result of the attack, Warrior is alive or not
bool Warrior::CanAttack(int reduce_health) {
  if (!IsAlive())
    throw Exception("Warrior is not live!");
  health_.ReduceHealth(reduce_health);
  if (health_.GetHealth() <= 0) {
    health_.SetHealth(0);
    score_.AddDeath();
    weapons_.clear();
  }
  return !health_.GetHealth();
}
/// Buy weapon for the selected warrior
/// \param name name of the weapon that warrior wants to buy
void Warrior::Buy(const std::string &name) {
  auto weapon = WeaponsData::GetWeapon(name, access_level_);
  if (weapon->GetPrice() > money_.GetMoney())
    throw Exception("no enough money");
  if (weapons_.count(weapon->GetType()))
    throw Exception("you have a " + Configuration::WeaponString(weapon->GetType()));
  money_.ReduceMoney(weapon->GetPrice());
  weapons_[weapon->GetType()] = weapon;
}
/// warrior kills another warrior and score and money should be updated
/// \param type the weapon that warrior used
void Warrior::AddKill(GameData::GameData::KWeaponType type) {
  score_.AddKill();
  AddMoney(weapons_[type]->GetMoney());
}
///
/// \return get health of the warrior
int Warrior::GetHealth() const {
  return health_.GetHealth();
}
///
/// \return get money of the warrior
int Warrior::GetMoney() const {
  return money_.GetMoney();
}
///
/// \return get name of the warrior
std::string Warrior::GetName() const {
  return name_;
}
/// team won and warrior get prize of winning
void Warrior::AddWinPrize() {
  AddMoney(Configuration::GetWinAward());
}
/// team won and warrior get prize of winning
void Warrior::AddLosePrize() {
  AddMoney(Configuration::GetLoseAward());
}
///
/// \param money add money to the warrior
void Warrior::AddMoney(int money) {
  money_.AddMoney(money);
  if (money_.GetMoney() > Configuration::GetMaxMoney())
    money_.SetMoney(Configuration::GetMaxMoney());
}
///
/// \return check warrior is alive or dead
bool Warrior::IsAlive() const {
  if(health_.GetHealth())
    return true;
  return false;
}
/// check tha warrior's weapon to check warrior has a weapon or not
/// \param type the type of weapon that want t check
/// \return
bool Warrior::CheckWeapon(GameData::GameData::KWeaponType type) const {
  return weapons_.count(type);
}
/// get warrior's weapon
/// \param type type of the weapon that must returned
/// \return
Weapon *Warrior::GetWeapon(GameData::GameData::KWeaponType type) const {
  if (CheckWeapon(type))
    return const_cast<Weapon *>(weapons_.at(type));
  else
    return nullptr;
}
/// compare two warrior with score and joining time
/// \param warrior second warrior that compare with this warrior
/// \return true if this warrior is better
bool Warrior::IsBetter(Warrior* warrior) const {
  if (score_.GetKill() < warrior->score_.GetKill())
    return true;
  if (score_.GetKill() == warrior->score_.GetKill()) {
    if (score_.GetDeath() > warrior->score_.GetDeath())
      return true;
    if (score_.GetDeath() == warrior->score_.GetDeath())
      return join_time_ > warrior->join_time_;
  }
  return false;
}
/// print tha warrior in the scoreboard format
void Warrior::PrintWarrior() const {
  std::cout << GetName() << " " << score_.GetKill() << " " << score_.GetDeath() << std::endl;
}


