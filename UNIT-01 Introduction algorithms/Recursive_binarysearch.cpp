#include <iostream>
#include <vector>
using namespace std;
int binarySearchRecursive(vector<int>& arr, int low, int high, int key) {

    if (low > high)
        return -1;

    int mid = low + (high - low) / 2;

    if (arr[mid] == key)
        return mid;

    else if (arr[mid] < key)
        return binarySearchRecursive(arr, mid + 1, high, key);

    else
        return binarySearchRecursive(arr, low, mid - 1, key);
}
