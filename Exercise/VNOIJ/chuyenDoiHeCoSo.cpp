// Input: Gồm 1 dòng chứa số nguyên n (1 <= n <= 10e15)
// Output: + Dòng thứ nhất ghi số N ở dạng hệ nhị phân
        // + Dòng thứ hai ghi số N ở dạng hệ bát phân
        // + Dòng thứ ba ghi số N ở dạng hệ thập lục phân 

// Input: 20
// Output:  10100
//          24
//          14

#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

using namespace std;
using ll = long long;

string convert(ll n, short k){
    if (n == 0) {
        return "0";
    }
    string res = "";
    while (n){
        ll du = n % k;
        n /= k;
        if (du < 10) {
            res = (char)(du + '0') + res;
        } else {
            res = (char)(du - 10 + 'A') + res;
        }
    }
    return res;
}

int main (int argc, char * argv[]){
    IOS;
    freopen("file/hecoso.inp", "r", stdin);
    freopen("file/hecoso.out", "w", stdout);
    ll n; cin >> n;
    cout << convert(n, 2) << endl;
    cout << convert(n, 8) << endl;
    cout << convert(n, 16) << endl;
    return 0;
}
