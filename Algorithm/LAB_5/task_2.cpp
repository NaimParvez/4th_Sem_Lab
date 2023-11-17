
#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

struct Job {
    int profit;
    int deadline;
};

bool compareJobs(Job j1, Job j2) {
    return j1.profit > j2.profit;
}

int main() {
    ifstream input("jobsequence.txt");

    int n;
    input >> n;

    Job jobs[n];
    for (int i = 0; i < n; i++) {
        input >> jobs[i].profit;
    }
    for (int i = 0; i < n; i++) {
        input >> jobs[i].deadline;
    }

    sort(jobs, jobs + n, compareJobs);

    int maxDeadline = 0;
    for (int i = 0; i < n; i++) {
        maxDeadline = max(maxDeadline, jobs[i].deadline);
    }

    bool slots[maxDeadline] = {false};
    int totalProfit = 0;

    for (int i = 0; i < n; i++) {
        int slot = jobs[i].deadline - 1;
        while (slot >= 0 && slots[slot]) {
            slot--;
        }
        if (slot >= 0) {
            slots[slot] = true;
            totalProfit += jobs[i].profit;
        }
    }

    cout << "Optimal solution: " << totalProfit << endl;

    return 0;
}
