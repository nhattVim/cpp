#include <bits/stdc++.h>

using namespace std;

struct Students {
    string name;
    float gpa;
};

list<Students> readFromFile(const string fileName) {
    ifstream file(fileName);

    list<Students> l;
    string name, gpa;

    while (getline(file, name, ',') && getline(file, gpa)) {
        Students s;
        s.name = name;
        s.gpa = stof(gpa);
        l.push_back(s);
    }

    file.close();

    return l;
}

void searchStudent(list<Students> l, const string name) {
    for (Students s : l) {
        if (s.name == name) {
            cout << "Tìm thấy sinh viên: \n";
            cout << s.name << " " << s.gpa << endl;
            return;
        }
    }
    cout << "Không tìm thấy sinh viên\n";
}

void deleteStudents(list<Students> &l, const string name) {
    for (auto it = l.begin(); it != l.end(); it++) {
        if (it->name == name) {
            l.erase(it);
            break;
        }
    }
}

void printList(list<Students> l) {
    for (Students s : l) {
        cout << s.name << " " << s.gpa << endl;
    }
}

void writeToFile(list<Students> l, const string fileName) {
    ofstream file(fileName);
    for (Students s : l) {
        file << s.name << "," << s.gpa << endl;
    }
    file.close();
}

void sortDescending(list<Students> &l) {
    for (auto it1 = l.begin(); it1 != l.end(); it1++) {
        for (auto it2 = next(it1); it2 != l.end(); it2++) {
            if (it1->gpa < it2->gpa) {
                // swap(*it, *it2);
                Students temp = *it1;
                *it1 = *it2;
                *it2 = temp;
            }
        }
    }
}

void addToListDesc(Students s, list<Students> &l) {
    for (auto it = l.begin(); it != l.end(); ++it) {
        if (s.gpa > it->gpa) {
            l.insert(it, s);
            return;
        }
    }

    l.push_back(s);
}

int main(int argc, char *argv[]) {
    // a)
    list<Students> l = readFromFile("students.txt");

    // b)
    printList(l);

    // c)
    writeToFile(l, "output.txt");

    // d)
    cout << "\nNhập tên để tìm kiếm: ";
    string sName;
    getline(cin, sName);
    searchStudent(l, sName);

    // e)
    cout << "\nNhập tên để xoá: ";
    string dName;
    getline(cin, dName);
    cout << "\nDanh sách trước khi xoá: \n";
    printList(l);
    deleteStudents(l, dName);
    cout << "\nDanh sách sau khi xoá: \n";
    printList(l);

    // f)
    cout << "\nDanh sách sau khi sắp xếp giảm: \n";
    sortDescending(l);
    printList(l);

    // e)
    cout << "\nNhập sinh viên để thêm: ";
    cout << "\nTên: ";
    string name;
    getline(cin, name);
    cout << "GPA: ";
    float gpa;
    cin >> gpa;
    Students s = {name, gpa};
    addToListDesc(s, l);
    cout << "\nDanh sách sau khi thêm:\n";
    printList(l);

    return 0;
}
