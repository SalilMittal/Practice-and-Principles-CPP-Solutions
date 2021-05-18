#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <map>

class Money {
public:
	Money(long double amount, std::string currency);
	Money();
	std::vector<std::string> getAccepted() const { return accepted; }
	std::string getCurrency() const { return currency; }
	std::map<std::string, double> getFactors() const { return conversionFactor; };
	std::map<std::string, std::string> getSymbols() const { return symbols; };

	long double getAmt() const { return amt; }
private:
	long double amt;
	std::string currency;
	std::vector<std::string> accepted {"USD", "INR", "EUR", "DKK"};
	
	// Currency to US Dollar
	std::map<std::string, double> conversionFactor{
		{"USD", 1},
		{"INR", 0.014},
		{"EUR", 1.22},
		{"DKK", 0.16}
	};

	std::map<std::string, std::string> symbols{
		{"USD", "$"},
		{"INR", "₹"},
		{"EUR", "€"},
		{"DKK", "Kr"}
	};
};

std::istream& operator>>(std::istream& is, Money& mm);
std::ostream& operator<<(std::ostream& os, const Money& mm);
Money operator+(const Money& a, const Money& b);
Money operator*(const Money& a, const Money& b);
Money operator/(const Money& a, const Money& b);
