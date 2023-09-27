#include "Money.h"
/// create money for the warrior that initialized to start money
Money::Money() : money_(Configuration::GetStartMoney()) {}
///
/// \return money of the warrior
int Money::GetMoney() const {
  return money_;
}
/// add to the money of warrior and check the limit max money
/// \param m amount of money that add to the money of the warrior
void Money::AddMoney(int m) {
  money_ += m;
  if (money_ >= Configuration::GetMaxMoney())
    money_ = Configuration::GetMaxMoney();
}
///
/// \param m amount of money that add from the money of the warrior
void Money::ReduceMoney(int m) {
  if((money_ - m) < 0)
    throw Exception::("money is not enough");
  money_ -= m;
}
///
/// \param m the money of the warrior that be set
void Money::SetMoney(int m) {
  money_ = m;
  if(money_ > Configuration::GetMaxMoney())
    money_ = Configuration::GetMaxMoney();
}
