#include "ControlCenter.h"
///
/// \param name
/// \return find a warrior (name) and return if exist
Warrior *ControlCenter::Find(const std::string &name) const {
  if (this->counter_terrorist_->IsTeammate(name))
    return counter_terrorist_->GetWarrior(name);
  if (terrorist_->IsTeammate(name))
    return terrorist_->GetWarrior(name);
  throw Exception("invalid username");
}
///
/// \param name
/// \return is a warrior in the game with name = neme?
bool ControlCenter::IsWarrior(const std::string &name) const {
  return counter_terrorist_->IsTeammate(name) || terrorist_->IsTeammate(name);
}
///
/// \param name name of the warrior that wants to join
/// \param team team that wants to join
/// \param time time of joining
/// \return result of the order
std::string ControlCenter::AddUser(const std::string &name, GameData::GameData::Team team, const std::string &time) {
  if (IsWarrior(name))
    throw Exception("you are already in this game");
  auto time_of_add = Time(time, round_);
  switch (team) {
    case GameData::GameData_Team_Terrorist:terrorist_->AddWarrior(name, time_of_add);
      break;
    case GameData::GameData_Team_Counter_Terrorist:counter_terrorist_->AddWarrior(name, time_of_add);
      break;
    default:
      throw Exception("Unsupported variable type: " + Configuration::TeamString(team));
  }
  std::string msg = "this user added to " + Configuration::TeamString(team);
  return msg;
}
///
/// \param name name of the warrior
/// \return get money of the warrior (name) if exist
int ControlCenter::GetMoney(const std::string &name) const {
  return Find(name)->GetMoney();
}
///
/// \param name name of the warrior
/// \return get health of the warrior (name) if exist
int ControlCenter::GetHealth(const std::string &name) const {
  return Find(name)->GetHealth();
}

std::string ControlCenter::Tap(const std::string &attacker, const std::string &attacked, GameData::GameData::KWeaponType type) const {
  auto attacker_player = Find(attacker);
  auto attacked_player = Find(attacked);
  if (!attacker_player->IsAlive())
    throw Exception("attacker is dead");
  if (!attacked_player->IsAlive())
    throw Exception("attacked is dead");
  if (!attacker_player->HasWeapon(type))
    throw Exception("no such gun");
  if (!(terrorist_->IsTeammate(attacker) ^ terrorist_->IsTeammate(attacked)))
    throw Exception("friendly fire");
  if (attacked_player->CanAttack(attacker_player->GetWeapon(type)->GetPower())) { attacker_player->AddKill(type); }
  return "nice shot";
}
/// check money/ username/ weapon and ... to buy a gun
/// \param name warrior the wants to buy a weapon
/// \param weapon_name weapon name
/// \param time buying time
/// \return result of the buy
std::string ControlCenter::Buy(const std::string &name, const std::string &weapon_name, const std::string &time) const {
  auto player = Find(name);
  if (!player->IsAlive()) throw Exception("deads can not Buy");
  if (Time(time) > Time(Configuration::GetBuyLimit())) throw Exception("you are out of time");
  player->Buy(weapon_name);
  return "I hope you can use it";
}
/// print scoreboard of the game by call scoreboard from teams
void ControlCenter::ScoreBoard() const {
  std::cout << "Counter-Terrorist-Players:" << std::endl;
  for(int i = 0; i < counter_terrorist_->GetScoreBoard().size(); i++){
    std::cout << i + 1 << " ";
    counter_terrorist_->GetScoreBoard()[i]->PrintWarrior();
  }
  std::cout << "Terrorist-Players:" << std::endl;
  for(int i = 0; i < terrorist_->GetScoreBoard().size(); i++){
    std::cout << i + 1 << " ";
    terrorist_->GetScoreBoard()[i]->PrintWarrior();
  }
}
/// find the winner and call new round for teams
void ControlCenter::NewRound() {
  round_++;
  if ((counter_terrorist_->GetAliveNum() == 0) && terrorist_->GetAliveNum() != 0) {
    std::cout << "Terrorist Won" << std::endl;
    terrorist_->Won();
    counter_terrorist_->Lose();
  }
  else {
    std::cout << "Counter-Terrorist Won" << std::endl;
    terrorist_->Lose();
    counter_terrorist_->Won();
  }
  terrorist_->NewSet();
  counter_terrorist_->NewSet();
}
/// to delete memory that allocated
ControlCenter::~ControlCenter() {
  delete terrorist_;
  delete counter_terrorist_;
}
