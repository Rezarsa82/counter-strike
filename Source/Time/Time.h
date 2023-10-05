#ifndef COUNTER_STRIKE_TIME_TIME_H_
#define COUNTER_STRIKE_TIME_TIME_H_

#include <string>
#include <regex>

#include "../GameFeatures/Configuration/Configuration.h"

class Time {
 public:
  explicit Time(const std::string&, int = 1);
  explicit Time(int);
  static int correct_str_to_milliseconds(const std::string&);
  static bool str_is_correct(const std::string&);
  bool operator==(const Time&) const;
  bool operator==(const std::string&) const;
  bool operator<(const Time&) const;
  bool operator>(const Time&) const;
  bool operator<(const std::string&) const;
  bool operator>(const std::string&) const;
  Time operator*(int) const;
  Time operator%(const Time&) const;
  Time operator+(const Time&) const;
 private:
  int milliseconds_;
};

#endif //COUNTER_STRIKE_TIME_TIME_H_
