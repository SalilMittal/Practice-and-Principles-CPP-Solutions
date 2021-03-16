/* Write a program that converts from Celsius to Fahrenheit and from
Fahrenheit to Celsius (formula in §4.3.3). Use estimation (§5.8) to see
if your results are plausible.*/

#include <iostream>
#include <vector>
using namespace std;

double convert(double t, char u)
{
    switch(u) {
        case 'C': case 'c':
            if(t < -273.15) throw runtime_error("Temperature below abs zero");
            return 1.8 * t + 32;
            break;
        case 'F': case 'f':
            if(t < -460) throw runtime_error("Temperature below abs zero");
            return (t - 32) * 1.8;
            break;
        default:
            throw runtime_error("Invalid Unit");
            break;
    }
}

int main()
{
    try {
        double t = 0;
        cin >> t;
        char u;
        cin >> u;
        double conv = convert(t, u);
        cout << conv;
    } catch(runtime_error& e) {
        cerr << e.what();
    }
}