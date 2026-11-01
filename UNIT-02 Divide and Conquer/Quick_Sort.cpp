#include <iostream>
#include <vector>
#include <chrono>
#include <cstdlib>
using namespace std;
using namespace chrono;

int partitionArray(vector<int>& a, int low, int high) {
    int pivot = a[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (a[j] <= pivot) {
            i++;
            swap(a[i], a[j]);
        }
    }
    swap(a[i + 1], a[high]);
    return i + 1;
}

void quickSort(vector<int>& a, int low, int high) {
    if (low < high) {
        int p = partitionArray(a, low, high);
        quickSort(a, low, p - 1);
        quickSort(a, p + 1, high);
    }
}

bool isSorted(const vector<int>& a) {
    for (int i = 1; i < (int)a.size(); i++)
        if (a[i - 1] > a[i]) return false;
    return true;
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) a[i] = rand() % 100000;

    auto start = high_resolution_clock::now();
    quickSort(a, 0, n - 1);
    auto stop = high_resolution_clock::now();

    auto time = duration_cast<microseconds>(stop - start);
    cout << "Sorted correctly: " << (isSorted(a) ? "Yes" : "No") << endl;
    cout << "Time taken: " << time.count() << " microseconds" << endl;
    return 0;
}
