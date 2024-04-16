#include <algorithm>
#include <bits/stdc++.h>
#include <vector>

using namespace std;

int popK(queue<int> &q, int k) {
    queue<int> tmp;
    for(int i = 0; i < k - 1; i++){
        tmp.push(q.front());
        q.pop();
    }
    int x = q.front();
    q.pop();
    while (!q.empty()){
        tmp.push(q.front());
        q.pop();
    }
    while (!tmp.empty()){
        q.push(tmp.front());
        tmp.pop();
    }
    return x;
}

void pushK(stack<int> &s, int k, int value) {
    stack<int> tmp;
    for (int i = 0; i < k; i++) {
        tmp.push(s.top());
        s.pop();
    }
    s.push(value);
    while (!tmp.empty()) {
        s.push(tmp.top());
        tmp.pop();
    }
}

int minStack(stack<int> s) {
    int min_val = INT_MAX;
    while (!s.empty()) {
        min_val = min(min_val, s.top());
        s.pop();
    }
    return min_val;
}

void reverseQueue(queue<int> &q) {
    stack<int> s;
    while (!q.empty()) {
        s.push(q.front());
        q.pop();
    }
    while (!s.empty()) {
        q.push(s.top());
        s.pop();
    }
}

int minQueue(queue<int> q) {
    int min_val = INT_MAX;
    while (!q.empty()) {
        min_val = min(min_val, q.front());
        q.pop();
    }
    return min_val;
}

void sortQueue(queue<int> &q) {
    vector<int> v;
    while (!q.empty()) {
        v.push_back(q.front());
        q.pop();
    }
    sort(v.begin(), v.end());
    for (int i : v) {
        q.push(i);
    }
}

void printQueue(queue<int> q) {
    cout << "Queue: ";
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
}

void printStack(stack<int> s) {
    cout << "Stack: ";
    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
}

int main (int argc, char *argv[]) {
    queue<int> q;
    stack<int> s;

    q.push(2);
    q.push(6);
    q.push(10);
    q.push(9);
    q.push(8);
    q.push(5);
    q.push(7);

    s.push(2);
    s.push(6);
    s.push(10);
    s.push(9);
    s.push(8);
    s.push(5);
    s.push(7);

    // a)
    printQueue(q);
    cout << "Index you want to take: "; int n1; cin >> n1;
    cout << "Take at: " << popK(q, n1) << endl;
    printQueue(q);
    cout << "\n";

    // b)
    printStack(s);
    cout << "Index you want to add: "; int n2; cin >> n2;
    cout << "Value you want to add: "; int n3; cin >> n3;
    pushK(s, n2, n3);
    printStack(s);
    cout << "\n";

    // c)
    cout << "Minimum number of stack: " << minStack(s) << endl;
    cout << "\n";

    // d)
    cout << "Queue after reverse" << endl;
    reverseQueue(q);
    printQueue(q);
    cout << "\n";

    // e)
    cout << "Minimum number of queue: " << minQueue(q) << endl;
    cout << "\n";

    // f)
    cout << "Queue after sort" << endl;
    sortQueue(q);
    printQueue(q);

    return 0;
}
