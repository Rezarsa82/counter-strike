#include "Score.h"
/// make a score for the warrior with zero kills and deaths
Score::Score() : kill_(0), death_(0) {}
///
/// \return number of deaths
int Score::GetDeath() const {
  return death_;
}
///
/// \return number of kills
int Score::GetKill() const {
  return kill_;
}
/// add one death to the number of deaths
void Score::AddDeath() {
  death_++;
}
/// add one kill to the number of kills
void Score::AddKill() {
  kill_++;
}