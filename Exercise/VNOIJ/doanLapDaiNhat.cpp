// Cho 1 chuỗi DNA gồm các ký tự A, C, G và T. Nhiệm vụ của bạn là tìm đoạn lặp
// lại nhiều nhất trong chuỗi DNA
// Input: Gồm 1 dòng chứa chuỗi DNA độ dài n
// Output: In ra độ dài của đoạn lặp lại nhiều nhất

// Input:
// ATTCGGGA

// Output:
// 3
#include <bits/stdc++.h>

using namespace std;

int main() {
    string dna;
    cin >> dna;

    int current_length = 1;
    int max_length = 1;

    for (auto i = 1; i < dna.length(); ++i) {
        if (dna[i] == dna[i - 1]) {
            current_length++;
        } else {
            current_length = 1;
        }

        max_length = max(max_length, current_length);
    }

    cout << max_length << endl;

    return 0;
}

