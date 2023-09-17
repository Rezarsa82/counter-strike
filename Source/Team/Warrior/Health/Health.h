#ifndef COUNTER_STRIKE_TEAM_WARRIOR_HEALTH_HEALTH_H_
#define COUNTER_STRIKE_TEAM_WARRIOR_HEALTH_HEALTH_H_

class Health{
 public:
  explicit Health(int = 100);
  Health(const Health&) = delete;
  Health operator=(const Health&) = delete;
  void SetHealth(const int&);
  int GetHealth() const;
  void ReduceHealth(int);
 private:
  int health_;
};

#endif //COUNTER_STRIKE_TEAM_WARRIOR_HEALTH_HEALTH_H_
