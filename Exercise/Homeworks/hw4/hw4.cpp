#include <bits/stdc++.h>

using namespace std;

struct Student {
    string  name;
    int     age;
    double  gpa;
};

struct SLLStudents {
    Student     data;
    SLLStudents *next;
};

SLLStudents *readFile (const string fileName) {
    SLLStudents *head = nullptr, *last = nullptr;
    fstream file(fileName.c_str());
    Student s;
    string name, age, gpa;
    while (getline(file, name, ',') && getline(file, age, ',') && getline(file, gpa)) {
        s.name = name;
        s.age = stoi(age);
        s.gpa = stod(gpa);
        SLLStudents *p = new SLLStudents;
        p -> data = s;
        p -> next = nullptr;
        if (head == nullptr) {
            head = p;
        } else {
            last -> next = p;
        }
        last = p;
    }
    file.close();
    return head;
}

void printSLL (SLLStudents *p) {
    while (p != nullptr) {
        cout << p -> data.name << " " << p -> data.age << " " << p -> data.gpa << endl;
        p = p -> next;
    }
}

void writeFile (const string fileName, SLLStudents *p) {
    fstream file(fileName.c_str());
    while (p != nullptr) {
        file << p -> data.name << " " << p -> data.age << " " << p -> data.gpa << endl;
        p = p -> next;
    }
    file.close();
}

void addToEnd (SLLStudents* &p, Student s) {
    SLLStudents *q = new SLLStudents;
    q -> data = s;
    q -> next = nullptr;
    if (p == nullptr) {
        p = q;
        return;
    }
    SLLStudents *temp = p;
    while ( temp -> next != nullptr) {
        temp = temp -> next;
    }
    temp -> next = q;
}

SLLStudents *rankStudent (SLLStudents *p) {
    SLLStudents *head = nullptr, *last = nullptr;
    while (p != nullptr) {
        if (p -> data.gpa >= 8) {
            SLLStudents *tmp = new SLLStudents;
            tmp -> data = p -> data;
            tmp -> next = nullptr;
            if (head == nullptr) {
                head = tmp;
            } else {
                last -> next = tmp;
            }
            last = tmp;
        }
        p = p -> next;
    }
    return head;
}

SLLStudents *findByName (SLLStudents *p, string name) {
    while (p != nullptr) {
        if (p -> data.name == name) {
            return p;
        }
        p = p -> next;
    }
    return nullptr;
}

void deleteSLL (SLLStudents *&head, SLLStudents *x) {
    while (head != nullptr) {
        if (head == x) {
            SLLStudents *p = x;
            p = head -> next;
            head -> next = p -> next;
            delete p;
        }
        head = head -> next;
    }
}

int main (int argc, char *argv[]) {
    // a)
    SLLStudents *p = readFile("hw4.txt");

    // b)
    printSLL(p);
    cout << "\n\n";

    // c)
    writeFile("students.txt", p);

    // d)
    Student s;
    s.name = "Nguyễn Văn Test";
    s.age = 10;
    s.gpa = 2.2;
    addToEnd(p, s);
    printSLL(p);
    cout << "\n\n";

    // e)
    SLLStudents *rank = rankStudent(p);
    printSLL(rank);
    cout << "\n\n";

    // f)
    SLLStudents *f = findByName(p, "Nguyễn Văn Test");
    if (f != nullptr) {
        cout << "Đã tìm thấy sinh viên: " << f -> data.name << ", " << f -> data.age << ", " << f -> data.gpa << "\n\n";
    } else {
        cout << "Không tìm thấy sinh viên có tên này.\n\n";
    }

    // g)
    deleteSLL(p, findByName(p, "Nguyễn Văn Tèo"));
    printSLL(p);

    return 0;
}
