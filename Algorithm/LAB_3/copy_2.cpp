#include <bits/stdc++.h>
#include <fstream>
#include <chrono>

using namespace std;
int Max, Min, comp = 0;

void StrightMaxMin(vector<int> &vec, int &max, int &min) {
    max = min = vec[0];
    int size = vec.size();
    for (int i = 1; i < size; i++) {
        if (vec[i] > max) {
            max = vec[i];
        } else if (vec[i] < min) {
            min = vec[i];
        }
    }
}

void maxmin(vector<int> &v, int i, int j) {
    int size = v.size();

    int max1, min1, mid;
    if (i == j) {
        Max = Min = v[i];
    } else {
        if (i == j - 1) {
            comp++;
            if (v[i] < v[j]) {
                Max = v[j];
                Min = v[i];
            } else {
                Max = v[i];
                Min = v[j];
            }
        } else {
            mid = (i + j) / 2;
            maxmin(v, i, mid);
            max1 = Max;
            min1 = Min;
            maxmin(v, mid + 1, j);
            if (Max < max1) {
                Max = max1;
            }
            if (Min > min1) {
                Min = min1;
            }
        }
    }
}

int main() {
    vector<string> name = {"1000", "2500", "5000", "7500", "10000", "12500", "15000", "17500", "20000"};
    int arr[] = {1000, 2500, 5000, 7500, 10000, 12500, 15000, 17500, 20000};
    vector<int> vec;
    cout << "No.of data \t max \t\t min\t\tBrute-force\t\trecursion method" << endl;
    cout << "-----------------------------------------------------------------------------------------" << endl;
    for (int i = 0; i < name.size(); i++) {
        int x;
        string s = name[i] + ".txt";
        ifstream in(s);
        while (!in.eof()) {
            in >> x;
            vec.push_back(x);
        }
        in.close();
        cout << arr[i] << "\t\t";
        
        int max, min;
        double totalStrightTime = 0;
        double totalRecursionTime = 0;
        int numIterations = 1000; // Number of iterations

        for (int j = 0; j < numIterations; j++) {
            auto start_time = std::chrono::high_resolution_clock::now();
            StrightMaxMin(vec, max, min);
            auto end_time = std::chrono::high_resolution_clock::now();
            auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end_time - start_time);
            totalStrightTime += duration.count();

            start_time = std::chrono::high_resolution_clock::now();
            Max = Min = 0;
            maxmin(vec, 0, vec.size() - 1);
            end_time = std::chrono::high_resolution_clock::now();
            duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end_time - start_time);
            totalRecursionTime += duration.count();
        }

        double avgStrightTime = totalStrightTime / numIterations / 1e6;
        double avgRecursionTime = totalRecursionTime / numIterations / 1e6;

        cout << max << " \t\t" << min << " \t\t" << avgStrightTime << " ms \t\t" << avgRecursionTime << " ms" << endl;
        vec.clear();
    }
    return 0;
}
