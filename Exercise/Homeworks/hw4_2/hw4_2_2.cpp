#include <bits/stdc++.h>

using namespace std;

int popK(queue<int> &q, int k) {
    queue<int> tmp;
    for(int i = 0; i < k; i++){
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
    for (int i = 0; i < k; ++i) {
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
    priority_queue<int, vector<int>, greater<int>> pq;
    while (!q.empty()) {
        pq.push(q.front());
        q.pop();
    }
    while (!pq.empty()) {
        q.push(pq.top());
        pq.pop();
    }
}

int main (int argc, char *argv[]) {
    queue<int> myQueue;
    stack<int> myStack;

    for (int i = 1; i <= 5; ++i) {
        myQueue.push(i);
        myStack.push(i);
    }

    int kthElement = popK(myQueue, 2);
    cout << "Phan tu thu 2 cua hang doi: " << kthElement << endl;

    pushK(myStack, 2, 10);

    cout << "So nho nhat trong ngan xep: " << minStack(myStack) << endl;

    reverseQueue(myQueue);

    cout << "So nho nhat trong hang doi: " << minQueue(myQueue) << endl;

    sortQueue(myQueue);

    return 0;
}
