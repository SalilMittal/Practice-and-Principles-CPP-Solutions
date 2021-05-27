/* Do exercise 3 again, but this time handle the error inside ctok().
 */

#include <iostream>
#include <vector>
using namespace std;

double ctok(double c) // converts Celsius to Kelvin
{
    if(c < -273.15) throw runtime_error("Temperature below 273K");
    int k = c + 273.15;
    return k;
}

int main()
{
    try {
        double c = 0; // declare input variable
        cin >> c; // retrieve temperature to input variable
        double k = ctok(c); // convert temperature
        cout << k << '\n' ; // print out temperature
    } catch(runtime_error& e) {
        cerr << e.what();
    }
}