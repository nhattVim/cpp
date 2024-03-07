// Thuật toán lạ kỳ được phát biểu như sau: cho 1 số nguyên dương n, Nếu n chẵn thì chia cho 2, nếu n lẻ
// thì nhân nó với 3 và cộng thêm 1. Thuật toán này lặp lại cho đến khi n bằng 1.
// Ví dụ: n = 3 khi đó các số sinh ra theo thuật toán lạ kì như sau:3 -> 10 -> 5 -> 16 -> 8 -> 4 -> 2 -> 1
// Nhiệm vụ của bạn là mô tả quá trình thực thi của thuật toán từ 1 số n cho trước.
// Input: Gồm 1 dòng duy nhất chứa số nguyên n
// Output: In ra 1 dòng bao gồm các số sinh ra trong quá trình thực thi thuật toán

#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

using namespace std;

int main (int argc, char *argv[]) {
    IOS;
    long long n; cin >> n;
    cout << n << " ";
    while (n != 1) {
        if (n % 2 == 0) {
            n /= 2;
        } else {
            n = n * 3 + 1;
        }
        cout << n << " ";
    }
    return 0;
}

