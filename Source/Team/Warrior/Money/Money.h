#ifndef COUNTER_STRIKE_TEAM_WARRIOR_MONEY_MONEY_H_
#define COUNTER_STRIKE_TEAM_WARRIOR_MONEY_MONEY_H_

#include "../../../GameFeatures/Configuration/Configuration.h"

class Money{
 public:
  explicit Money();
  Money(const Money&) = delete;
  Money operator=(const Money&)= delete;
  int GetMoney() const;
  void AddMoney(int);
  void ReduceMoney(int);
  void SetMoney(int);
 private:
  int money_;
};

#endif //COUNTER_STRIKE_TEAM_WARRIOR_MONEY_MONEY_H_
