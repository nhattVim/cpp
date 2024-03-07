#include <bits/stdc++.h>

using namespace std;

long decimalToBinary(int num) {
    long binarynum = 0;
    int rem, temp = 1;

    while (num != 0) {
        rem = num % 2;
        num = num / 2;
        binarynum = binarynum + rem * temp;
        temp = temp * 10;
    }
    return binarynum;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("hocoso.inp", "r", stdin);
    freopen("hecoso.out", "w", stdout);

    int n;
    cin >> n;
    cout << decimalToBinary(n) << endl;
    cout << oct << n << endl;
    cout << hex << n << endl;

    return 0;
}
