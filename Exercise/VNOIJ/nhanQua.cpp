// Bạn có muốn nhận quà không. Nếu có thì hãy in ra l want!!!!!!..!!! với n dấu ! ở phía sau
// Input: số nguyên n
// Output: in ra l want!!!!!!..!!! với n dấu ! ở phía sau

// Input: 5
// Output: l want!!!!!

#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

using namespace std;

int main (int argc, char *argv[]) {
    IOS;
    int n; cin >> n;
    cout << "l want";
    for (int i = 0; i < n; i++) {
        cout << "!";
    }
    return 0;
}
