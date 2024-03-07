// Phân tích thừa số nguyên tố. Yêu cầu: Xuất các số nguyên tố theo thứ tự giảm dần và xuất dấu nhân "x" có khoảng trắng hai bên
// Input:  + Dòng thứ nhất: số lượng trường hợp cần kiểm tra 
//         + Các dòng còn lại: số nguyên dương n < 10000000
// Output: Xuất các kết quả cho từng trường hợp kiểm tra 

// Input:
// 4
// 999
// 1234567
// 823
// 3

// Output:
// 37 x 3 x 3 x 3
// 9721 x 127
// 823
// 3

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

void thuaSoNgto(int n){
    vi v;
    for (int i = 2; i <= n; i++) {
        while (n % i == 0 && isPrime(i)) {
            v.pb(i);
            n /= i;
        }
    }

    for (int i = v.size() - 1; i >= 0; i--) {
        cout << v[i];
        if (i > 0) {
            cout << " x ";
        }
    }
}

int main (int argc, char *argv[]) {
    IOS;
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        thuaSoNgto(n);
        cout << endl;
    }
    return 0;
}
