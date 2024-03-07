// Có bao nhiêu số từ a đến b mà tổng các chữ số của nó là số nguyên tố
// Input: hai số a, b (0 < a <= b <= 10e8)
// Input: 7 20
// Output: 6

#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

using namespace std;

bool ngto(int n){
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return n > 1;
}

int tong_cac_chu_so(int n){
    int sum = 0;
    while (n) {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

int main (int argc, char *argv[]) {
    IOS;
    freopen("file/tnt.inp", "r", stdin);
    freopen("file/tnt.out", "w", stdout);
    int a, b, d = 0; cin >> a >> b;
    for (int i = a; i <= b; i++) {
        if (ngto(tong_cac_chu_so(i))) {
            d++;
        }
    }
    cout << d;
    return 0;
}

