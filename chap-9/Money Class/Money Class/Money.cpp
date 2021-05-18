#include <iostream>
#include <vector>
#include <map>
#include <string>
#include "Money.h"

Money::Money() : amt{ 100 }, currency{ "USD" } {}

Money::Money(long double amount, std::string curr) : currency{curr}  {
    if (std::find(accepted.begin(), accepted.end(), curr) == accepted.end()) {
        throw std::runtime_error("Invalid currency");
    }

    if (currency == "USD") amount *= 100;
    amt = amount;
}

std::istream& operator>>(std::istream& is, Money& mm) {
    std::cout << "Accepted currencies [USD, EUR, INR, DKK]\n";
    std::cout << "Enter currency: ";

    std::string currency = "";
    std::cin >> currency;
    const std::vector<std::string> accepted = mm.getAccepted();

    if (std::find(accepted.begin(), accepted.end(), currency) == accepted.end()) {
        is.clear(std::ios_base::failbit);
        return is;
    }

    long double amount = 0;
    std::map<std::string, std::string> symbols = mm.getSymbols();
    std::cout << "Enter amount: " << symbols[currency];
    std::cin >> amount;

    mm = Money(amount, currency);

    return is;
}

std::ostream& operator<<(std::ostream& os, const Money& mm) {
    long double amt = mm.getAmt();
    const std::string currency = mm.getCurrency();
    if (currency == "USD") amt /= 100;
    return os << currency << amt;
}

Money operator+(const Money& a, const Money& b) {
    Money m{};
    long double amtA = a.getAmt();
    long double amtB = b.getAmt();
    std::map<std::string, double> conversionFactors = a.getFactors();

    if (a.getCurrency() == "USD") amtA /= 100;
    if (b.getCurrency() == "USD") amtB /= 100;

    long double final = 0;
    std::string finalCurr;
    const std::string currA = a.getCurrency();
    const std::string currB = b.getCurrency();

    if (currA == currB) {
        finalCurr = currA;
    } else {
        finalCurr = "USD";
        amtA *= conversionFactors[currA];
        amtB *= conversionFactors[currB];
    }
    
    final = amtA + amtB;
    return Money { final, finalCurr };
}

Money operator*(const Money& a, const Money& b) { throw std::runtime_error("Invalid Operation"); }
Money operator/(const Money& a, const Money& b) { throw std::runtime_error("Invalid Operation"); }