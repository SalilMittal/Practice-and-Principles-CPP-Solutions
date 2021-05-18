#pragma once
#include "Invalid.h"
#include <string>

// Invalid Class
Invalid::Invalid(std::string err) : msg{ err } {}

Invalid::Invalid() : msg{ "Invalid Exception Thrown" } {}

std::string Invalid::what() { return msg; }