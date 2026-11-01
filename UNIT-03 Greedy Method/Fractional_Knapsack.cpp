#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Item {
    int value, weight;
};

bool cmp(Item a, Item b) {
    return (double)a.value / a.weight > (double)b.value / b.weight;
}

int main() {
    int n, capacity;
    cout << "Enter number of items: ";
    cin >> n;

    vector<Item> items(n);
    cout << "Enter value and weight of each item:" << endl;
    for (auto &item : items) cin >> item.value >> item.weight;

    cout << "Enter knapsack capacity: ";
    cin >> capacity;

    sort(items.begin(), items.end(), cmp);

    double totalValue = 0;
    for (auto item : items) {
        if (capacity == 0) break;
        if (item.weight <= capacity) {
            capacity -= item.weight;
            totalValue += item.value;
        } else {
            totalValue += item.value * ((double)capacity / item.weight);
            capacity = 0;
        }
    }

    cout << "Maximum value = " << totalValue << endl;
    return 0;
}
