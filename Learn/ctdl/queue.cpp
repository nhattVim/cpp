#include <bits/stdc++.h>

using namespace std;

int main (int argc, char *argv[]) {
    queue<int> q;
    q.push(9);
    q.push(1);
    q.push(2);
    q.push(7);
    cout << q.front() << endl;
    q.pop();
    cout << q.front() << endl;
    cout << q.size() << endl;
    q.pop();
    q.pop();
    q.pop();
    cout << q.empty() << endl;
    return 0;
}
