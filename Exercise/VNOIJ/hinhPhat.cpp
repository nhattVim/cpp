// HÌNH PHẠT: Trong giờ học thể dục, bạn Nam gây mất trật tự nên bị thầy giáo phạt. Hình phạt của thầy 
// như sau: bạn Nam đứng nghiêm, khi thầy hô "trái" thì Nam bước sang trái một mét, thầy 
// hô "phải" thì Nam bước sang phải một mét. Hỏi sau N lần thầy hô như vậy thì bạn Nam 
// cách xa vị trí ban đầu bao nhiêu mét?
// Input: 
//     - Dòng đầu tiên là số N
//     - Dòng tiếp theo gồm n số 1 hoặc 2 cách nhau bởi 1 khoảng trắng. Nếu số 1 tương ứng thầy hô sang trái, số 2 tương ướng thầy hô
//     sang phải
// Ouput: Ghi ra một số nguyên duy nhất là khoảng cách của Nam sau N lần hô so với giá trị ban đầu
// Example:
//     Input:  4
//             1 1 2 1
//     Output: 2

#include <bits/stdc++.h>

using namespace std;

int main (int argc, char *argv[]) {
    int n, temp = 0, vt = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> temp;
        if (temp == 1) {
            vt -= 1;
        } else {
            vt += 1;
        }
    }
    cout << abs(vt);
    return 0;
}
