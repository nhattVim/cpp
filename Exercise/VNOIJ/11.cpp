// Tính n giai thừa

#include <bits/stdc++.h>

using namespace std;

int main (int argc, char *argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    short n;
    long long kq = 1;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        kq *= i;
    }
    cout << kq;
    return 0;
}

// #include <bits/stdc++.h>
//
// using namespace std;
//
// int main() {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
//     short n; 
// 	long long temp = 1;
//     cin >> n;
//     for (; n > 0 ; n--)
// 		temp *= n;
// 	cout << temp;
//     return 0;
// }
