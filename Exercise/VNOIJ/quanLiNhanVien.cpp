// Công ty XYZ có n nhân viên, mỗi nhân viên gồm các thông tin: tên, năm sinh, số năm làm việc, hệ số lương.
// Có q truy vấn, bao gồm các loại như sau:
//         C: cho biết có bao nhiêu nhân viên trong công ty XYZ
//         F name: cho biết có bao nhiêu nhân viên tên name trong công ty
//         S x: cho biết có bao nhiêu nhân viên làm việc từ x năm trở lên
//         I name year: thêm nhân viên có tên name sinh năm year vào trong cơ sở dữ liệu (hệ số lương khởi điểm là 2.34)
// Viết chương trình đọc từ dữ liệu đầu vào và trả lời các truy vấn. Kết quả của mỗi truy vấn in trên 1 dòng.
// Input: 
//     Dòng đầu tiên chứa số n là số nhân viên và q là số truy vấn (1 < n, q < 105)
//     n dòng tiếp theo mỗi dòng chứa 4 thông tin tên, năm sinh, số năm làm việc và hệ số lương các nhau bởi dấu cách
//     q dòng tiếp theo chứa các truy vấn
// Output: Ghi ra kết quả của các truy vấn
//
// Example:
// Input:
// 5 4
// Nam 1999 3 3
// Binh 1987 10 4.34
// An 2000 2 2.63
// Nga 2003 3 3.1
// Ha 1993 7 4
// I Lan 1999
// C
// F Ha
// S 3
//
// Output: 6
//         1
//         4

#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define pb push_back

using namespace std;

struct Employee {
    string name;
    int birthYear;
    int yearWorked;
    float salary;
};

int main (int argc, char *argv[]) {
    IOS;
    int n, q; cin >> n >> q;

    vector<Employee> v;
    for (int i = 0; i < n; i++) {
        Employee temp;
        cin >> temp.name >> temp.birthYear >> temp.yearWorked >> temp.salary;
        v.pb(temp);
    }

    for (int i = 0; i < q; i++) {
        char c;
        cin >> c;
        if (c == 'C') {
            cout << v.size() << endl;
        } else if(c == 'F'){
            string name;
            cin >> name;
            int d = 0;
            for (auto x : v) {
                if (x.name == name) {
                    d++;
                }
            }
        //     for (int i = 0; i < n; i++) {
        //         string name;
        //         cin >> name;
        //         int d = 0;
        //         if (v[i].name == name) {
        //             d++;
        //         }
        //     }
            cout << d << endl;
        } else if (c == 'S'){
            int x, d = 0; cin >> x;
            for (auto t : v) {
                if (t.yearWorked >= x) {
                    d++;
                }
            }
            // for (int i = 0; i < n; i++) {
            //     if (v[i].yearWorked >= x) {
            //         d++
            //     }
            // }
            cout << d << endl;
        } else if (c == 'I') {
            string name;
            int year;
            cin >> name >> year;
            Employee temp;
            temp.name = name;
            temp.yearWorked = 0;
            temp.birthYear = year;
            temp.salary = 2.34;
            v.pb(temp);
        }
    }

    return 0;
}

// #include <bits/stdc++.h>
// #define rep(i,a,b) for (int i = a; i < b; ++i)
// #define int long long
// #define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
// #define endl "\n"
//
// using namespace std;
//
// struct Xyz {
//     string name;
//     int bYear;
//     int yOfW;
//     double salaryCoefficient;
// };
//
//
// signed main(){
//     IOS;
//     int n,q;
//     cin >> n >> q;
//
//
//     vector<Xyz> Xyzs(n);
//     map<string,int> nameCount;
//     map<int, int> yOfWCount;
//
//     rep(i,0,n) {
//         cin >> Xyzs[i].name >> Xyzs[i].bYear >> Xyzs[i].yOfW >> Xyzs[i].salaryCoefficient;
//         ++nameCount[Xyzs[i].name];
//         ++yOfWCount[Xyzs[i].yOfW];
//     }
//
//
//
//     rep(i,0,q){
//         char qType;
//         cin >> qType;
//
//         if(qType == 'C')
//             cout << n << endl;
//
//             else if (qType == 'F'){
//                 string name;
//                 cin >> name;
//                 cout << nameCount[name] << endl;
//             } else if (qType == 'S') {
//                     int x;
//                     cin >> x;
//
//                     int count = 0;
//                     for (const auto& pair : yOfWCount)
//                         if (pair.first >= x)
//                                 count += pair.second;
//
//                 cout << count << endl;
//             } else  if (qType == 'I') {
//                     string name;
//                     int year;
//                     cin >> name >> year;
//
//                     Xyz newXyz{name, year, 0, 2.34};
//                     Xyzs.push_back(newXyz);
//                     ++nameCount[name];
//                     ++yOfWCount[0];
//                     ++n;
//                 }
//             }
//     return 0;
// }
