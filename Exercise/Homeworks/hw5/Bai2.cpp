#include <algorithm>
#include <bits/stdc++.h>
#include <climits>
#include <queue>
#include <stack>
#include <vector>

using namespace std;

void printStack(stack<int> s) {
    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
}

void printQueue(queue<int> q) {
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
}

int popK(queue<int> &q, int k) {
    queue<int> tmp;

    for (int i = 1; i < k; i++) {
        tmp.push(q.front());
        q.pop();
    }

    int x = q.front();
    q.pop();

    while (!q.empty()) {
        tmp.push(q.front());
        q.pop();
    }

    while (!tmp.empty()) {
        q.push(tmp.front());
        tmp.pop();
    }

    return x;
}

void pushK(stack<int> &s, int i, int k) {
    stack<int> tmp;

    for (int i = 1; i < k; i++) {
        tmp.push(s.top());
        s.pop();
    }

    s.push(i);

    while (!tmp.empty()) {
        s.push(tmp.top());
        tmp.pop();
    }
}

void reverseQueue(queue<int> &q) {
    stack<int> tmp;

    while (!q.empty()) {
        tmp.push(q.front());
        q.pop();
    }

    while (!tmp.empty()) {
        q.push(tmp.top());
        tmp.pop();
    }
}

int findMinStack(stack<int> s) {
    int min = INT_MAX;

    while (!s.empty()) {
        if (s.top() < min) {
            min = s.top();
        }
        s.pop();
    }

    return min;
}

void sortQueue(queue<int> &q) {
    vector<int> tmp;

    while (!q.empty()) {
        tmp.push_back(q.front());
        q.pop();
    }

    sort(tmp.begin(), tmp.end());

    for (int s : tmp) {
        q.push(s);
    }
}

int main() {
    queue<int> q;
    q.push(5);
    q.push(3);
    q.push(2);
    q.push(8);
    printQueue(q);
    int a = popK(q, 2);
    cout << "Phần tử thứ 2 là: " << a << endl;
    cout << "Hàng đợi còn lại: ";
    printQueue(q);
    cout << "Đảo ngược hàng đợi: ";
    reverseQueue(q);
    printQueue(q);
    cout << "Sắp tăng hàng đợi: ";
    sortQueue(q);
    printQueue(q);

    // stack<int> s;
    // s.push(5);
    // s.push(3);
    // s.push(2);
    // s.push(8);
    // printStack(s);
    // cout << "Thêm phần tử 4 vào vị trí 2 của stack: ";
    // pushK(s, 4, 2);
    // printStack(s);
    // cout << "Khoá nhỏ nhât của ngăn xếp là: " << findMinStack(s) << endl;

    return 0;
}
