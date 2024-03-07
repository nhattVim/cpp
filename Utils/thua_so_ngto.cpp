#include <bits/stdc++.h>
#define vi vector<int>
#define pb push_back
#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

using namespace std;

bool isPrime(int n){
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return n > 1;
}

void cach1(int n){
    for (int i = 2; i <= n; i++) {
        while (n % i == 0 && isPrime(i)) {
            cout << i;
            if (i != n) {
                cout << " x ";
            }
            n /= i;
        }
    }
}

void cach2(int n){
    for (int i = 2; i <= sqrt(n); i++){
        while (n % i == 0) {
            cout << i;
            if (i != n) {
                cout << " x ";
            }
            n /= i;
        }
    }

    if (n != 1) {
        cout << n;
    }
}

int main (int argc, char *argv[]) {
    IOS;
    int n; cin >> n;
    cach1(n); cout << endl;
    cach2(n);
    return 0;
}
