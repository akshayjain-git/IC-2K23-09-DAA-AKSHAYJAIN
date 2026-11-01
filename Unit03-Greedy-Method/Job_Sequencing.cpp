#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Job {
    char id;
    int deadline;
    int profit;
};

bool cmp(Job a, Job b) {
    return a.profit > b.profit;
}

int main() {
    int n;
    cout << "Enter number of jobs: ";
    cin >> n;

    vector<Job> jobs(n);
    cout << "Enter job id, deadline and profit:" << endl;
    for (auto &job : jobs) cin >> job.id >> job.deadline >> job.profit;

    sort(jobs.begin(), jobs.end(), cmp);

    int maxDeadline = 0;
    for (auto job : jobs) maxDeadline = max(maxDeadline, job.deadline);

    vector<char> slots(maxDeadline + 1, '-');
    int totalProfit = 0;

    for (auto job : jobs) {
        for (int j = job.deadline; j >= 1; j--) {
            if (slots[j] == '-') {
                slots[j] = job.id;
                totalProfit += job.profit;
                break;
            }
        }
    }

    cout << "Selected jobs: ";
    for (int i = 1; i <= maxDeadline; i++)
        if (slots[i] != '-') cout << slots[i] << " ";

    cout << "\nMaximum profit = " << totalProfit << endl;
    return 0;
}
