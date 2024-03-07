// Bạn được cho 1 dãy số 1, 2, …, n trong đó thiếu 1 số. Nhiệm vụ của bạn là tìm số còn thiếu.
// Input: 
//     Dòng đầu tiên chứa số n
//     Dòng tiếp theo chứa n – 1 số phân biệt trong đoạn [1,n].
// Output: In ra số còn thiếu

// Input: 
// 5
// 2 3 1 5
// Output: 4

#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

using namespace std;

int main (int argc, char *argv[]) {
    IOS;
    freopen("file/002.inp", "r", stdin);
    freopen("file/002.out", "w", stdout);

    int n;
    cin >> n;

    vector<int> v(n);
    for (int i = 0; i < n - 1; i++) {
        cin >> v[i];
    }

    int sum = 0;
    for (int i = 0; i < n - 1; i++) {
        sum += v[i];
    }

    int sum2 = 0;
    for (int i = 1; i <= n; i++) {
        sum2 += i;
    }
    cout << sum2 - sum;

    return 0;
}
