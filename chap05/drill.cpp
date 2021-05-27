#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
try {
    cout << "Success!\n";
    cout << "Success!\n";
    cout << "Success" << "!\n";
    cout << "success" << '\n';
    // string res = "7";
    // vector<string> v(10);
    // v[5] = res;
    // cout << "Success!\n";

    // vector<int> v(10); v[5] = 7; 
    // if (v[5] != 7) cout << "Success!\n";
    
    if (true) 
        cout << "Success!\n";
    else 
        cout << "Fail!\n";

    // bool c = false; if (!c) cout << "Success!\n"; else cout << "Fail!\n";

    // string s = "ape"; bool c = "fool" > s; 
    // if (c) cout << "Success!\n";

    // string s = "ape"; if (s!="fool") cout << "Success!\n";
    // string s = "ape"; if (s!="fool") cout << "Success!\n";
    // string s = "ape"; if (s != "fool") cout << "Success!\n";

    vector<char> v(5); for (int i = 0; i < v.size(); ++i) ; cout << "Success!\n";

    // string s = "Success!\n"; for (int i = 0; i < 6; ++i) cout << s[i];
    // if (true) cout << "Success!\n"; else cout << "Fail!\n";

    int x = 2000; char c = x; if (int(c) == 2000) cout << "Success!\n";
    
    string s = "Success!!\n"; for (int i=0; i < 10; ++i) cout << s[i];

    vector<int> v(5); for (int i=0; i < v.size(); ++i) ; cout << "Success!\n";
    int i=0; int j = 9; while (i<10) ++i; if (j == i) cout << "Success!\n";

    int x = 2; double d = 5 / 2 + 2; if (d==2*x+0.5) cout << "Success!\n";
    string s = "Success!\n"; for (int i=0; i<=10; ++i) cout << s[i];
    int i=0; int j = 0; while (i<10) ++i; if (j<i) cout << "Success!\n";

    int x = 4; double d = 5/(x-2) + 6; if (d=2*x+0.5) cout << "Success!\n";
    cout << "Success!\n";
    
    return 0;
}
catch (exception& e) {
    cerr << "error: " << e.what() << '\n';
    return 1;
}
catch (...) {
    cerr << "Oops: unknown exception!\n";
}
