#include <bits/stdc++.h>

using namespace std;

void chan_le(int n){
    if (n % 2 == 0) {
        cout << "Chan" << endl;
    } else {
        cout << "Le" << endl;
    }
}

void thap_luc_phan(int n, char result[]){
    for (int i = 0; n > 0; i++) {
        int x = n % 16;
        n = n / 16;
        if (x < 10){
            result[i] = x + '0';
        } else {
            result[i] = x - 10 + 'A';
        }
    }
    strrev(result);
    cout << result << endl;
}

bool so_nguyen_to(int n){
    int d = 0;
    if (n < 2) {
        return false;
    }
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) {
            d++;
        }
    }
    if (d == 0) {
        return true;
    } else {
        return false;
    }
}

void so_hoan_hao(int n){
    int sum = 0;
    for (int i = 1; i < n; i++) {
        if (n % i == 0) {
            sum = sum + i;
        }
    }
    if (sum == n) {
        cout << "La so hoan hao" << endl;
    } else {
        cout << "Khong phai so hoan hao" << endl;
    }
}

void so_nguyen_to_nho_hon_n(int n){
    int d = 0;
    for (int i = 0; i < n; i++) {
        if (so_nguyen_to(i) == true) {
            d++;
        }
    }
    cout << "Co " << d << " so nguyen to nho hon " << n << endl;
}

void tong_uoc_nho_hon_n_la_snt(int n){
    int d = 0;
    for (int i = 1; i < n; i++) {
        int sum = 0;
        for (int j = 1; j <= i; j++) {
            if (i % j == 0) {
                sum = sum + j;
            }
        }
        if (so_nguyen_to(sum) == true) {
            // cout << i << " " << endl; /* test */
            d++;
        }
    }
    cout << "Co " << d << " so nho hon " << n << " va co tong cac uoc la so nguyen to" << endl;
}

int tong_cac_chu_so(int n){
    int sum = 0;
    while (n > 0) {
        sum = sum + (n % 10);
        n = n / 10;
    }
    return sum;
}

void tong_chu_so_nho_hon_n_la_snt(int n){
    int d = 0;
    for (int i = 0; i < n; i++) {
        if (so_nguyen_to(tong_cac_chu_so(i))) {
            d++;
            // cout << i << " " << endl; /* test */
        }
    }
    cout << "Co " << d << " so nho hon " << n << " va co tong cac chu so la so nguyen to" << endl;
}

void so_random(int n){
    srand(time(0));
    long long num1 = 0;
    for (int i = 0; i < n; i++) {
        num1 = num1 * 10 + (rand() % 10);
    }
    long long  num2 = 0;
    for (int i = 0; i < n; i++) { 
        num2 = num2 * 10 + (rand() % 10);
    }
    cout << "So random lan luot la: " << num1 << " " << num2 << endl;
    cout << "Tong: " << num1 + num2 << endl;
    cout << "Hieu: " << num1 - num2 << endl;
    cout << "Tich: " << num1 * num2 << endl;
    cout << "Thuong: " << (double)num1 / num2 << endl;
}

int main (int argc, char *argv[]) {
    int n;
    char result[20];
    cin >> n;

    /* cau 1 */chan_le(n);

    /* cau 2 */thap_luc_phan(n,result);

    /* cau 3 */ if (so_nguyen_to(n) == true) {
                    cout << "La so nguyen to" << endl;
                } else {
                    cout << "Khong phai so nguyen to" << endl;
                }

    /* cau 4 */so_hoan_hao(n);

    /* cau 5 */so_nguyen_to_nho_hon_n(n);

    /* cau 6 */tong_chu_so_nho_hon_n_la_snt(n);

    /* cau 7 */tong_uoc_nho_hon_n_la_snt(n);

    /* cau 8 */so_random(n);

    return 0;
}
