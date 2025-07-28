#include <bits/stdc++.h>
using namespace std;

// -------------------- Aliases --------------------
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pii> vpii;
typedef vector<pll> vpll;

// -------------------- Macros --------------------
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define pb push_back
#define F first
#define S second
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define ROF(i, a, b) for (int i = (a); i >= (b); --i)

// -------------------- Fast IO --------------------
void fastIO() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

// -------------------- Debug --------------------
#ifdef LOCAL
#define debug(x) cerr << #x << ": " << x << endl;
#else
#define debug(x)
#endif

// -------------------- Utility Functions --------------------
template <typename T>
void printVec(const vector<T> &v, const string &sep = " ") {
    for (auto &x : v)
        cout << x << sep;
    cout << '\n';
}

template <typename T> void readVec(vector<T> &v, int n) {
    v.resize(n);
    for (int i = 0; i < n; ++i)
        cin >> v[i];
}

// -------------------- Main Logic --------------------
void solve() {
    // Write your solution for each test case here
}

int main() {
    fastIO();
    int t = 1;
    // cin >> t; // Uncomment if multiple test cases
    while (t--)
        solve();
    return 0;
}
