#include <bits/stdc++.h>

using namespace std; 

struct Node {
    int data;
    Node *next;
};

typedef struct Node* node;

// Cap phat dong 1 node moi voi du lieu la so nguyen x
node makeNode(int x) {
    node tmp = new Node();
    tmp->data = x;
    tmp->next = nullptr;
    return tmp;
}

// Kiem tra rong
bool empty(node a) {
    return a == nullptr;
}

// Dem so phan tu
int getSize(node a) {
    int cnt = 0;
    while (a != nullptr) {
        cnt++;
        a = a->next;
    }
    return cnt;
}

// Them ptu vao dau
void insertFirst (node &a, int x) {
    node tmp = makeNode(x);
    if (empty(a)) {
        a = tmp;
    } else {
        tmp->next = a;
        a = tmp;
    }
}

// Them ptu vao cuoi
void insertLast (node &a, int x) {
    node tmp = makeNode(x);
    if (empty(a)) {
        a = tmp;
    } else {
        node p = a;
        while (p->next != nullptr) {
            p = p->next;
        }
        p->next = tmp;
    }
}

// Them ptu vao giua
void insertMiddle (node &a, int x, int pos) {
    int n = getSize(a);
    if (pos <= 0 || pos > n + 1) {
        cout << "Vi tri chen khong hop le\n";
    }
    if (pos == 1) {
        insertFirst(a, x);
        return;
    } else if (pos == n + 1) {
        insertLast(a, x);
        return;
    } else {
        node p = a;
        for (int i = 1; i < pos - 1; i++) {
            p = p->next;
        }
        node tmp = makeNode(x);
        tmp->next = p->next;
        p->next = tmp;
    }
}

// Xoa phan tu o dau
void deleteFirst (node &a) {
    if (empty(a)) return;
    a = a->next;
}

// Xoa o cuoi
void deleteLast (node &a) {
    if (empty(a)) return;
    node truoc = nullptr, sau = a;
    while (sau->next != nullptr) {
        truoc = sau;
        sau = sau->next;
    }
    if (truoc == nullptr) {
        a = nullptr;
    } else {
        truoc->next = nullptr;
        delete sau;
    }
}

// Xoa o giua
void deleteMiddle (node &a, int pos) {
    if (pos <= 0 || pos > getSize(a)) {
        cout << "Vi tri xoa khong hop le";
    }
    node truoc = nullptr, sau = a;
    for (int i = 1; i < pos; i++) {
        truoc = sau;
        sau = sau->next;
    }
    if (truoc == nullptr) {
        a = a->next;
    } else {
        truoc->next = sau->next;
        delete sau;
    }
}

// In
void printNode (node a) {
    cout << "\n------------------------------------\n";
    while (!empty(a)) {
        cout << a->data << " ";
        a = a->next;
    }
    cout << "\n------------------------------------\n";
}

// Sap xep giam
void sortDec (node &a) {
    for (node i = a; i->next != nullptr; i = i->next) {
        for (node j = i->next; j != nullptr; j = j->next) {
            if (i->data < j->data) {
                int tmp = i->data;
                i->data = j->data;
                j->data = tmp;
            }
        }
    }
}

// Sap xep tang
void sortInc (node &a) {
    for (node i = a; i->next != nullptr; i = i->next) {
        for (node j = i->next; j != nullptr; j = j->next) {
            if (i->data > j->data) {
                int tmp = i->data;
                i->data = j->data;
                j->data = tmp;
            }
        }
    }
}

int main (int argc, char *argv[]) {
    node head = nullptr;
    while (1) {
        cout << "\n\n\n---------------MENU------------------\n";
        cout << "1. Chen phan tu vao dau danh sach\n";
        cout << "2. Chen phan tu vao cuoi danh sach\n";
        cout << "3. Chen phan tu vao giua danh sach\n";
        cout << "4. Xoa phan tu dau\n";
        cout << "5. Xoa phan tu cuoi\n";
        cout << "6. Xoa phan tu giua\n";
        cout << "7. Sap xep giam\n";
        cout << "8. Sap xep tang\n";
        cout << "9. Duyet danh sach\n";
        cout << "0. Exit\n";
        cout << "------------------------------------\n";
        cout << "Nhap lua chon: ";
        int lc; cin >> lc;
        if (lc == 1) {
            int x; cout << "Nhap gia tri can chen: "; cin >> x;
            insertFirst(head, x);
        } else if (lc == 2) {
            int x; cout << "Nhap gia tri can chen: "; cin >> x;
            insertLast(head, x);
        } else if (lc == 3) {
            int x; cout << "Nhap gia tri can chen: "; cin >> x;
            int pos; cout << "Nhap vi tri can chen: "; cin >> pos;
            insertMiddle(head, x, pos);
        } else if (lc == 4) {
            deleteFirst(head);
        } else if (lc == 5) {
            deleteLast(head);
        } else if (lc == 6) {
            int pos; cout << "Nhap vi tri can xoa: "; cin >> pos;
            deleteMiddle(head, pos);
        } else if (lc == 7) {
            sortDec(head);
        } else if (lc == 8) {
            sortInc(head);
        } else if (lc == 9) {
            printNode(head);
        } else if (lc == 0) {
            break;
        } else {
            cout << "Nhap lai\n";
        }
    }
    return 0;
}
