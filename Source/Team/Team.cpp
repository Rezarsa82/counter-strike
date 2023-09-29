#include "Team.h"

Team::Team(GameData::GameData::Access access_level) : KAccessLevel_(access_level) {
  if(access_level == GameData::GameData::Access::GameData_Access_terrorist)
    name = "Terrorist";
  else
    name = "Counter-Terrorist";
}
/// check the teammate limit and add a warrior to team
/// \param name name of the new warrior
/// \param time time that join the team
void Team::AddWarrior(const std::string &name, const Time &time) {
  if (warriors_.size() == Configuration::GetMaxMembers())
    throw Exception("this Team is full");
  warriors_[name] = new Warrior(name, time, KAccessLevel_);
}
/// check the team members to find a teammate called name
/// \param name name of the member we search for
/// \return the result of check
bool Team::IsTeammate(const std::string &name) const {
  return warriors_.count(name);
}
/// find a teammate and return it
/// \param name name of the team member
/// \return the warrior if exist
Warrior *Team::GetWarrior(const std::string &name) const {
  if (warriors_.count(name))
    return warriors_.at(name);
  else
    throw Exception("invalid username");
}
/// end the round and prepare team for new round
void Team::NewSet() {
  for (auto &player: warriors_)
    player.second->EndGame();
}
/// calculate the scoreboard of the team and return it
std::vector<Warrior *> Team::GetScoreBoard() const {
  std::vector<Warrior *> score_board;
  for (const auto &player: warriors_)
    score_board.push_back(player.second);
  std::sort(score_board.begin(), score_board.end(), [](Warrior *a, Warrior *b) { return a->IsBetter(b); });
  return score_board;
}
/// team won a round and members get losing award
void Team::Won() const {
  for (auto &player: warriors_)
    player.second->AddWinPrize();
}
/// team lose a round and members get losing award
void Team::Lose() const {
  for (auto &player: warriors_)
    player.second->AddLosePrize();
}
/// calculate the number of alive members
/// \return the number of team members that are alive
int Team::GetAliveNum() const {
  int liveNum = 0;
  for (auto &player: warriors_)
    if (player.second->IsAlive())
      liveNum++;
  return liveNum;
}
/// destructor of team that must delete warriors_ map
Team::~Team() {
  for (const auto &player: warriors_)
    delete player.second;
  this->warriors_.clear();
}
