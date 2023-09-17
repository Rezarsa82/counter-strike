#include "Health.h"

#include "Health.h"

Health::Health(const int h) : health_(h) {}
///
/// \return the health number
int Health::GetHealth() const{
  return health_;
}
/// reduce health and check it
/// \param h
void Health::ReduceHealth(const int h) {
  health_ -= h;
  if(health_ < 0)
    health_ = 0;
}
///
/// \param h set health to h
void Health::SetHealth(const int &h) {
  health_ = h;
}