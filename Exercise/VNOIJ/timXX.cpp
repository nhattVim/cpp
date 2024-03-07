// Cho một số nguyên a và một số x. Hãy cho biết x có xuất hiện trong a hay không, nếu có thì cho biết các vị trí xuất hiện của x
// (tính từ 0 từ trái sang phải).
// Input: Dòng đầu tiên là số nguyên n và x (n < 10^7). Dòng tiếp theo chứa số nguyên ai (ai < 10^9), các số cách nhau bởi dấu cách
// Output: In ra các vị trí xuất hiện của x, nếu không có thì in ra -1

// Input:    
// 6 3                 
// 0 1 2 3 4 3
// Output: 3 5                 

// Input:    
// 5 7
// 0 1 2 3 4 3         
// Output: -1

#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

using namespace std;

int main() {
    IOS;
    int n, x, flag = 0;
    cin >> n >> x;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] == x) {
            cout << i << " ";
            flag++;
        }
    }

    if (flag == 0) {
        cout << -1;
    }

    return 0;
}
