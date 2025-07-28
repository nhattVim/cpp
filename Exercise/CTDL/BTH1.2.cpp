#include <bits/stdc++.h>
using namespace std;

// -------------------- Aliases --------------------
typedef long long ll;
typedef vector<int> vi;

// -------------------- Fast IO --------------------
void fastIO() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

// -------------------- Utility Functions --------------------
void inputArr(int a[], int n, const string &label = "a") {
    cout << "\n--- Nhập mảng " << label << " ---\n";
    for (int i = 0; i < n; i++) {
        cout << "  " << label << "[" << i << "]: " << flush;
        cin >> a[i];
    }
}

void printArr(const int a[], int n, const string &label = "Mảng") {
    cout << label << " (" << n << " phần tử): ";
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << "\n";
}

int maxArr(const int a[], int n) {
    return *max_element(a, a + n);
}

float avgArr(const int a[], int n) {
    int sum = accumulate(a, a + n, 0);
    return static_cast<float>(sum) / n;
}

bool findArr(const int a[], int n, int x) {
    return find(a, a + n, x) != a + n;
}

int extractEvenNum(const int a[], int n, int b[]) {
    int k = 0;
    for (int i = 0; i < n; i++)
        if (a[i] % 2 == 0)
            b[k++] = a[i];
    return k;
}

void sortArr(int a[], int n) {
    sort(a, a + n);
}

int mergeArr(const int a[], int n, const int b[], int m, int c[]) {
    int i = 0, j = 0, k = 0;
    while (i < n && j < m)
        c[k++] = (a[i] < b[j]) ? a[i++] : b[j++];
    while (i < n)
        c[k++] = a[i++];
    while (j < m)
        c[k++] = b[j++];
    return k;
}

int countNumOfEachElement(const int a[], int n, int b[], int d[]) {
    int k = 0;

    for (int i = 0; i < n; ++i) {
        bool isNew = true;

        for (int j = 0; j < k; ++j) {
            if (a[i] == b[j]) {
                isNew = false;
                break;
            }
        }

        if (isNew) {
            b[k] = a[i];
            d[k] = 1;
            for (int j = i + 1; j < n; ++j) {
                if (a[j] == a[i])
                    d[k]++;
            }
            ++k;
        }
    }

    return k;
}

// -------------------- Main Logic --------------------
void solve() {
    cout << "Nhập số lượng phần tử mảng a: " << flush;
    int n;
    cin >> n;
    int a[n];

    inputArr(a, n, "a");
    cout << '\n';
    printArr(a, n, "Mảng a");

    cout << "\n→ Giá trị lớn nhất: " << maxArr(a, n);
    cout << "\n→ Trung bình cộng: " << fixed << setprecision(2) << avgArr(a, n);

    int x;
    cout << "\n\nNhập số cần tìm: " << flush;
    cin >> x;
    cout << "→ " << (findArr(a, n, x) ? "Tìm thấy " : "Không tìm thấy ") << x
         << " trong mảng.\n"
         << flush;

    int evenArr[100], evenCount = extractEvenNum(a, n, evenArr);
    cout << "\n→ Mảng chứa các số chẵn:\n";
    if (evenCount > 0)
        printArr(evenArr, evenCount, "Mảng chẵn");
    else
        cout << "Không có số chẵn nào.\n";

    cout << "\n→ Mảng a sau khi sắp xếp tăng dần:\n";
    sortArr(a, n);
    printArr(a, n, "a (đã sắp xếp)");

    int b[100], n2;
    cout << "\nNhập số lượng phần tử mảng b: " << flush;
    cin >> n2;
    inputArr(b, n2, "b");

    int merged[200];
    int mergedLen = mergeArr(a, n, b, n2, merged);
    cout << "\n→ Mảng sau khi trộn a và b (đã sắp xếp):\n";
    printArr(merged, mergedLen, "Merged");

    cout << "\nĐếm số lần xuất hiện của các số trong mảng:\n";
    int c[100], d[100];
    int count = countNumOfEachElement(a, n, c, d);
    printArr(a, n, "Mảng a");
    printArr(c, count, "Mảng cơ sở c của a");
    printArr(d, count, "Mảng số lần xuất hiện d của c trong a");
}

// -------------------- Entry --------------------
int main() {
    fastIO();
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}
