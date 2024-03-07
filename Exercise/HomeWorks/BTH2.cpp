#include <bits/stdc++.h>
#define fu(i,a,b) for(int i = a; i < b; i++)

using namespace std;

bool prime_number(int n){
    if (n < 2) {
        return false;
    }
    fu(i,2,n){
        if (n % i == 0) {
            return false;
        }
    }
        return true;
}

bool perfect_number(int n){
    int sum = 0;
    fu(i,1,n){
    if (n % i == 0) {
            sum += i;
        }
    }
    if (sum == n) {
        return true;
    } else {
        return false;
    }
}

int reverse_num(int n){
    int reverse_num = 0;
    while(n != 0){
        int temp = n % 10;
        reverse_num = reverse_num * 10 + temp;
        n /= 10;
    }
    return reverse_num;
}

int main (int argc, char *argv[]) {
    int n;
    cin >> n;

    vector<int> a(n);

    fu(i,0,n){
        cin >> a[i];
    }
    cout << endl;

    // Câu 1
    int sum = 0, d = 0;
    fu(i,0,n){
        sum += a[i];
        d++;
    }
    float average = 1.0 * sum / d;
    cout << average << endl << endl;

    // Câu 2
    d = 0;
    fu(i,0,n){
        if (prime_number(a[i])) {
            d++;
        }
    }
    cout << d << endl;
    fu(i,0,n){
        if (prime_number(a[i])) {
            cout << a[i] << " ";
        }
    }
    cout << endl << endl;
    
    // Câu 3
    d = 0;
    fu(i,0,n){
        if (perfect_number(a[i])) {
            d++;
        }
    }
    cout << d << endl;
    fu(i,0,n){
        if (perfect_number(a[i])) {
            cout << a[i] << " ";
        }
    }
    cout << endl << endl;

    // Câu 4
    vector<int> backup = a;
    sort(a.begin(), a.end());
    fu(i,0,n){
        cout << a[i] << " ";
    }
    cout << endl << endl;
    
    // Câu 5
    a = backup;
    int max = 0, temp = 0;
    fu(i,0,n){
        if (a[i] > max) {
            max = a[i];
            temp = i + 1;
        }
    }
    cout << max << " " << temp << endl << endl;

    // Câu 6
    fu(i,0,n){
        a[i] = reverse_num(a[i]);
        cout << a[i] << " ";
    }
    cout << endl << endl;

    // Câu 7
    d = 0;
    fu(i,0,n){
        if (a[i] == reverse_num(a[i])) {
            d++;
        }
    }
    cout << d << endl;
    fu(i,0,n){
        if (a[i] == reverse_num(a[i])) {
            cout << a[i] << " ";
        }
    }
    cout << endl << endl;

    // Câu 8
    int min_gap = abs(a[0] - average), closest_num = a[0];
    fu(i,0,n){
        int gap = abs(a[i] - average);
        if (gap < min_gap) {
            min_gap = gap;
            closest_num = a[i];
        }
    }
    cout << closest_num;

    return 0;
}
