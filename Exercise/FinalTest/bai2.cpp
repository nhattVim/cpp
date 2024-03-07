// Số thao tác giúp mảng tăng dần 2
// Cho dãy số A[] gồm N phần tử. Ở mỗi thao tác bạn có thể tăng các phần tử trong mảng lên 1 lượng là d đơn vị
// hãy xác định số thao tác tối thiểu sao cho mảng trở thành một dãy tăng chặt. Ví dụ 1 2 3 7 8 là một dãy 
// tăng chặt, nhưng dãy 1 2 2 7 8 không là một dãy tăng chặt. Ví dụ với mảng 1 3 3 4 và d = 2, ta cần thực hiện
// thao tác thứ nhất thêm d vào các phần tử thứ 3 trong mảng, mảng trở thành 1 3 5 2,ta tiếp tục thực hiện 2 
// thao tác thêm d vào phần tử thứ 4, mảng trở thành dãy tăng chặt 1 3 5 6
// Input: Dòng đầu tiên là số nguyên N và số d, Dòng tiếp theo gồm N số nguyên A[i] ( 1 <= N,d <= 10^4; 0 <= A[i] <= 10^6 )
// Output: In ra số thao tác tối thiểu cần thực hiện để mảng thành dãy tăng chặt 

// Input:
// 3 3
// 15 17 9
// Output: 3

#include <bits/stdc++.h>
#define IOS std::ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

using ll = long long;
using std::cout;
using std::cin;
using std::endl;
const ll size = 1e6;

int main (int argc, char *argv[]) {
    IOS;
    ll a[size], n, d;
    cin >> n >> d;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    ll res = 0;
    for (int i = 1; i < n; i++) {
        if (a[i] < a[i - 1]) {
            ll dv = (a[i - 1] - a[i] + 1);
            ll tt;
            if (dv % d == 0) {
                tt = dv / d;
            } else {
                tt = dv / d + 1;
            }
            res += tt;
            a[i] += tt * d;
        }
    }
    cout << res << endl;

    return 0;
}
