#include <bits/stdc++.h>

using namespace std;

int main (int argc, char *argv[]) {
    int n, temp = 0, sum = 0;
    cin >> n;
    while (n) {
        temp = n % 10;
        n /= 10;
        sum += temp;
    }
    cout << sum;
    return 0;
}
