// finding minimum and maximum using recursion

#include <bits/stdc++.h>
#include <fstream>
#include <vector>
#include <algorithm>
#include <chrono>
#define ll long long
#define fr(m) for (int i = 0; i < m; i++)
#define fro(m) for (int i = 1; i < m; i++)
#define frj(m) for (int j = 0; j < m; j++)
#define frr(n) for (int i = n; i >= 0; i--)
#define frxy(x, y) for (int i = x; i <= y; i++)
#define pb push_back
#define pf push_front

using namespace std;
using namespace chrono;

void brute_force(vector<int> &vec)
{

    //  max:=min:=a[l];
    // for i :=2 to n do
    // {
    // if (a[i]>max)thenmax:=a[i];
    // }
    int min = vec[0];
    int max = vec[0];

    for (int i = 0; i < vec.size(); i++)
    {
        if (vec[i] > max)
            max = vec[i];
        else
            min = vec[i];
    }
    cout << max << "\t\t" << min << "\t\t";
}
void recursion(vector<int> &vec)
{
    int start = 0;
    int end = vec.size();
    int maxVal,minVal;

    if (start == end)
    {
        maxVal = minVal = vec[start];
        return;
    }

    // If there are two elements, compare and set max and min.
    if (start == end - 1)
    {
        maxVal = max(vec[start], vec[end]);
        minVal = min(vec[start], vec[end]);
        return;
    }

    int mid = (start + end) / 2;
    int maxVal1, minVal1, maxVal2, minVal2;

    // Recursively find max and min in the first and second halves.
    recursion(vec, start, mid, maxVal1, minVal1);
    recursion(vec, mid + 1, end, maxVal2, minVal2);

    // Merge results from the two halves.
    maxVal = max(maxVal1, maxVal2);
    minVal = min(minVal1, minVal2);
}

int main()
{
    vector<string> name = {"1000", "2500", "5000", "7500", "10000", "12500", "15000", "17500", "20000"};
    int vec[] = {1000, 2500, 5000, 7500, 10000, 12500, 15000, 17500, 20000};
    vector<int> vec;
    //   int x;
    //   cout << "How many data you want to work with :" << endl;
    //   cout << "\t\t1. 1000" << endl;
    //   cout << "\t\t2. 2500" << endl;
    //   cout << "\t\t3. 5000" << endl;
    //   cout << "\t\t4. 7500" << endl;
    //   cout << "\t\t5. 10000" << endl;
    //   cout << "\t\t6. 12500" << endl;
    //   cout << "\t\t7. 15000" << endl;
    //   cout << "\t\t8. 17500" << endl;
    //   cout << "\t\t9. 20000" << endl;
    //   cout << "Enter your choice: ";
    //   int choice;
    //   cin >> choice;

    cout << " no.of data \t\t max \t\t min \t\t Brute-force \t\t recursion method" << endl;
    for (int i = 0; i < name.size(); i++)
    {
        int x;
        string s = name[i] + ".txt";
        ifstream in(s);
        while (!in.eof())
        {
            in >> x;
            vec.push_back(x);
        }
        in.close();
        cout << vec[i] << "\t\t";
        auto start_time = high_resolution_clock::now();
        brute_force(vec);
        auto end_time = high_resolution_clock::now();
        auto duration = duration_cast<milliseconds>(end_time - start_time);
        cout << duration.count() << " milliseconds\t\t";

        start_time = high_resolution_clock::now();
        recursion(vec);
        end_time = high_resolution_clock::now();
        duration = duration_cast<milliseconds>(end_time - start_time);
        cout << duration.count() << " milliseconds" << endl;

        vec.clear();
    }
    return 0;
}