#include <bits/stdc++.h>
#include <ostream>
#include <stack>

using namespace std;

// Stack (LIFO list: last in first out)
// Ham hay su dung, do phuc tap O(1)
// push     : day phan tu vao stack
// pop      : lay phan tu o dinh stack ra khoi stack
// top      : lay phan tu o dinh stack
// size     : tra ve so luong phan tu
// empty    : check rong

int main (int argc, char *argv[]) {
    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    cout << st.top() << endl;
    st.pop();
    cout << st.top() << endl;
    cout << st.size() << endl;
    if (st.empty()) {
        cout << "Rong";
    } else {
        cout << "Khong rong";
    }
    return 0;
}
