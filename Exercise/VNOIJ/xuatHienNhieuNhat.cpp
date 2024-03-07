// Cho một dãy gồm n số nguyên dương a1 a2 … an. Cho biết trong dãy vừa cho số nào xuất hiện nhiều nhất và xuất hiện bao nhiêu lần.
// Input:   + Dòng đầu tiên số nguyên n
//          + Dòng tiếp theo chứa n số nguyên a1 a2 … an
// Output: In ra x y với x là số xuất hiện nhiều nhất trong dãy trên và y là số lần xuất hiện. Nếu có nhiều số cùng số lần xuất hiện nhiều nhất như nhau thì in ra số bé nhất.

// Input:
// 5
// 1 2 3 1 2
// Output: 1 2

// Input:
// 6
// 1 2 3 4 2 2
// Output: 2 3

#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

using namespace std;

int main (int argc, char *argv[]) {
    IOS;
    int n, m = 0; 
    cin >> n;
    int a[n];
    map<int, int> mp;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        mp[a[i]]++;
        m = max(m, mp[a[i]]);
    }

    // for (int &x : a) {
    //     cin >> x;
    //     mp[x]++;
    //     d = max(d, mp[x]);
    // }

    for (auto x : mp) {
        if (x.second == m) {
            cout << x.first << " " << m << endl;
            break;
        }
    }
    return 0;
}
