#include <bits/stdc++.h>

using namespace std;

struct Student {
    string name;
    int age;
    double gpa;
};

void inputStudent(struct Student &s) {
    cout << "Name: "; getline(cin, s.name);
    cout << "Age: "; cin >> s.age;
    cout <<  "GPA: "; cin >> s.gpa;
}

void inputListOfStudent(struct Student a[], int n) {
    for (int i = 0; i < n; i++) {
        inputStudent(a[i]);
        cin.ignore();
    }
}

void printStudent(struct Student s) {
    cout << "Name: " << s.name << endl;
    cout << "Age: " << s.age << endl;
    cout << "GPA: " << s.gpa << endl;
}

void printListOfStudent(struct Student a[], int n) {
    cout << "\n\n";
    for (int i = 0; i < n; i++) {
        printStudent(a[i]);
    }
    cout << endl;
}

void deleteStudent(struct Student a[], int n, int k) {
    for (int i = k; i <= n; i++) {
        a[i] = a[i + 1];
    }
}

int main (int argc, char *argv[]) {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n = 5;
    struct Student a[100];
    inputListOfStudent(a, n);
    printListOfStudent(a, n);

    // a)
    double x; int d = 0;
    cout << "X: "; cin >> x;
    for (int i = 0; i <= n; i++) {
        if (a[i].gpa >= x) {
            d++;
        }
    }
    cout << "\n\nd:" << d;

    // b)
    string name;
    cout << "\n\nName to delete student:"; getline(cin, name);
    for (int i = 0; i <= n; i++) {
        if (name == a[i].name) {
            deleteStudent(a, n, i);
        }
    }
    printListOfStudent(a, 7);

    return 0;
}
