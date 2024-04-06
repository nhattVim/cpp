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

Student makeStudent() {
    Student s;
    cout << "Ten: "; cin.ignore(); getline(cin, s.name);
    cout << "Age: "; cin >> s.age;
    cout << "GPA: "; cin >> s.gpa;
    return s;
}

nodeSV makeNodeSV (Student s) {
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
void insertFirst (nodeSV &p, nodeSV tmp) {
    if (empty(p)) {
        p = tmp;
    } else {
        tmp->next = p;
        p = tmp;
    }
}

// Them phan tu vao cuoi danh sach
void insertLast (nodeSV &p, nodeSV tmp) {
    if (empty(p)) {
        p = tmp;
    } else {
        nodeSV n = p;
        while (n->next != nullptr) {
            n = n->next;
        }
        n->next = tmp;
    }
}

// Them vao giua danh sach
void insertMiddle (nodeSV &p, nodeSV tmp, int pos) {
    int n = size(p);
    if (pos <= 0 || pos > n + 1) {
        cout << "Vi tri khong hop le";
    }
    if (n == 1) {
        insertFirst(p, tmp);
    } else if (n == pos + 1) {
        insertLast(p, tmp);
    } else {
        for (int i = 1; i < pos - 1; i++) {
            p = p->next;
        }
        nodeSV tmp = makeNodeSV(makeStudent());
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
    } else {
        truoc->next = nullptr;
        delete sau;
    }
}

// Xoa phan tu o giua
void deleteMiddle (nodeSV &p, int pos) {
    if (pos <= 0 || pos >= size(p)) {
        cout << "Vi tri khong hop le";
    }
    nodeSV truoc = nullptr, sau = p;
    for (int i = 1 ; i < pos; i++) {
        truoc = sau;
        sau = sau->next;
    }
    if (truoc == nullptr) {
        deleteFirt(p);
    } else {
        truoc->next = sau->next;
        delete sau;
    }
}

// In
void printNodeSV (nodeSV p) {
    cout << "\n---------------------------\n";
    while (!empty(p)) {
        cout << "Ten: " << p->data.name << endl;
        cout << "Tuoi: " << p->data.age << endl;
        cout << "GPA: " << p->data.age << endl;
        p = p->next;
    }
    cout << "---------------------------\n";
}

int main (int argc, char *argv[]) {
    nodeSV sv = nullptr;
    while (1) {
        cout << "\n-------------------MENU-------------------\n";
        cout << "0. Exit\n";
        cout << "1. Duyet danh sach lien ket\n";
        cout << "2. Them vao dau\n";
        cout << "3. Them vao cuoi\n";
        cout << "4. Them vao giua\n";
        cout << "5. Xoa phan tu dau\n";
        cout << "6. Xoa phan tu cuoi\n";
        cout << "7. Xoa phan tu giua";
        cout << "\n-------------------MENU-------------------\n";
        cout << "Nhap lua chon: ";
        int n; cin >> n;
        switch (n) {
            case 0: {
                return 0;
                break;
            }
            case 1: {
                if (empty(sv)) {
                    cout << "Danh sach rong";
                } else {
                    printNodeSV(sv);
                }
                break;
            }
            case 2: {
                nodeSV tmp = makeNodeSV(makeStudent());
                insertFirst(sv, tmp);
                break;
            }
            case 3: {
                nodeSV tmp = makeNodeSV(makeStudent());
                insertLast(sv, tmp);
                break;
            }
            case 4: {
                int pos; cout << "Nhap vi tri can chen: "; cin >> pos;
                nodeSV tmp = makeNodeSV(makeStudent());
                insertMiddle(sv, tmp, pos);
                break;
            }
            case 5: {
                deleteFirt(sv);
            }
            case 6: {
                deleteLast(sv);
            }
            case 7: {
                int pos; cout << "Nhap vi tri can xoa: "; cin >> pos;
                deleteMiddle(sv, pos);
            }
            default: {
                cout << "Lua chon khong hop le";
                break;
            }
        }
    } 
    return 0;
}
