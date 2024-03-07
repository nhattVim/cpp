// Input:  - Dòng đầu tiên chứa t là số bộ test
//         - t dòng tiếp theo mỗi dòng chứa 1 số nguyên N
// Output: In ra t dòng là số Fibonacci tương ứng

// Input: 
// 4
// 3
// 2
// 5
// 7

// Output:
// 2
// 1
// 5
// 13

#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio;cin.tie(NULL);cout.tie(NULL)

using namespace std;
using ll = long long;

vector<ll> v;

ll Fibonacci(int n){
    if (n == 1 || n == 2) {
        return 1;
    } 

    if (v[n] != -1) {
        return v[n];
    }

    v[n] = Fibonacci(n - 1) + Fibonacci(n - 2);
    return v[n];
}

int main (int argc, char *argv[]){
    int t; cin >> t;
    
    while (t) {
        ll n; cin >> n;
        v.assign(n + 1, -1);
        cout << Fibonacci(n) << endl;
        t--;
    }

    return 0;
}
