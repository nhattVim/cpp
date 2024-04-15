#include <bits/stdc++.h>

using namespace std;

struct Student {
    string name;
    int age;
    double gpa;
};

struct DLLNode {
    Student data;
    DLLNode *prev, *next;
};

typedef struct DLLNode* node;

node makeDLLNode (Student s) {
    node tmp = new DLLNode();
    tmp->data = s;
    tmp->prev = nullptr;
    tmp->next = nullptr;
    return tmp;
}

int getSize (node a) {
    int d = 0;
    while (a != nullptr) {
        d++;
        a = a->next;
    }
    return d;
}

void insertFirst (node &a, Student s) {
    node tmp = makeDLLNode(s);
    if (a == nullptr) {
        a = tmp;
    } else {
        tmp->next = a;
        a->prev = tmp;
        a = tmp;
    }
}

void insertLast (node &a, Student s) {
    node tmp = makeDLLNode(s);
    if (a == nullptr) {
        a = tmp;
    } else {
        node p = a;
        while (p->next != nullptr) {
            p = p->next;
        }
        p->next = tmp;
        tmp->prev = p;
    }
}

void insertMiddle (node &a, Student s, int pos) {
    int n = getSize(a);
    if (pos <= 0 || pos > n + 1) {
        cout << "Vi tri khong hop le";
        return;
    }
    if (pos == 1) {
        insertFirst(a, s);
    } else if (pos == n + 1) {
        insertLast(a, s);
    } else {
        node tmp = makeDLLNode(s);
        node p = a; 
        for (int i = 1 ; i < pos - 1; i++) {
            p = p->next;
        }
        tmp->next = p->next;
        p->next->prev = tmp;
        p->next = tmp;
        tmp->prev = p;
    }
}

void deleteFirst (node &a) {
    if (a == nullptr) {
        return;
    } else {
        a = a->next;
    }
}

void deleteLast (node &a) {
    node truoc = nullptr, sau = a;
    while (a != nullptr) {
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

void deleteNode (node &a, node p) {
    if (a == nullptr) {
        return;
    } else {
        p->prev->next = p->next;
        p->next->prev = p->prev;
        delete p;
    }
}

void prinstStudent (Student s) {
    cout << "Ten: " << s.name << endl;
    cout << "Tuoi: " << s.age << endl;
    cout << "GPA: " << s.gpa << endl;
}

void printNode (node a) {
    cout << "\n---------------------------\n";
    while (a != nullptr) {
        prinstStudent(a->data);
        a = a->next;
    }
    cout << "---------------------------\n";
}

node readFile (const string filename) {
    fstream file(filename.c_str());
    node tmp = nullptr;
    Student s; 
    string name, age, gpa;
    while (getline(file, name, ',') && getline(file, age, ',') && getline(file, gpa)) {
        s.name = name;
        s.age = stoi(age);
        s.gpa = stod(gpa);
        insertLast(tmp, s);
    }
    file.close();
    return tmp;
}

void writeFile (const string filename, node a) {
    fstream file(filename.c_str());
    while (a != nullptr) {
        file << "Ten: " << a->data.name << endl;
        file << "Tuoi: " << a->data.age << endl;
        file << "GPA: " << a->data.gpa << endl;
        a = a->next;
    }
    file.close();
}

node searchByName (node a, string name) {
    while (a != nullptr) {
        if (a->data.name == name) {
            return a;
        }
        a = a->next;
    }
    return nullptr;
}

void deleteByName (node &a, string name) {
    if (searchByName(a, name)) {
        deleteNode(a, searchByName(a, name));
    }
}

// void insertionSort (node &a) {
//     if (a == nullptr || a->next == nullptr) {
//         return;
//     }
//     for (node i = a->next; i != nullptr; i = i->next) {
//         node pos = i->prev;
//         while (pos != nullptr && pos->data.gpa < i->data.gpa ) {
//             pos->next->data = pos->data;
//             pos = pos->prev;
//         }
//     }
// }
void insertionSort(node &a) {
    if (a == nullptr || a->next == nullptr) {
        return; // Danh sách rỗng hoặc chỉ có một nút, không cần sắp xếp
    }

    node sorted = a->next;
    while (sorted != nullptr) {
        node current = sorted;
        sorted = sorted->next;

        node pos = current->prev;
        while (pos != nullptr && pos->data.gpa < current->data.gpa) {
            pos->next->data = pos->data;
            pos = pos->prev;
        }

        if (pos == nullptr) {
            a->data = current->data;
        } else {
            pos->next->data = current->data;
        }
    }
}

int main (int argc, char *argv[]) {
    // a)
    node sv = readFile("hw4_2_1.txt");

    // b)
    printNode(sv);

    // c)
    writeFile("text.txt", sv);

    // d)
    cout << "Name to find: ";
    string nameToFind; getline(cin, nameToFind);
    if (searchByName(sv, nameToFind)) {
        prinstStudent(searchByName(sv, nameToFind)->data);
    } else {
        cout << "Not found";
    }

    // e)
    cout << "\nName to delete: ";
    string nameToDelete; getline(cin, nameToDelete);
    if (searchByName(sv, nameToDelete)) {
        deleteByName(sv, nameToDelete);
        printNode(sv);
    } else {
        cout << "Not found";
    }

    // d)
    insertionSort(sv);
    printNode(sv);

    return 0;
}
