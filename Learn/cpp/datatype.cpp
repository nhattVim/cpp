// KIỂU DỮ LIỆU
// n bit => -2^(n-1) -> 2^(n - 1) - 1
//
// số nguyên:
//     + int: 4byte = 32bit : -2^31 -> 2^31 - 1
//     + long long: 8byte = 64bit : -2^63 -> 2^63-1
//     + unsigned int : 0 -> 2^32 - 1
//     + unsigned long long : 0 -> 2^64 - 1
// số thực:
//     + float: 4byte
//     + double: 8byte
//
// char: 1byte = 8bit : 2^8 = 256 : 0 -> 255
// bool: 1byte : true, false

#include <bits/stdc++.h>

using namespace std;

int main (int argc, char *argv[]) {
    cout << INT_MIN << " " << INT_MAX << endl;
    cout << LLONG_MIN << " " << LLONG_MAX << endl;
    float a = 1.876;
    cout << fixed << setprecision(4) << a << endl;
    char x = 't'; // nháy đơn là kí tự nháy kép là xâu
    cout << x;
    int b = 4, c = 7;
    float f = 1.0 * b/c;
    cout << f << "\n";

    // increse operator ++i, i++ && decrese operator --i, i++
    int i = 100;
    int z = i++; // z = 100, i -> 101
    i = 100;
    int v = ++i; // i -> 101, v = i = 101;
    cout << z << " " << v << endl;
    return 0;
}
