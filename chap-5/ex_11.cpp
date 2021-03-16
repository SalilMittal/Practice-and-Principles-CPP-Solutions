/* Write a program that writes out the first so many values of the
Fibonacci series, that is, the series that starts with 1 1 2 3 5 8 13 21
34. The next number of the series is the sum of the two previous ones.
Find the largest Fibonacci number that fits in an int.
 */

#include <iostream>
#include <algorithm>
#include <limits.h>
using namespace std;

int main() {
    int n, t1 = 0, t2 = 1, nextTerm = 1;

    cout << "Enter the number of terms: ";
    cin >> n;

    cout << "Fibonacci Series: ";
    cout << "1 ";
    for (int i = 1; i <= n; ++i) {
        nextTerm = t1 + t2;
        t1 = t2;
        t2 = nextTerm;
        if(nextTerm < 0) break;
        cout << nextTerm << " ";
    }
    return 0;
}