// liet ke so nhi phan
// Cho so tu nhien n. Hay in ra tat ca cac so nhi phan tu 1 den n
// Input:
//     + Dong dau tien ghi so luong test T (T<=100)
//     + Moi test la 1 so tu nhien ghi tren 1 dong (n<=10000)
// Output:
//     Dua ra ket qua dung tren moi dong
// Vi du:
//     Input           |           Output
//     2               |
//     2               |           1 10
//     3               |           1 10 11 100 101

#include <bits/stdc++.h>
#include <vector>

using namespace std;

vector<string> s;

void init() {
    queue<string> q;
    q.push("1");
    int cnt = 1;
    s.push_back("1");
    while (s.size() < 10000) {
        string top = q.front();
        q.pop();
        s.push_back(top + "0");
        s.push_back(top + "1");
        q.push(top + "0");
        q.push(top + "1");
    }
}

int main (int argc, char *argv[]) {
    init();
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        for (int i = 0; i < n; i++) {
            cout << s[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
