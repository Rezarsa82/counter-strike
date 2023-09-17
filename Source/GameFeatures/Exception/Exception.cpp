#include "Exception.h"

Exception::Exception(std::string message) : message_(std::move(message)) {}

std::string Exception::GetError() const {
  return message_;
}


