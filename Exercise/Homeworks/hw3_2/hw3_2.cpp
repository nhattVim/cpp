#include <bits/stdc++.h>

using namespace std;

struct Student {
    string MaSV;
    string hoTen;
    string ngaySinh;
    string queQuan;
    string truongPT;
    string tenNganh;
};

void inputListOfStudent(const char *filename, vector<Student> &v) {
    fstream f;
    string str;

    f.open(filename);
    if (f.is_open()) {
        while (getline(f, str)) {
            stringstream ss(str);
            vector<string> data;

            string word;
            while (getline(ss, word, ',')) {
                data.push_back(word);
            }

            Student temp;
            temp.MaSV = data[0];   
            temp.hoTen= data[1];   
            temp.ngaySinh= data[2];   
            temp.queQuan= data[3];   
            temp.truongPT = data[4];   
            temp.tenNganh = data[5];   

            v.push_back(temp);
        }
    } else {
        cout << "Could not open file" << filename << endl;
    }
    f.close();
}

void outputStudentToConsole(Student s) {
    cout << "MaSV: " << s.MaSV << endl;
    cout << "Ho ten: " << s.hoTen << endl;
    cout << "Ngay sinh: " << s.ngaySinh << endl;
    cout << "Que quan: " << s.queQuan << endl;
    cout << "Truong pho thong: " << s.truongPT << endl;
    cout << "Ten nganh: " << s.tenNganh << endl;
    cout << "-------------------" << endl;
}

void outputListOfStudentToConsole(vector<Student> v) {
    for (Student s : v) {
        outputStudentToConsole(s);
    }
}

void outputListOfStudentToFileWithAddressCondition(const char *filename, vector<Student> v) {
    fstream f(filename);
    if (f.is_open()) {
        for (Student s : v) {
            if (s.queQuan == "Bình Định") {
                f << "-------------------------" << endl;
                f << "MaSV: " << s.MaSV << endl;
                f << "Ho ten: " << s.hoTen << endl;
                f << "Ngay sinh: " << s.ngaySinh << endl;
                f << "Que quan: " << s.queQuan << endl;
                f << "Truong PT: " << s.truongPT << endl;
                f << "Ten nganh: " << s.tenNganh << endl;
            }
        }
    } else {
        cout << "Can not open file " << filename << endl;
    }
    f.close();
}

int main (int argc, char *argv[]) {
    vector<Student>  v;

    // 1
    inputListOfStudent("danhsach.txt", v);
    outputListOfStudentToConsole(v);

    // 2
    outputListOfStudentToFileWithAddressCondition("dsBinhDinh.txt", v);

    // 3
    Student newStudent;
    cout << "\n\nInitial new student\n\n";
    cout << "Ma SV: "; getline(cin, newStudent.MaSV);
    cout << "Ho ten: "; getline(cin, newStudent.hoTen);
    cout << "Ngay sinh: "; getline(cin, newStudent.ngaySinh);
    cout << "Que quan: "; getline(cin, newStudent.queQuan);
    cout << "Truong PT: "; getline(cin, newStudent.truongPT);
    cout << "Ten nganh: "; getline(cin, newStudent.tenNganh);
    cout << "\n\nStudent to add append to file\n\n";
    outputStudentToConsole(newStudent);
    v.push_back(newStudent);
    cout << "\n\nList of student after append\n\n";

    return 0;
}
