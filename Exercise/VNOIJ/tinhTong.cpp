// Cho N số nguyên a(i). Hãy tính tổng a(1) + a(2) + a(3) + ... + a(n). Giới hạn n <= 10^7, ai<= 10^9
// Input:  + Dòng thứ nhất chứa số nguyên N
//         + Dòng tiếp theo chứa N số nguyên a(1) a(2) a(3) ... a(n) cách nhau bới dấu cách
// Output: ghi ra tổng a(1) + a(2) + a(3) + ... + a(n)

// Input:   
// 3
// 3 4 1
// Output: 8

#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

using namespace std;

int main (int argc, char *argv[]) {
    IOS;
    int n;
    long long sum = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        sum += temp;
    }
    cout << sum << endl;
    return 0;
}
