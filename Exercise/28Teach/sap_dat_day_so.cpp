// #8.1 [C++]. Hướng Dẫn Giải Bài Tập Mảng 1 Chiều Trong Ngôn Ngữ Lập Trình C++
//
// Sắp đặt dãy 
// Cho mảng a[] gồm n phần tử. Nhiệm vụ của bạn là sắp đặt lại các phần tử của mảng sao cho a[i] = i. Nếu phần tử a[i] có giá trị khác i, hãy ghi vào -1.
// Ví dụ với mảng a[] = {-1, -1, 6, 1, 9, 3, 2, -1, 4, -1} ta có kết quả a[] = {-1, 1, 2, 3, 4, -1, 6, -1, -1, 9}
// Input:   + Dòng đầu tiên chứa số lượng bộ test T
//          + Những dòng kế tiếp đưa vào T bộ test. Mỗi bộ test gồm hai dòng: dòng đầu tiên đưa vào n là số phần tử của mảng a[], dòng kế tiếp đưa vào n số a[i] của mảng
//          + T, n, a[i] thỏa mãn ràng buộc 1 <= T <= 100; 1 <= n <= 10^7; 1 <= a[i] <= 10^18

// Input
// 2
// 10
// -1 -1 6 1 9 3 2 -1 4 -1
// 6
// 0 -3 1 -2 3 -4
//
// Output
// -1 1 2 3 4 -1 6 -1 -1 9
// 0 1 -1 3 -1 -1

#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main (int argc, char *argv[]) {
    int TC; cin >> TC;      // TC = test case
    while (TC--) {
        int n; cin >> n;
        map<ll, bool> mp;
        for (int i = 0; i < n; i++) {
            ll x; cin >> x;
            mp[x] = true;
        }
        for (int i = 0; i < n; i++) {
            if (mp[i]) {
                cout << i << " ";
            } else {
                cout << "-1 ";
            }
        }
        cout << endl;
    }

    return 0;
}
