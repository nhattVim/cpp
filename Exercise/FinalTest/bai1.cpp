// Thừa số nguyên tố có số mũ lớn nhất
// Bạn hãy tìm thừa số nguyên tố có số mũ lớn nhất của số nguyên N, nếu có nhiều thừa số nguyên tố có cùng
// số mũ lớn nhất hãy chọn số nhỏ hơn. Ví dụ N = 60 = 2^2 * 3^1 * 5^1 thì đáp án là 2
// Input: Dòng đầu tiên chứa một số nguyên N ( 2 <= N <= 10^12)
// Output: In ra thừa số nguyên tố kèm với số mũ

// Input: 88
// Output: 2 3

#include <bits/stdc++.h>
#define IOS std::ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

using ll = long long;
using std::cout;
using std::cin;
using std::endl;

void solve(ll n) {
    ll res, mu = 0;
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) {
            int d = 0;
            while (n % i == 0) {
                d++;
                n /= i;
            }
            if (d > mu) {
                mu = d;
                res = i;
            }
        }
    }
    if (n != 1) {
        if (mu == 0) {
            mu = 1;
            res = n;
        }
    }
    cout << res << " " << mu << endl;
}

int main (int argc, char *argv[]) {
    IOS;
    ll n; cin >> n;
    solve(n);
    return 0;
}
