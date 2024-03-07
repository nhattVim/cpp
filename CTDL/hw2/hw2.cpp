#include <bits/stdc++.h>

using std::cin;
using std::cout;
using std::endl;
using std::fstream;
using std::ios;
using std::string;

struct Student {
  string name;
  int age;
  double gpa;
};

void inputStudent(struct Student &n) {
  cout << "Name: ";
  getline(cin, n.name);
  cout << "Age: ";
  cin >> n.age;
  cout << "GPA: ";
  cin >> n.gpa;
}

void inputListOfStudent(struct Student a[], int n) {
  for (int i = 0; i < n; i++) {
    inputStudent(a[i]);
    cin.ignore();
  }
}

void printStudent(struct Student n) {
  cout << "Name: " << n.name << endl;
  cout << "Age: " << n.age << endl;
  cout << "GPA: " << n.gpa << endl;
}

void printListOfStudent(struct Student a[], int n) {
  cout << endl;
  for (int i = 0; i < n; i++) {
    printStudent(a[i]);
  }
  cout << endl;
}

bool findStudent(struct Student a[], int n, string name) {
  for (int i = 0; i < n; i++) {
    if (a[i].name == name) {
      cout << a[i].name << endl;
      return true;
    }
  }
  return false;
}

void writeToFile(struct Student a[], int n, const char *nameFile) {
  fstream fout(nameFile);

  if (!fout.is_open()) {
    cout << "Failed to open file for writing." << endl;
    return;
  }

  for (int i = 0; i < n; i++) {
    fout << a[i].name << ", " << a[i].age << ", " << a[i].gpa << endl;
  }

  fout.close();
}

int readFromFile(const char *nameFile, struct Student b[]) {
  fstream fin;
  string s;
  int m, n, i = 0;
  fin.open(nameFile);

  while (getline(fin, s)) {
    n = s.find(',');
    b[i].name = s.substr(0, n);
    m = s.find(',', n + 1);
    b[i].age = stoi(s.substr(n + 2, m - n - 2));
    b[i].gpa = stof(s.substr(m + 2));
    i++;
  }
  fin.close();
  return i;
}

void listOfGoodStudent(struct Student a[], int n) {
  cout << endl;
  for (int i = 0; i < n; i++) {
    if (a[i].gpa >= 8) {
      cout << a[i].name << ": " << a[i].gpa << " (good)" << endl;
    }
  }
}

int appendStudent(struct Student a[], int n, struct Student s) {
  a[n] = s;
  return n + 1;
}

int countFirstName(struct Student a[], int n, string firstName) {
  int d = 0;
  for (int i = 0; i < n; i++) {
    size_t space = a[i].name.find(' ');
    string first = a[i].name.substr(0, space);
    if (first == firstName) {
      d++;
    }
  }
  return d;
}

int main(int argc, char *argv[]) {
  struct Student a[100];
  struct Student b[100];
  string name;

  // input and print to console
  inputListOfStudent(a, 3);
  printListOfStudent(a, 3);

  // write to file
  writeToFile(a, 3, "student.txt");

  // read from file
  cout << "Read from file Student.txt";
  int n = readFromFile("student.txt", b);
  printListOfStudent(b, n);

  // search
  cout << "Input name to find: ";
  getline(cin, name);
  if (!findStudent(a, 3, name)) {
    cout << "Not found" << endl;
  }

  // list good student
  listOfGoodStudent(a, 3);

  // add new student
  cout << "\nAdd new Student" << endl;
  struct Student newStudent;
  inputStudent(newStudent);
  int num = appendStudent(a, 3, newStudent);
  cout << "List of students after appending a new student:" << endl;
  printListOfStudent(a, num);

  // cout first name
  cout << "\nInput the first name you want to count: ";
  string firstName;
  cin.ignore();
  getline(cin, firstName);
  cout << firstName << ": " << countFirstName(a, num, firstName) << endl;

  return 0;
}
// Le Nhat Truong
// 20
// 8.4
// Lam Thi Huu Hanh
// 46
// 7.6
// Le Minh Hoi
// 47
// 9.9
