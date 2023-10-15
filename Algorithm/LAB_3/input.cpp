#include <bits/stdc++.h>
#include <fstream>
#define ll long long
#define fr(m) for (int i = 0; i < m; i++)
#define fro(m) for (int i = 1; i < m; i++)
#define frj(m) for (int j = 0; j < m; j++)
#define frr(n) for (int i = n; i >= 0; i--)
#define frxy(x, y) for (int i = x; i <= y; i++)
#define pb push_back
#define pf push_front
using namespace std;
int main()
{
    srand(time(0));
    ofstream file;
    // ofstream out;
    vector<string> name = {"1000", "2500", "5000", "7500", "10000", "12500", "15000", "17500", "20000"};
    int arr[] = {1000, 2500, 5000, 7500, 10000, 12500, 15000, 17500, 20000};
    int k;
    for (int j = 0; j < name.size(); j++)
    {
        k = arr[j];
        ofstream file(name[j] + ".txt");
        for (int i = 0; i < arr[j]; i++)
        {

            file << rand() % 1000000 << endl; 
        }
    }
    return 0;
}