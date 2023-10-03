#ifndef COUNTER_STRIKE_GAMEFEATURES_EXCEPTION_EXCEPTION_H_
#define COUNTER_STRIKE_GAMEFEATURES_EXCEPTION_EXCEPTION_H_

#include <exception>
#include <string>

class Exception : public std::exception {
 public:
  explicit Exception(std::string message);
  Exception operator=(const Exception&) = delete;
  std::string GetError() const;
 private:
  std::string message_;
};

 class TapException : public std::exception{
 public:
  explicit TapException() = default;
  static void AttackerIsDead();
  static void AttackedIsDead();
  static void NoGun();
  static void FriendlyFire();
  private:
  std::string message_;
};


#endif //COUNTER_STRIKE_GAMEFEATURES_EXCEPTION_EXCEPTION_H_
