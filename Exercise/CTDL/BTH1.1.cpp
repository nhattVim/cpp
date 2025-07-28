#include <bits/stdc++.h>
using namespace std;

// -------------------- Fast IO --------------------
void fastIO() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

// -------------------- Main Logic --------------------
void solve() {
    int myNum = 5;
    float myFloatNum = 5.99;
    double myDoubleNum = 9.98;
    char myLetter = 'D';
    bool myBool = true;
    string myString = "Hello";

    cout << "int: " << myNum << endl;
    cout << "float: " << myFloatNum << endl;
    cout << "double: " << myDoubleNum << endl;
    cout << "char: " << myLetter << endl;
    cout << "bool: " << myBool << endl;
    cout << "string: " << myString << endl;
}

int main() {
    fastIO();
    int t = 1;
    // cin >> t; // Uncomment if multiple test cases
    while (t--)
        solve();
    return 0;
}
