// Bạn được cung cấp 1 mảng gồm n phần tử và một số k.
// Bạn có chính xác k lần đảo dấu, mỗi lần đảo dấu được chọn 1 phần tử trong mảng và đảo dấu của nó (ai thành –ai).
// Hãy tìm các sao cho được tổng các số sau k lần đảo là lớn nhất
// Input:   Dòng đầu tiên chứa n và k (1 <= N <= 10e5; 0 <= k <= 10e5; |ai| <= 10e9)
//          Dòng tiếp theo chứa n số nguyên a1, s2, a3,..., an 
// Output:  Tổng các phần tử trong mảng sau k lần đảo dấu
// Example: 
//          Input:  3 1                             4 2
//                  4 6 2                           4 -6 2 3
//                
//          Output: 8                               11

#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

using namespace std;

int main (int argc, char *argv[]) {
    IOS;
    int n, k;
    long long sum = 0;
    cin >> n >> k;
    vector<int> v(n);
    
    for (int i = 0; i < v.size(); i++) {
        cin >> v[i];
    }

    sort(v.begin(), v.end());

    int i = 0;
    while (k) {
        if (v[i] < 0) {
            v[i] = -(v[i]);
        }
        else if (v[i] > 0) {
            if (k % 2 == 0) {
                k--;
            } else {
                v[i] = -(v[i]);
            }
        }
        i++;
        k--;
    }

    for (int x : v) {
        sum += x;
    }

    cout << sum;

    return 0;
}
