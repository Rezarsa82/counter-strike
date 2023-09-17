#ifndef COUNTER_STRIKE_TEAM_WARRIOR_SCORE_H
#define COUNTER_STRIKE_TEAM_WARRIOR_SCORE_H

class Score{
 public:
  Score();
  Score(const Score&) = delete;
  Score operator=(const Score&) = delete;
  int GetKill() const;
  int GetDeath() const;
  void AddDeath();
  void AddKill();
 private:
  int kill_;
  int death_;
};

#endif //COUNTER_STRIKE_TEAM_WARRIOR_SCORE_H
