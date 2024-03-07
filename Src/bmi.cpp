#include <bits/stdc++.h>

using namespace std;

struct Con_nguoi {
    string ho_ten;
    int tuoi;
    float chieu_cao;
    float can_nang;
};

void chi_so_BMI(Con_nguoi nguoi){
    float bmi = nguoi.can_nang / (nguoi.chieu_cao * nguoi.chieu_cao);
    cout << "Chi so BMI cua ban " << nguoi.ho_ten << " la: " << fixed << setprecision(2) << bmi << endl;
    if (bmi <= 15.0) {
        cout << "Ban thieu can rat nang" << endl;
    } else if (bmi >= 16.0 and bmi < 18.5) {
        cout << "Ban thieu can" << endl;
    } else if (bmi >= 18.5 and bmi < 25.0) {
        cout << "Ban binh thuong" << endl;
    } else if (bmi >= 25.0 and bmi < 30.0) {
        cout << "Ban tien beo phi" << endl;
    } else if (bmi >= 30.0 and bmi < 35.0) {
        cout << "Ban thua can cap I" << endl;
    } else if (bmi >= 35.0 and bmi < 40.0) {
        cout << "Ban thua can cap do II" << endl;
    } else {
        cout << "Ban thua can cap do III" << endl;
    }
}

int main (int argc, char *argv[]) {
    Con_nguoi nguoi;

    cout << "Nhap ten cu ban: ";
    cin >> nguoi.ho_ten;

    cout << "Nhap chieu cao cua ban: ";
    cin >> nguoi.chieu_cao;
    
    cout << "Nhap can nang cua ban: ";
    cin >> nguoi.can_nang;

    chi_so_BMI(nguoi);
    return 0;
}
