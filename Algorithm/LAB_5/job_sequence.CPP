#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

struct Job
{
    int id;
    int profit;
    int deadline;
};

bool compareJobs(Job &a, Job &b)
{
    return a.profit > b.profit;
}

vector<int> jobSequence(vector<Job> &jobs)
{
    sort(jobs.begin(), jobs.end(), compareJobs);

    vector<int> result;
    vector<bool> slot(jobs.size(), false);

    for (const Job &job : jobs)
    {
        for (int i = min(job.deadline - 1, static_cast<int>(slot.size()) - 1); i >= 0; --i)
        {
            if (!slot[i])
            {
                result.push_back(job.id); 
                slot[i] = true;
                break;
            }
        }
    }

    return result;
}

int main()
{
    // ofstream outputFile("jobsequence.txt");
    // // cout << "Enter the number of jobs: ";
    // // int n;
    // // cin >> n;
    int n;
    // outputFile << n << endl;

    vector<Job> jobs(n);
    vector<int> getresult(n);

    // cout << "Enter the profits : ";
    // for (int i = 0; i < n; ++i)
    // {
    //     int profit;
    //     cin >> jobs[i].profit;
    //     jobs[i].id = i + 1;
    //     outputFile << jobs[i].profit << " ";
    //      getresult[i]=jobs[i].profit;

    // }
    // outputFile << endl;

    // cout << "Enter the deadlines : ";
    // for (int i = 0; i < n; i++)
    // {
    //     cin >> jobs[i].deadline;
    //     outputFile << jobs[i].deadline << " ";
    // }
    // outputFile << endl;

    // outputFile.close();

    ifstream inputFile("jobsequence.txt");
    // int n;
    inputFile >> n;
    for (int i = 0; i < n; i++)
    {
        inputFile >> jobs[i].profit;
        jobs[i].id = i + 1;
        getresult[i] = jobs[i].profit;
    }
    for (int i = 0; i < n; i++)
    {
        inputFile >> jobs[i].deadline;
    }

    vector<int> result = jobSequence(jobs);
    cout << endl;
    cout << "Job sequence: ";

    cout << endl;

    cout << "Optimal solution: ";
    for (int jobId : result)
    {
        cout << jobId << " ";
    }

    // Calculate total profit
    int totalProfit = 0;
    for (int jobId : result)
    {
        totalProfit += getresult[jobId - 1]; // Corrected indexing
    }

    cout << "\nTotal Profit: " << totalProfit << endl;
    cout << endl;
    return 0;
}
