// abs(x): Giá trị tuyệt đối
// pow(a, b): Tinh a^b, trả về số double
// sqrt(n): Tính căn bậc hai của n và trả về số double
// round(a): Làm tròn số

#include <bits/stdc++.h>
#define fu(i,a,b) for(int i = a; i < b; i++)

using namespace std;

int main(){
    
    int x = -100, y = abs(x);
    cout << y << endl;

    int a = 2, b = 3;
    int res = pow(a, b);
    cout << res << endl;

    int q = 16;
    int can = sqrt(q);
    cout << can << endl;

    float s = 1.5632;
    int f = round(s);
    cout << f << endl;

    return 0;
}
