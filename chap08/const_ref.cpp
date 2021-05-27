#include <iostream>
#include <vector>
using namespace std;

void print(const vector<double>& v) {
    // pass by const reference
    cout << "{ ";   
    for(double x : v) cout << x << " ";
    cout << "}\n";
}

int main() {
    vector<double> v1(1000);
    print(v1);
}
