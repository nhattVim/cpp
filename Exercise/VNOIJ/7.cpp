// Input: Đọc từ file shh.inp gồm 1 số duy nhất N là số cần kiểm tra
// Output: Ghi ra file shh.oup 1 dòng duy nhất là YES nếu N là số hoàn hảo, ngược lại ghi NO
// Example:
//         shh.inp: 28
//         shh.out: YES

#include <bits/stdc++.h>
#define fu(i,a,b) for(int i = a; i < b; i++)

using namespace std;

const int MAX_N = 1e5;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("shh.inp", "r", stdin);
    freopen("shh.out", "w", stdout);

    int n, sum = 0;
    cin >> n;
    fu(i,1,n){
        if (n % i == 0) {
            sum = sum + i;
        }
    }
    if(sum == n) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    return 0;
}

// #include <bits/stdc++.h>
//
// using namespace std;
//
// int main() {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
//     int a;
//     int b = 1;
//     cin >> a;
//     for(int i = 2 ; i<=sqrt(a);i++){
//         if(a%i==0){
//             int c = a/i;
//             b=b+i+c;
//     }}
//     if(b==a) cout<<"YES";
//     else cout<<"NO";
//     return 0;
// }
