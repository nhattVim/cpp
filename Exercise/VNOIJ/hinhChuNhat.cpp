// Cho một ma trận 2 chiều có n dòng và m cột. Viết chương trình tính tổng của hình chữ nhật có
// ô bên trái là (u, v) và ô dưới bên phải là (g, h)
// Input:
//     + Dòng đầu tiên là số nguyên n m k (n, m, k < 10^5) là số dòng và số cột của ma trận và k là số hình chữ nhật con cần tính tổng
//     + n dòng tiếp theo mỗi dòng chứa m số nguyên (<10^9) là ma trận ban đầu, các số cách nhau bởi dấu cách
//     + k dòng tiếp theo mỗi dòng chứa 4 số u v g h
// Output: In ra k dòng, dòng thứ i là tổng của hình chữ nhật tương ứng đầu vào

// Input:
// 5 4 3
// 1 0 0 1
// 1 1 2 0
// 1 2 2 1
// 1 1 2 3
// 1 1 3 2
// 0 0 1 1
// 1 1 2 3
// 0 0 4 3
// Output:
// 3
// 8
// 26

#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

using namespace std;

int main() {
    IOS;
    freopen("hcn.inp", "r", stdin);
    freopen("hcn.out", "w", stdout);

    int x1A, y1A, x2A, y2A;
    cin >> x1A >> y1A >> x2A >> y2A;

    int x1B, y1B, x2B, y2B;
    cin >> x1B >> y1B >> x2B >> y2B;

    int areaA = (x2A - x1A) * (y2A - y1A);
    int areaB = (x2B - x1B) * (y2B - y1B);

    int overlapWidth = max(0, min(x2A, x2B) - max(x1A, x1B));
    int overlapHeight = max(0, min(y2A, y2B) - max(y1A, y1B));
    int overlapArea = overlapWidth * overlapHeight;

    cout << areaA + areaB - overlapArea << endl;

    return 0;
}
