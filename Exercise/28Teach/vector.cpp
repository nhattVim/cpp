// [CTDL & GT]. Buổi 1. Vector, Iterator, Pair, Set Trong C++

#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

using namespace std;
using ll = long long;

int main (int argc, char *argv[]) {
    IOS;
    int n; cin >> n;
    vector<int> v;
    for (int i = 0; i < n; i++) {
        int tt; cin >> tt;
        if (tt == 1) {
            int x; cin >> x;
            v.push_back(x);
        } else {
            if (v.empty() == false) {
                v.pop_back();
            }
        }
    }
    if (v.empty()) {
        cout << "EMPTY\n";
    } else {
        for (int x : v) {
            cout << x << " ";
        }
    }
    return 0;
}
