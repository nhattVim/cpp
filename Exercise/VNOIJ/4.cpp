// Vẽ tam giác vuông có cạnh góc vuông n
// Input: n
// Output: tam giác vuông có cạnh n gồm các dấu *
// Example:    Input: 5
//             Output:      *
//                         **
//                        ***
//                       ****
//                      *****

#include <bits/stdc++.h>
#define fu(i,a,b) for(int i = a; i < b; i++)

using namespace std;

int main (int argc, char *argv[]) {
    int n;
    cin >> n;
    fu(i,1,n+1) {
        fu(j,1,n+1) {
            if (j <= n-i) {
                cout << " ";
            } else {
                cout << "*";
            }
        }
        cout << endl;
    }
    return 0;
}

// #include <bits/stdc++.h>
// using namespace std;
//
// int main()
// {
//     int chieuCao;
//     cin >> chieuCao;
//     for(int i = 1; i <= chieuCao; i++) {
//
//         for(int j = 1; j <= i; j++) {
//
//             cout << "*";
//         }
//         cout << endl;
//     }
//     system("pause");
//     return 0;
// }
