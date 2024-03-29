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
        file << p -> data.name << " " << p -> data.age << p -> data.gpa << endl;
        p = p -> next;
    }
    file.close();
}

void insert (SLLStudents* &p, Student s) {
    SLLStudents *q = new SLLStudents;
    q -> data = s;
    q -> next = p;
    p = q;
}

int main (int argc, char *argv[]) {
    // a)
    SLLStudents *p = readFile("hw4.txt");
    printSLL(p);

    // b)
    writeFile("test.txt", p);

    // c)
    Student s;
    s.name = "test";
    s.age = 10;
    s.gpa = 2.2;
    insert(p, s);
    cout << "\n\n\n";
    printSLL(p);

    return 0;
}
