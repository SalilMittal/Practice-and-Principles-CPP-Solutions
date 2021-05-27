#include <iostream>
#include <string>
#include <vector>
#include "Chrono.h"

int main()
{
    using namespace Chrono;
    Date today{ 1978, Month::Jun, 30 };
    Date tomorrow = today;
    tomorrow.add_day(1);
 
    std::cout << today << "\n" << tomorrow;
}