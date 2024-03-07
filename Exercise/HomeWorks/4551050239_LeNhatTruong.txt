// Câu 1
#include <bits/stdc++.h>

using namespace std;

int main (int argc, char *argv[]) {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cout << right << setw(3) << setfill('0') << i << endl;
    }
    return 0;
}

// Câu 2
#include <bits/stdc++.h>

using namespace std;

const double PI = M_PI;
int main (int argc, char *argv[]) {
    int n;
    cin >> n;
    cout << fixed << setprecision(n) << PI;
    return 0;
}

// Câu 3
#include <bits/stdc++.h>
#define fu(i,a,b) for(int i = a; i < b; i++)

using namespace std;

struct Student {
    string name;
    short age;

    void getInfo(){
        cout << "Name: "; 
        cin.ignore();
        getline(cin, name);
        cout << "Age: ";
        cin >> age;
    }

    void displayInfo(int x) const {
        cout << x << setw(10) << name << setw(6) << age << endl;
    }
};

int main (int argc, char *argv[]) {
    int n;
    cout << "Enter number of student: ";
    cin >> n;

    vector<Student> v;
    fu(i,0,n){
        Student s;
        s.getInfo();
        v.push_back(s);
    }

    cout << "---LIST OF STUDENT---" << endl;

    fu(i,0,n){
        v[i].displayInfo(i);
    }

    cout << endl;

    string searchName;
    cout << "Enter a name: ";
    cin.ignore();
    getline(cin, searchName);

    int count = 0;
    fu(i,0,n){
        if(v[i].name == searchName)
            count++;
    }
    cout << "There's " << count << " student which's name " << searchName << endl;

    int sum = 0;
    fu(i,0,n){
        sum += v[i].age;
    }
    cout << "Average of age is " << fixed << setprecision(3) << 1.0 * sum/n;
    
    return 0;
}
