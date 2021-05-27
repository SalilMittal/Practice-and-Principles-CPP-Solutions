/* 
    * Useful for not copying large amounts of data
    * Both reading and writing an element of complicated expression
    * Eg:
    * double complicated_element = v[sqrt(4) - 1][0];
    * complicated_element /= 2;
    * now {v[sqrt(4) - 1][0]} is halved
    * Modifying value **without copying**
    * 
 */

#include <iostream>
#include <vector>
using namespace std;

void swap(double& d1, double& d2) {
    double temp = d1;
    d1 = d2;
    d2 = temp;
}

void init(vector<double>& v) {
    for(int i = 0; i < v.size(); i++) v[i] = i;
}

int main() {
    vector<double> vd1(10);
    for(double x : vd1) cout << x << " ";
    cout << "\n";
    init(vd1);
    for(double x : vd1) cout << x << " ";
    cout << "\n";
    double x = 1;
    double y = 2;
    cout << "x == " << x << " y== " << y << '\n'; // write: x==1 y==2
    swap(x, y); // already part of std lib
    cout << "x == " << x << " y== " << y << '\n'; // write: x==2 y==1
}