#include <bits/stdc++.h>

using namespace std;

struct Student {
    string name;
    int age;
    double gpa;
};

struct SLLStudents {
    Student data;
    SLLStudents *next;
};

SLLStudents *readFile(const string fileName) {
    SLLStudents *head = nullptr, *last = nullptr;
    fstream file(fileName.c_str());
    Student s;
    string name, age, gpa;
    while (getline(file, name, ',') && getline(file, age, ',') &&
           getline(file, gpa)) {
        s.name = name;
        s.age = stoi(age);
        s.gpa = stod(gpa);
        SLLStudents *p = new SLLStudents;
        p->data = s;
        p->next = nullptr;
        if (head == nullptr) {
            head = p;
        } else {
            last->next = p;
        }
        last = p;
    }
    file.close();
    return head;
}

void printListOfStudents(SLLStudents *p) {
    while (p != nullptr) {
        cout << p->data.name << " " << p->data.age << " " << p->data.gpa
             << endl;
        p = p->next;
    }
}

void writeFile(const string fileName, SLLStudents *p) {
    fstream file(fileName.c_str());
    while (p != nullptr) {
        file << p->data.name << " " << p->data.age << " " << p->data.gpa
             << endl;
        p = p->next;
    }
    file.close();
}

void insertLast(SLLStudents *&p, Student s) {
    SLLStudents *q = new SLLStudents;
    q->data = s;
    q->next = nullptr;
    if (p == nullptr) {
        p = q;
        return;
    }
    SLLStudents *temp = p;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = q;
}

SLLStudents *goodStudents(SLLStudents *p) {
    SLLStudents *head = nullptr, *last = nullptr;
    while (p != nullptr) {
        if (p->data.gpa >= 8) {
            SLLStudents *tmp = new SLLStudents;
            tmp->data = p->data;
            tmp->next = nullptr;
            if (head == nullptr) {
                head = tmp;
            } else {
                last->next = tmp;
            }
            last = tmp;
        }
        p = p->next;
    }
    return head;
}

SLLStudents *findByName(SLLStudents *head, string const name) {
    while (head != nullptr) {
        if (head->data.name == name) {
            return head;
        }
        head = head->next;
    }
    return nullptr;
}

void deleteByName(SLLStudents *&head, const string name) {
    SLLStudents *x = findByName(head, name);
    SLLStudents *p1 = nullptr;
    SLLStudents *p = head;

    while (p != nullptr) {
        if (p == x) {
            if (p1 == nullptr) {
                head = p->next;
            } else {
                p1->next = p->next;
            }
            cout << "Delete " << p->data.name << " successfully" << "\n\n";
            delete p;
            break;
        }
        p1 = p;
        p = p->next;
    }
}

