// Cho Số nguyên dương n (n <= 2 000 000 000). Hãy xác định xem trong phạm vi từ 1 đến n có bao nhiêu số mà trong dạng biểu diễn nhị
// phân của nó có đúng k chữ số 0 có nghĩa (giá trị của k không vượt quá 32)
// Input: Gồm 1 dòng chứa hai số nguyên n và k
// Output: Ghi ra số lượng các số tìm được

// Input: 
// 18 3
// Output:
// 3

#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

using namespace std;

int countNumbersWithKZero(int n, int k) {
    int count = 0;

    for (int i = 1; i <= n; i++) {
        int numZero = 0;
        int num = i;

        while (num > 0) {
            if (num % 2 == 0) {
                numZero++;
            }
            num /= 2;
        }

        if (numZero == k) {
            count++;
        }
    }

    return count;
}

int main() {
    IOS;

    int n, k;
    cin >> n >> k;

    int result = countNumbersWithKZero(n, k);
    cout << result << endl;

    return 0;
}
