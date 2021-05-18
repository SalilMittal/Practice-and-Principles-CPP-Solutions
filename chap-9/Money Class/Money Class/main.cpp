// Money Class.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Money.h"

int main()
{
    std::cout << "Bank Input: \n";
    Money mm{};
    std::cin >> mm;

    std::cout << "Second Input: \n";
    Money mm2{};
    std::cin >> mm2;

    std::cout << mm+mm2;
}
