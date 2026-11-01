#include <iostream>
#include <vector>
using namespace std;

pair<int,int> findMaxMin(const vector<int>& a, int low, int high) {
    if (low == high) return {a[low], a[low]};
    if (high == low + 1) {
        if (a[low] < a[high]) return {a[high], a[low]};
        return {a[low], a[high]};
    }

    int mid = (low + high) / 2;
    auto left = findMaxMin(a, low, mid);
    auto right = findMaxMin(a, mid + 1, high);

    int maximum = max(left.first, right.first);
    int minimum = min(left.second, right.second);
    return {maximum, minimum};
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> a(n);
    cout << "Enter elements: ";
    for (int &x : a) cin >> x;

    auto result = findMaxMin(a, 0, n - 1);
    cout << "Maximum = " << result.first << endl;
    cout << "Minimum = " << result.second << endl;
    return 0;
}
