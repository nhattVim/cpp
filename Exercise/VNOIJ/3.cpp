// Cho 1 dãy gồm n số nguyên dương a1 a2 ... an được sắp xếp tăng dần và một số x. Hãy cho biết x xuất hiện ở vị trí nào trong dãy vừa cho
// Input: + Dòng đầu tiên chứa số nguyên n và x
//        + Dòng tiếp theo chứa n số nguyên a1 a2 ... an
// Output: In ra vị trí xuất hiện của x nếu không có in ra -1
// Example: 
//         + Input:    5 3             3 4
//                     1 2 3 4 5       1 3 6 10 15
//         + Output:   3               -1

#include <bits/stdc++.h>

using namespace std;

int main (int argc, char *argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, x;
    cin >> n >> x;

    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        if (v[i] == x) {
            cout << i + 1;
            return 0;
        }
    }

    cout << -1;
    return 0;
}

// #include <bits/stdc++.h>
// int i,n,k,x;
// signed main(){
//     std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
//     std::cin >> n >> k;
//     for(;i<n & x<k;i=i+1) std::cin >> x;
//     if(x!=k) i=-1;
//     std::cout<<i;
// }