void insertStudentByPos(SLLStudents *&head, int k, Student newStudent) {
    SLLStudents *newNode = new SLLStudents;
    newNode->data = newStudent;
    newNode->next = nullptr;

    if (k == 0) {
        newNode->next = head;
        head = newNode;
        return;
    }

    SLLStudents *temp = head;
    for (int i = 0; temp != nullptr && i < k - 1; ++i) {
        temp = temp->next;
    }

    if (temp == nullptr) {
        cout << "Vị trí k không hợp lệ\n";
        delete newNode;
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}

void deleteByPos(SLLStudents *&head, int k) {
    if (head == nullptr) {
        cout << "Danh sách rỗng\n";
        return;
    }

    if (k == 0) {
        SLLStudents *temp = head;
        head = head->next;
        delete temp;
        return;
    }

    SLLStudents *p = head;
    for (int i = 0; p != nullptr && i < k - 1; ++i) {
        p = p->next;
    }

    if (p == nullptr || p->next == nullptr) {
        cout << "Vị trí k không hợp lệ\n";
        return;
    }

    SLLStudents *tmp = p->next;
    p->next = tmp->next;
    delete tmp;
}

void sortByGPA(SLLStudents *&head) {
    SLLStudents *p = head;
    while (p != nullptr) {
        SLLStudents *max = p;
        SLLStudents *maxNext = p->next;
        while (maxNext != nullptr) {
            if (maxNext->data.gpa > max->data.gpa) {
                max = maxNext;
            }
            maxNext = maxNext->next;
        }

        if (max != p) {
            swap(p->data, max->data);
        }

        p = p->next;
    }
}

// SLLStudents *mergeListOfStudents(SLLStudents *a, SLLStudents *b) {
//     SLLStudents *c = nullptr;
//     while (a != nullptr && b != nullptr) {
//         if (a->data.gpa >= b->data.gpa) {
//             insertLast(c, b->data);
//             b = b->next;
//         } else {
//             insertLast(c, a->data);
//             a = a->next;
//         }
//     }
//     return c;
// }

void insertListByName(SLLStudents *&l1, SLLStudents *l2, const string name) {
    SLLStudents *h1 = l1;

    while (h1 != nullptr) {
        if (h1->data.name == name) {
            SLLStudents *tmp = h1->next;
            h1->next = l2;

            SLLStudents *h2 = l2;
            if (h2 != nullptr) {
                while (h2->next != nullptr) {
                    h2 = h2->next;
                }
                h2->next = tmp;
            }
            return;
        }
        h1 = h1->next;
    }
}

SLLStudents *reverseList(SLLStudents *head) {
    SLLStudents *prev = nullptr;
    SLLStudents *current = head;
    SLLStudents *next = nullptr;
    while (current != nullptr) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev;
}

void inputStudent(struct Student &s) {
    cout << "Name: ";
    getline(cin, s.name);
    cout << "Age: ";
    cin >> s.age;
    cout << "GPA: ";
    cin >> s.gpa;
}

void outputStudent(struct Student s) {
    cout << "Name: " << s.name << endl;
    cout << "Age: " << s.age << endl;
    cout << "GPA: " << s.gpa << endl;
}

int main(int argc, char *argv[]) {
    SLLStudents *head;

    // a)
    head = readFile("hw4_list1.txt");

    // b)
    cout << "b) In danh sách sinh viên\n\n";
    printListOfStudents(head);
    cout << "\n\n";

    // c)
    writeFile("students.txt", head);

    // d)
    cout << "d) Thêm sinh viên vào cuối danh sách\n\n";
    Student s;
    inputStudent(s);
    insertLast(head, s);
    printListOfStudents(head);
    cout << "\n\n";

    // e)
    cout << "e) Tạo danh sách sinh viên xuất sắc có gpa >= 8\n\n";
    SLLStudents *rank = goodStudents(head);
    printListOfStudents(rank);
    cout << "\n\n";

    // f)
    cout << "f) Tìm một sinh viên theo họ tên\n\n";
    cout << "Find Name: ";
    string findName;
    cin.ignore();
    getline(cin, findName);
    SLLStudents *f = findByName(head, findName);
    if (f != nullptr) {
        outputStudent(f->data);
    } else {
        cout << "Không tìm thấy sinh viên có tên này.";
    }
    cout << "\n\n";

    // g)
    cout << "g) Xóa một sinh viên theo họ tên\n\n";
    cout << "Delete Name: ";
    string delName;
    getline(cin, delName);
    deleteByName(head, delName);
    printListOfStudents(head);
    cout << "\n\n";

    // h)
    cout << "h) Thêm một sinh viên vào vị trí k\n\n";
    Student newStudent;
    inputStudent(newStudent);
    int k;
    cout << "Position: ";
    cin >> k;
    insertStudentByPos(head, k, newStudent);
    cout << "\n";
    printListOfStudents(head);
    cout << "\n\n";

    // i)
    cout << "i) Xóa một sinh viên trong danh sách theo vị trí k\n\n";
    int k1;
    cout << "Position: ";
    cin >> k1;
    deleteByPos(head, k1);
    cout << "\n";
    printListOfStudents(head);
    cout << "\n\n";

    // j)
    cout << "j) Sắp xếp danh sách theo gpa (giảm)\n\n";
    sortByGPA(head);
    cout << "\n";
    printListOfStudents(head);
    cout << "\n\n";

    // k)
    cout << "k) Trộn dai danh sách đã sắp xếp theo thứ tự giảm của gpa thành 1 "
            "danh sách đã dắp xếp theo gpa\n\n";
    SLLStudents *head2;
    head2 = readFile("hw4_list2.txt");
    sortByGPA(head2);
    cout << "Danh sách 1\n\n";
    printListOfStudents(head);
    cout << "Danh sách 2\n\n";
    printListOfStudents(head2);
    cout << "\nDanh sách sau khi trộn\n\n";
    // printListOfStudents(mergeListOfStudents(head, head2));
    cout << "\n\n";

    // l)
    cout << "l) Chèn danh sách list 2 vào list 1 ngay sau sinh viên có tên "
            "sau\n\n";
    string insertName;
    cout << "Name: ";
    cin.ignore();
    getline(cin, insertName);
    insertListByName(head, head2, insertName);
    printListOfStudents(head);
    cout << "\n\n";

    // m)
    // cout << "m) Đảo ngược 1 danh sách sinh viên\n\n";
    // printListOfStudents(reverseList(head));
    // cout << "\n\n";

    return 0;
}
