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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int a, b, d = 0;
    cin >> a >> b;
    fu(i,a,b+1){
        if (prime_number(i) == true && (i == reverse_num(i))) {
            d++;
        }
    }
    cout << d;
    
    return 0;
}
