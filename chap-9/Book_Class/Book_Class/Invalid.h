#pragma once
#include <string>

class Invalid {
public:
	Invalid(std::string err);
	Invalid();
	std::string what();
private:
	std::string msg;
};