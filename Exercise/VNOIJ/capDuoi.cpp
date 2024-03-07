// Cho biết quan hệ của các nhân viên trong 1 công ty. Hãy cho biết mỗi nhân viên có bao nhiêu cấp dưới.
// Input: 
//     - Dòng đầu tiên chứa số n là số nhân viên. Các nhân viên được đánh số từ 1 đến n. Trong đó giám đốc là nhân viên 1
//     - Dòng tiếp theo chứa n-1 số, số thứ i ghi số hiệu nhân viên cấp trên trực tiếp của nhân viên i + 1
// Output: In ra n số nguyên, số thứ i tương ứng với số lượng nhân viên cấp dưới của nhân viên thứ i

// Input:
// 5
// 1 1 2 3
// Output:
// 4 1 1 0 0

#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

using namespace std;

vector<vector<int>> g;
vector<int> cnt;

void dfs(int u) {
    cnt[u] = 0;
    for (int v : g[u]) {
        dfs(v);
        cnt[u] += (1 + cnt[v]);
    }
}

int main() {
    IOS;
    int n; cin >> n;

    g.resize(n + 1);
    cnt.resize(n + 1);

    for (int i = 2; i <= n; ++i) {
        int m;
        cin >> m;
        g[m].push_back(i);
    }

    dfs(1);

    for (int i = 1; i <= n; ++i) {
        cout << cnt[i] << " ";
    }

    return 0;
}
