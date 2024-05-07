#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

using namespace std;

int main() {
    IOS;
    freopen("file/005.inp", "r", stdin);
    freopen("file/005.out", "w", stdout);

    int n, d = 0;
    cin >> n;
    int arr[n];

    for (int i = 0; i < n; i++) {
        arr[i] = i + 1;
    }

    do {
        bool isBeautiful = true;
        for (int i = 0; i < n; i++) {
            if (arr[i] - arr[i - 1] == 1 || arr[i] - arr[i + 1] == 1) {
                isBeautiful = false;
                break;
            }
        }

        if (isBeautiful) {
            d++;
            for (int j = 0; j < n; j++) {
                cout << arr[j] << " ";
            }
            return 0;
        }

    } while (next_permutation(arr, arr + n));

    if (d == 0) {
        cout << "-1";
    }
    
    return 0;
}
