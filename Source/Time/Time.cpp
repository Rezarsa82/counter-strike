#include "Time.h"

#include "../GameFeatures/Exception/Exception.h"

Time::Time(int time) : milliseconds_(time) {}

Time::Time(const std::string &time, int round) {
  if (round == 1)
    this->milliseconds_ = Time::correct_str_to_milliseconds(time);
  else
    this->milliseconds_ =
        (Time(Configuration::GetEndGame()) * (round - 1)).milliseconds_ +
            Time::correct_str_to_milliseconds(time);
}

bool Time::operator<(const Time &other) const { return this->milliseconds_ < other.milliseconds_; }

bool Time::operator<(const std::string &other) const {
  return this->milliseconds_ < Time::correct_str_to_milliseconds(other);
}

bool Time::operator>(const Time &other) const { return this->milliseconds_ > other.milliseconds_; }

bool Time::operator>(const std::string &other) const {
  return this->milliseconds_ > Time::correct_str_to_milliseconds(other);
}

int Time::correct_str_to_milliseconds(const std::string &time) {
  if (!Time::str_is_correct(time))
    throw Exception("Time::correct_str_to_milliseconds() failed: " + std::string(time));
  long long int minute = stoll(time.substr(0, 2));
  long long int second = stoll(time.substr(3, 2));
  long long int millisecond = stoll(time.substr(6, 3));

  return minute * 60 * 1000 + second * 1000 + millisecond;
}

bool Time::str_is_correct(const std::string &time) {
  std::regex timePattern(R"(\d\d:\d\d:\d\d\d)");
  return regex_match(time, timePattern);
}

bool Time::operator==(const Time &other) const {
  return this->milliseconds_ == other.milliseconds_;
}

bool Time::operator==(const std::string &other) const {
  return this->milliseconds_ == Time::correct_str_to_milliseconds(other);
}

Time Time::operator*(int i) const {
  return Time(this->milliseconds_ * i);
}

Time Time::operator%(const Time &other) const {
  return Time(this->milliseconds_ % other.milliseconds_);
}

Time Time::operator+(const Time &other) const {
  return Time(this->milliseconds_ + other.milliseconds_);
}
