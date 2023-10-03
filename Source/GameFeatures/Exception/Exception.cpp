#include "Exception.h"

Exception::Exception(std::string message) : message_(std::move(message)) {}

std::string Exception::GetError() const {
  return message_;
}

void TapException::AttackerIsDead() {
  throw Exception("attacker is dead");
}

void TapException::AttackedIsDead() {
  throw Exception("attacked is dead");
}

void TapException::NoGun() {
  throw Exception("no such gun");
}

void TapException::FriendlyFire() {
  throw Exception("friendly fire");
}
