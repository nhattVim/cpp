// Cho 1 dãy n số nguyên. Bạn hãy thay đổi các số trong dãy sao cho được dãy tăng. Dãy được gọi là dãy tăng nếu phần tử phía sau lớn hơn
// hoặc bằng phần tử phía trước. Mỗi lần tăng 1 phần tử lên 1 đơn vị. Cho biết số lần tăng ít nhất các phần tử để được dãy tăng.
// Input: 
//     Dòng đầu tiên chứa số n (1 <= n <= 2.10^5)
//     Dòng tiếp theo chứa n số nguyên ai (1 <= ai <= 10^9)
// Output: In ra số lần tăng ít nhất

// Input:
// 5
// 3 2 5 1 7
// Output: 5

#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

using namespace std;

int main() {
    IOS;
    freopen("file/004.inp", "r", stdin);
    freopen("file/004.out", "w", stdout);
    int n;
    cin >> n;

    vector<long long> v(n);

    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    long long moves = 0;

    for (int i = 1; i < n; i++) {
        if (v[i] < v[i - 1]) {
            moves += (v[i - 1] - v[i]);
            v[i] = v[i - 1];
        }
    }

    cout << moves << endl;

    return 0;
}
