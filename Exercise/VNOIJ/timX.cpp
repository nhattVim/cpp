// nhập vào một dãy số nguyên và 1 số x. Hãy cho biết x có xuất hiện trong a hay không, nếu có thì bao nhiêu lần xuất hiện
// Input: Dòng đầu tiên là số nguyên n và x (n<10^7). Dòng tiếp theo chứa số nguyên a[i] (<10^9), các số cách nhau bởi dấu cách
// Ouput: In ra số lần xuất hiện của x, nếu không có thì in ra -1

// Input:  
// 6 3
// 0 1 2 3 4 3 
// Ouput:  2

// Input:  
// 6 7
// 0 1 2 3 4 3
// Ouput:  -1

#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

using namespace std;

int main(){
    IOS;
    freopen("file/timx.inp", "r", stdin);
    freopen("file/timx.out", "w", stdout);
    int n, x; cin >> n >> x;
    map<int, int> mp;
    for (int i = 0; i < n; i++) {
        int temp; cin >> temp;
        if (x == temp) {
            mp[temp]++;
        }
    }

    if(mp[x] == 0) {
        cout << -1 << endl;
    } else {
        cout << mp[x] << endl;
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
//     int n,temp,x,dem = 0;
//     cin >> n >> x;
//     for(int i = 0; i < n; i++){
//     	cin >> temp;
//     	if(temp == x)
//     		dem++;
// 	}
// 	if(dem)
// 		cout << dem;
// 	else
// 		cout << -1;
//     return 0;
// }
