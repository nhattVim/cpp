// [CTDL & GT]. Buổi 1. Vector, Iterator, Pair, Set Trong C++

#include <bits/stdc++.h>
#include <ctime>
#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

using namespace std;
using ll = long long;

int main (int argc, char *argv[]) {
    IOS;
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    // vector<int> v(3, 100);
    // v.push_back(5);
    // v.push_back(2);
    // v.push_back(1);
    // v.push_back(4);
    // cout << v.size() << endl;
    // cout << v[2] << endl;
    // for (int x : v) {
    //     cout << x << " ";
    // }
    // cout << endl;
    // for (int i = 0; i < v.size(); i++) {
    //     cout << v[i] << " ";
    // }
    // cout << endl;
    // for (int i = v.size() - 1; i >= 0; i--) {
    //     cout << v[i] << " ";
    // }
    // cout << endl;
    //
    // // iterator
    // // v.begin()    :trỏ đến phần tử đầu tiên của vector 
    // // v.end()      :trỏ đến ô nhớ sau phần tử cuối cùng trong vector
    // // v.rbengin()  :trỏ đến phần tử cuối cùng của vector
    // // v.rend()     :trỏ đến ô nhớ trước phần tử đầu tiên trong vector
    // // có thể dùng auto để thay thế vecto<int>::iterator, vd: auto it = v.begin()
    // vector<int>::iterator it = v.begin();
    // cout << *it << endl;
    // ++it;
    // it += 3;
    // cout << *it << endl;
    // --it;
    // cout << *it << endl;
    // it = v.end();
    // cout << *it << endl;
    //
    // // Duyệt vector bằng iterator
    // vector<int>::iterator it1;
    // for (it1 = v.begin(); it1 != v.end(); ++it1) {
    //     cout << *it1 << " ";
    // }

    // khai báo vector
    // c1:
    // vector<int> v;
    // int n; cin >> n;
    // for (int i = 0; i < n; i++) {
    //     int tmp; cin >> tmp;
    //     v.push_back(tmp);
    // }
    // for (int x : v) cout << x << " ";

    // c2:
    vector<int> v(6);
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    for (int x : v) cout << x << " ";
    cout << endl;

    // chèn thông qua iterator
    v.insert(v.begin() + 2, 100);
    for (int x : v) cout << x << " ";
    cout << endl;

    // xóa thông qua iterator
    v.erase(v.begin() + 1);
    for (int x : v) cout << x << " ";
    cout << endl;

    // xóa phần tử cuối
    v.pop_back();
    for (int x : v) cout << x << " ";
    cout << endl;

    // asign(): gán các phần tử trong vector với cùng một giá trị, assign(số phần tử, value)
    v.assign(10, 22);
    for (int x : v) cout << x << " ";
    cout << endl;

    // resize(): thay đổi kích thước vector, resize(n)
    v.resize(5);
    for (int x : v) cout << x << " ";
    cout << endl;

    return 0;
}
