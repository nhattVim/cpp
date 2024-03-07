// Đếm số lần xuất hiện của các phần tử trong mảng, in ra màn hình 

// Input
// 8
// 1 2 2 1 3 5 1 -4
// Output:  1 4
//          2 1
//          3 1
//         -4 1
//          5 1

#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

using namespace std;

int main (int argc, char *argv[]) {
    IOS;   
    map<int, int> mp;
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        mp[x]++;
    }
    cout << endl;
    for (auto it : mp) {
        cout << it.first << " " << it.second << endl;
    }

    // Trong trường hợp in ra theo thứ tự xuất hiện trong mảng
    // IOS;
    // map<int, int> mp;
    // int n; cin >> n;
    // int a[n];
    // for (int i = 0; i < n; i++) {
    //     cin >> a[i];
    //     mp[a[i]]++;
    // }
    // cout << endl;
    // for (int i = 0; i < n; i++) {
    //     if (mp[a[i]] != 0) {
    //         cout << a[i] << " " << mp[a[i]] << endl;
    //         mp[a[i]] = 0;
    //     }
    // }

    return 0;
}
