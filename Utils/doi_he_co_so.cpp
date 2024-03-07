// Dổi hệ cơ số từ hệ 10 sang 2, 8, 16

#include <bits/stdc++.h>

using namespace std;

string convert(int n, int k){
    string res = "";
    while (n) {
        int du = n % k;
        n /= k;
        if (du < 10) {
            res = (char)(du + '0') + res;
        } else {
            res = (char)(du - 10 + 'A') + res;
        }
    }
    return res;
}

int main (int argc, char *argv[]) {
    int n, k;
    cout << "Nhap so: ";
    cin >> n;
    cout << "Nhap he co so: ";
    cin >> k;
    cout << convert(n,k);
    return 0;
}
