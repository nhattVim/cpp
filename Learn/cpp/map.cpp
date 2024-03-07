// #16 [C++]. Cấu Trúc Dữ Liệu Map Trong C++ | Multimap | Unordered_map

#include <bits/stdc++.h>

using namespace std;

int main (int argc, char *argv[]) {
    // (key, value) O(Log(n))
    map<int, int> mp;
    mp[100] = 200; // (100, 200)
    mp[200] = 300; // (200, 300)
    mp.insert({300, 400});
    mp.insert({400, 500});
    cout << mp.size() << endl;

    // Duyệt map
    for (pair<int, int> x: mp) {
        cout << x.first << " " << x.second << endl;
    }

    for (auto it : mp) {
        cout << it.first << " " << it.second << endl;       
    }

    for (map<int, int>::iterator it = mp.begin(); it != mp.end(); it++) {
        cout << (*it).first << " " << (*it).second << endl;
    }

    // Tìm kiếm
    if (mp.count(100) != 0) {
        cout << "Found" << endl;
    } else {
        cout << "Not Found" << endl;
    }

    if (mp.find(500) != mp.end()) {
        cout << "Found" << endl;
    } else {
        cout << "Not Found" << endl;
    }
    
    // Xóa
    mp.erase(100);
    for (auto it : mp) {
        cout << it.first << " " << it.second << endl;       
    }

    return 0;
}
