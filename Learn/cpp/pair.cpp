// [CTDL & GT]. Buổi 1. Vector, Iterator, Pair, Set Trong C++

#include <bits/stdc++.h>
#define fu(i,a,b) for (int i = a; i < b; i++)
#define fd(i,a,b) for (int i = a; i > b; i--)
#define sz(x) x.size()
#define f first
#define s second
#define vi vector<int>
#define rs resize
#define pb push_back
#define pii pair<int, int>
#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

using namespace std;
using ll = long long;

int main (int argc, char *argv[]) {
    IOS;
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    // khởi tạo pair
    // // pii p = make_pair(10, 20);
    // pii p = {10, 20};
    // cout << p.first << " " << p.second << endl;
    //
    // pii p1 = p;
    // cout << p1.first << " " << p1.second << endl;
    
    // // pair lồng nhau
    // pair<int, pair<int, int>> p;
    // p.first = 10;
    // p.second.first = 22;
    // p.second.second = 12;
    // cout << p.first << " " << p.second.first << " " << p.second.second << endl;

    // mảng pair
    // int n; cin >> n;
    // pii a[n];
    // for (int i = 0; i < n; i++) {
    //     cin >> a[i].first >> a[i].second;
    // }
    // for (auto x : a) {
    //     cout << x.first << " " << x.second << endl;
    // }
    
    // // vector pair 1
    // int n; cin >> n;
    // vector<pii> v(n);
    // for (int i = 0; i < n; i++) {
    //     cin >> v[i].first >> v[i].second;
    // }
    // for (auto x : v) {
    //     cout << x.first << " " << x.second << endl;
    // }

    // vector pair 2
    int n; cin >> n;
    vector<pii> v;
    for (int i = 0; i < n; i++) {
        int first, second;
        cin >> first >> second;
        v.push_back(make_pair(first, second));
    }
    for (auto x : v) {
        cout << x.first << " " << x.second << endl;
    }

    return 0;
}

// 5
// 8 1
// 2 9
// 3 6
// 8 1
// 2 0
