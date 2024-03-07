#include <bits/stdc++.h>

using namespace std;

bool so_nguyen_to(int n){
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return n > 1;
}

int main (int argc, char *argv[]) {
    int n;
    cin >> n;
    if (so_nguyen_to(n)) {
        cout << "true";
    } else {
        cout << "false";
    }

    return 0;
}

