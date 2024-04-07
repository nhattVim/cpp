#include <bits/stdc++.h>

using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
};

typedef struct Node* node;

node makeNode (int x) {
    node tmp = new Node ();
    tmp->data = x;
    tmp->prev = nullptr;
    tmp->next = nullptr;
    return tmp;
}

void printNode (node p) {
    while (p != nullptr) {
        cout << p->data << " ";
        p = p->next;
    }
}   

int getSize (node p) {
    int d = 0;
    while (p != nullptr) {
        d++;
        p = p->next;
    }
    return d;
}

void insertFirst (node &p, int x) {
    node tmp = makeNode (x);
    if (p == nullptr) {
        p = tmp;
    } else {
        tmp->next = p;
        p->prev = tmp;
        p = tmp;
    }
}

void insertLast (node &p, int x) {
    node tmp = makeNode(x);
    if (p == nullptr) {
        p = tmp;
    } else {
        node a = p;
        while (a->next != nullptr) {
            a = a->next;
        }
        a->next = tmp;
        tmp->prev = a;
    }
}

void insertMiddle (node &p, int x, int pos) {
    int n = getSize(p);
    if (pos <= 0 || pos > n + 1) {
        cout << "Vi tri khong hop le";
        return;
    } else if (pos == 1) {
        insertFirst(p, x);
    } else if (pos == n + 1) {
        insertLast(p, x);
    } else {
        node a = p;
        for (int i = 1; i < pos - 1; i++) {
            a = a->next;
        }
        node tmp = makeNode(x);
        tmp->next = a->next;
        a->next->prev = tmp;
        a->next = tmp;
        tmp->prev = a;
    }
}

int main (int argc, char *argv[]) {
    node head = nullptr;
    while (1) {
        cout << "\n-------------------MENU-------------------\n";
        cout << "0. Exit\n";
        cout << "1. Duyet danh sach lien ket\n";
        cout << "2. Them vao dau\n";
        cout << "3. Them vao cuoi\n";
        cout << "4. Them vao giua\n";
        cout << "5. Xoa phan tu dau\n";
        cout << "6. Xoa phan tu cuoi\n";
        cout << "7. Xoa phan tu giua\n";
        cout << "8. Sap xep giam sinh vien theo GPA";
        cout << "\n-------------------MENU-------------------\n";
        cout << "Nhap lua chon: ";
        int n; cin >> n;
        switch (n) {
            case 0: {
                return 0;
                break;
            }
            case 1: {
                if (head == nullptr) {
                    cout << "Danh sach rong" << endl;
                } else {
                    printNode(head);
                }
                break;
            }
            case 2: {
                int x; cout << "Nhap gia tri can chen: "; cin >> x;
                insertFirst(head, x);
                break;
            }
            case 3: {
                int x1; cout << "Nhap gia tri can chen: "; cin >> x1;
                insertLast(head, x1);
                break;
            }
            case 4: {
                int pos; cout << "Nhap vi tri can chen: "; cin >> pos;
                int x2; cout << "Nhap gia tri can chen: "; cin >> x2;
                insertMiddle(head, x2, pos);
                break;
            }
            case 5: {
                // deleteFirt(head);
                break;
            }
            case 6: {
                // deleteLast(head);
                break;
            }
            case 7: {
                // int pos2; cout << "Nhap vi tri can xoa: "; cin >> pos2;
                // deleteMiddle(head, pos2);
                break;
            }
            case 8: {
                // sortByGPA(head);
                break;
            }
            default: {
                cout << "Lua chon khong hop le";
                break;
            }
        }
    }
    return 0;
}
