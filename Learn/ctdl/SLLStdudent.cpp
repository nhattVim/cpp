#include <bits/stdc++.h>

using namespace std;

struct Student {
    string name;
    int age;
    double gpa;
};

struct SLLStudent {
    Student data;
    SLLStudent *next;
};

typedef struct SLLStudent* nodeSV;

// Cap phat dong 1 node moi voi du lieu la so nguyen x
nodeSV makeNode () {
    Student s;
    cout << "Ten: "; cin.ignore(); getline(cin, s.name);
    cout << "Age: "; cin >> s.age;
    cout << "GPA: "; cin >> s.gpa;
    nodeSV tmp = new SLLStudent();
    tmp->data = s;
    tmp->next = nullptr;
    return tmp;
}

// Kiem tra rong
bool empty(nodeSV p) {
    return p == nullptr;
}

// Dem so phan tu
int size(nodeSV p) {
    int d = 0;
    while (!empty(p)) {
        d++;
        p = p->next;
    }
    return d;
}

// Them phan tu vao dau
void insertFirt (nodeSV &p) {
    nodeSV tmp = makeNode();
    if (empty(p)) {
        p = tmp;
    } else {
        tmp->next = p;
        p = tmp;
    }
}

// Them phan tu vao cuoi danh sach
void insertLast (nodeSV &p) {
    nodeSV tmp = makeNode();
    if (empty(p)) {
        p = tmp;
    } else {
        nodeSV n = p;
        while (n != nullptr) {
            n = n->next;
        }
        n->next = tmp;
    }
}

// Them vao giua danh sach
void insertMiddle (nodeSV &p, int pos) {
    int n = size(p);
    if (pos <= 0 || pos > n + 1) {
        cout << "Vi tri khong hop le";
    }
    if (n == 1) {
        insertFirt(p);
    } else if (n == 2) {
        insertLast(p);
    } else {
        for (int i = 1; i < pos - 1; i++) {
            p = p->next;
        }
        nodeSV tmp = makeNode();
        tmp->next = p->next;
        p->next = tmp;
    }
}

// Xoa phan tu o dau
void deleteFirt (nodeSV &p) {
    if (empty(p)) return;
    p = p->next;
}

// Xoa phan tu o cuoi
void deleteLast (nodeSV &p) {
    if (empty(p)) return;
    nodeSV truoc = nullptr, sau = p;
    while (sau->next != nullptr) {
        truoc = sau;
        sau = sau->next;
    }
    if (truoc == nullptr) {
        p = nullptr;
    }
    truoc->next = nullptr;
    delete sau;
}

int main (int argc, char *argv[]) {
       
    return 0;
}
