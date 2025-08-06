#include <bits/stdc++.h>
#include <fstream>

using namespace std;

struct Students {
    string name;
    float gpa;
    int age;
};

struct SLLStudents {
    Students data;
    SLLStudents *next;
};

SLLStudents *readFromFile(const string fileName) {
    SLLStudents *head = nullptr, *last = nullptr;
    ifstream f(fileName);

    if (!f.is_open()) {
        cout << "Không mở được file: " << fileName << endl;
        return nullptr;
    }

    string name, gpa, age;
    while (getline(f, name, ',') && getline(f, age, ',') && getline(f, gpa)) {
        Students s = {name, stof(gpa), stoi(age)};
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
    f.close();
    return head;
}

void prinListStudents(SLLStudents *head) {
    SLLStudents *p = head;
    while (p != nullptr) {
        cout << p->data.name << " " << p->data.age << " " << p->data.gpa
             << endl;
        p = p->next;
    }
}

void writeToFile(SLLStudents *head, const string fileName) {
    ofstream f(fileName);
    SLLStudents *p = head;
    while (p != nullptr) {
        f << p->data.name << "," << p->data.age << "," << p->data.gpa << endl;
        p = p->next;
    }
    f.close();
}

void insertLast(SLLStudents *&head, Students s) {
    SLLStudents *p = new SLLStudents;
    p->data = s;
    p->next = nullptr;

    if (head == nullptr) {
        head = p;
        return;
    }

    SLLStudents *tmp = head;
    while (tmp->next != nullptr) {
        tmp = tmp->next;
    }

    tmp->next = p;
}

int main(int argc, char *argv[]) {
    SLLStudents *head = readFromFile("students.txt");
    prinListStudents(head);

    writeToFile(head, "output.txt");

    insertLast(head, {"aaa", 2.3, 23});
    prinListStudents(head);
    return 0;
}
