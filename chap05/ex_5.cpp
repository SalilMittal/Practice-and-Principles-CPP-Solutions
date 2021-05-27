/*  Add to the program so that it can also convert from Kelvin to Celsius.
 */

#include <iostream>
#include <vector>
using namespace std;

double convert(double t, char u)
{
    switch(u) {
        case 'C': case 'c':
            if(t < -273.15) throw runtime_error("Temperature below abs zero");
            return t + 273.15;
            break;
        case 'K': case 'k':
            if(t < 0) throw runtime_error("Temperature below abs zero");
            return t - 273.15;
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