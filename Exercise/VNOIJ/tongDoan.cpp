// Cho một dãy số nguyên. Viết chương trình tính tổng đoạn từ u đến v của dãy số nguyên a.
// Input:  + Dòng đầu tiên là số nguyên n và m (m < 10^7). Dòng tiếp theo chứa n số nguyên ai(<10^9), các số cách nhau bởi dấu cách
//         + m dòng tiếp theo, mỗi dòng chứa 2 số ui vi
// Output: In ra m dòng, dòng thứ i là tổng đoạn con từ ui đến vi

// Input:
// 5 3
// 0 1 2 3 4 5
// 0 2
// 1 1
// 1 4
// Output:
// 3
// 1
// 10

#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

using namespace std;

int main() {
    IOS;

    long long n, m, sum = 0;
    cin >> n >> m;

    vector<long long> a(n + 2, 0);

    for (int i = 1; i <= n + 1; i++) {
        cin >> a[i];
        sum += a[i];
        a[i] = sum;
    }

    for (int x : a) {
        cout << x << " ";
    }
    cout << endl;

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        cout << a[v + 1] - a[u] << endl;
    }

    return 0;
}
