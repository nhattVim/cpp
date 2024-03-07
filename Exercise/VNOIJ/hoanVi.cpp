// Cho số nguyên n, in ra các hoán vị từ 1 đến n mỗi hoán vị trên 1 dòng
// Input: Gồm 1 dòng duy nhất chứa số nguyên n
// Output: In ra các hoán vị từ 1 đến n theo thứ tự từ điển tăng dần, mỗi hoán vị trên 1 dòng. Các số cách nhau bởi dấu cách

// Input: 3
// Output:  1 2 3 
//          1 3 2 
//          2 1 3
//          2 3 1
//          3 1 2
//          3 2 1

#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

using namespace std;

int main() {
    IOS;
    freopen("file/hoanvi.inp", "r", stdin);
    freopen("file/hoanvi.out", "w", stdout);
    int n; cin >> n;
    int arr[n];

    for (int i = 0; i < n; i++) {
        arr[i] = i + 1;
    }

    do {
        for (int i = 0; i < n; ++i) {
            cout << arr[i] << " ";
        }
        cout << endl;
    } while (next_permutation(arr, arr + n));

    return 0;
}
