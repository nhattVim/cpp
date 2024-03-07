// factorial : giai thừa
#include <bits/stdc++.h>

using namespace std;

int factorial(int n){
    if (n>1) {
        return n*factorial(n-1);
    }
    return 1;
}

int main (int argc, char *argv[]) {
    int n;
    cin >> n;
    cout << factorial(n) << endl;
    return 0;
}
