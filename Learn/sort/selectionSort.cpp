#include <bits/stdc++.h>

using namespace std;

// O(n^2)
void selectionSort (int a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min = i;
        for (int j = i + 1 ; j < n; j++) {
            if (a[j] < a[min]) {
                min = j;
            }
        }
        swap(a[i], a[min]);
    }
}

int main (int argc, char *argv[]) {
    int a[] = {1, 2, 4, 7, 2, 3, 8, 9, 4};
    selectionSort(a, 9);
    for (int x : a) {
        cout << x << " ";
    }
    return 0;
}
