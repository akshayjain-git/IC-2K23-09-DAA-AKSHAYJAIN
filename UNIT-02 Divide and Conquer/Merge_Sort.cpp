#include <iostream>
#include <vector>
using namespace std;

void mergeArrays(vector<int>& a, int l, int m, int r) {
    vector<int> left(a.begin() + l, a.begin() + m + 1);
    vector<int> right(a.begin() + m + 1, a.begin() + r + 1);

    int i = 0, j = 0, k = l;
    while (i < (int)left.size() && j < (int)right.size()) {
        if (left[i] <= right[j]) a[k++] = left[i++];
        else a[k++] = right[j++];
    }
    while (i < (int)left.size()) a[k++] = left[i++];
    while (j < (int)right.size()) a[k++] = right[j++];
}

void mergeSort(vector<int>& a, int l, int r) {
    if (l >= r) return;
    int m = l + (r - l) / 2;
    mergeSort(a, l, m);
    mergeSort(a, m + 1, r);
    mergeArrays(a, l, m, r);
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    vector<int> a(n);
    cout << "Enter elements: ";
    for (int &x : a) cin >> x;

    mergeSort(a, 0, n - 1);

    cout << "Sorted array: ";
    for (int x : a) cout << x << " ";
    cout << endl;
    return 0;
}
