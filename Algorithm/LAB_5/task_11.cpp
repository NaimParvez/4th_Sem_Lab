#include <bits/stdc++.h>
#include <fstream>
#define ll long long
#define fr02m(m) for (int i = 0; i < m; i++)
#define fr12m(m) for (int i = 1; i < m; i++)
#define fr02j(m) for (int j = 0; j < m; j++)
#define frn20(n) for (int i = n; i >= 0; i--)
#define frxy(x, y) for (int i = x; i <= y; i++)
#define pb push_back
#define pf push_front
using namespace std;

void maxProfit(vector<int> &weight, vector<int> &profit, int n, int capacity)
{
    vector<pair<int, int>> v;
    for (int i = 0; i < n; ++i)
    {
        v.push_back(make_pair(profit[i], weight[i]));
    }
    sort(v.begin(), v.end(), greater<pair<int, int>>());
    // for (auto i : v) {
    // cout << i.first << " " << i.second << endl;
    // }
    int current_weight = 0;
    double total_profit = 0.0;
    cout << " element of Weight -" << endl;
    for (int i = 0; i < n; i++)
    {
        if (current_weight + v[i].second <= capacity) // if we can take the whole item
        {
            cout << v[i].second << "  -  1" << endl;
            current_weight += v[i].second; // take it
            total_profit += v[i].first;    // add its profit to the total profit
        }
        else
        {
            int remaining = capacity - current_weight; // take the remaining part of the item
            // total_profit += v[i].first * remaining;    // add its profit to the total profit
            if (remaining == 0)
                break;
            cout << v[i].second << "  -  " << ((float)remaining / v[i].second) << endl;
            total_profit += v[i].first * ((float)remaining / v[i].second);
            break;
        }
    }
    cout << "solution : " << total_profit << endl
         << endl;
}

void maxweight(vector<int> &weight, vector<int> &profit, int n, int capacity)
{
    vector<pair<int, int>> v;
    for (int i = 0; i < n; ++i)
    {
        v.push_back(make_pair(profit[i], weight[i]));
    }
    sort(v.begin(), v.end(), [](const pair<int, int> &a, const pair<int, int> &b)
         { return a.second > b.second; });
    // for (auto i : v) {
    // cout << i.first << " " << i.second << endl;
    // }
    int current_weight = 0;
    double total_profit = 0.0;
    cout << " element of Weight -" << endl;
    for (int i = 0; i < n; i++)
    {
        // if(current_weight==capacity)break;

        if (current_weight + v[i].second <= capacity)
        { // if we can take the whole item
            cout << v[i].second << "  -  1" << endl;
            current_weight += v[i].second; // take it
            total_profit += v[i].first;    // add its profit to the total profit
        }
        else
        {
            int remaining = capacity - current_weight; // take the remaining part of the item
            // cout<<remaining<<endl;
            // cout<<total_profit<<endl;
            // cout<<remaining<<endl;
            // cout<<v[i].second<<endl;
            // cout<<((float)remaining/v[i].second)<<endl;
            if (remaining == 0)
                break;
            cout << v[i].second << "  -  " << ((float)remaining / v[i].second) << endl;
            total_profit += v[i].first * ((float)remaining / v[i].second); // add its profit to the total profit
            // cout<<total_profit<<endl;
            break;
        }
    }
    cout << "solution : " << total_profit << endl
         << endl;
}

void lesserweight(vector<int> &weight, vector<int> &profit, int n, int capacity)
{
    vector<pair<int, int>> v;
    for (int i = 0; i < n; ++i)
    {
        v.push_back(make_pair(profit[i], weight[i]));
    }
    sort(v.begin(), v.end(), [](const pair<int, int> &a, const pair<int, int> &b)
         { return a.second < b.second; });
    // for (auto i : v)
    // {
    //     cout << i.first << " " << i.second << endl;
    // }
    int current_weight = 0;
    double total_profit = 0.0;
    cout << " element of Weight -" << endl;
    for (int i = 0; i < n; i++)
    {
        // if(current_weight==capacity)break;

        if (current_weight + v[i].second <= capacity)
        { // if we can take the whole item
            cout << v[i].second << "  -  1" << endl;
            current_weight += v[i].second; // take it
            total_profit += v[i].first;    // add its profit to the total profit
        }
        else
        {
            int remaining = capacity - current_weight; // take the remaining part of the item
            // cout<<remaining<<endl;
            // cout<<total_profit<<endl;
            // cout<<remaining<<endl;
            // cout<<v[i].second<<endl;
            // cout<<((float)remaining/v[i].second)<<endl;
            if (remaining == 0)
                break;
            cout << v[i].second << "  -  " << ((float)remaining / v[i].second) << endl;
            total_profit += v[i].first * ((float)remaining / v[i].second); // add its profit to the total profit
            // cout<<total_profit<<endl;
            break;
        }
    }
    cout << "solution : " << total_profit << endl
         << endl;
}
void profitToweight(vector<int> &weight, vector<int> &profit, int n, int capacity)
{
    vector<pair<int, int>> v;
    for (int i = 0; i < n; ++i)
    {
        v.push_back(make_pair(profit[i], weight[i]));
    }
    sort(v.begin(), v.end(), [](const pair<int, int> &a, const pair<int, int> &b)
         { return ((double)a.first / a.second) > ((double)b.first / b.second); });
    // for (auto i : v)
    // {
    //     cout << i.first << " " << i.second << endl;
    // }
    int current_weight = 0;
    double total_profit = 0.0;
    cout << " element of Weight -" << endl;
    for (int i = 0; i < n; i++)
    {
        // if(current_weight==capacity)break;

        if (current_weight + v[i].second <= capacity)
        { // if we can take the whole item
            cout << v[i].second << "  -  1" << endl;
            current_weight += v[i].second; // take it
            total_profit += v[i].first;    // add its profit to the total profit
        }
        else
        {
            int remaining = capacity - current_weight; // take the remaining part of the item
            // cout<<remaining<<endl;
            // cout<<total_profit<<endl;
            // cout<<remaining<<endl;
            // cout<<v[i].second<<endl;
            // cout<<((float)remaining/v[i].second)<<endl;
            if (remaining == 0)
                break;
            cout << v[i].second << "  -  " << ((float)remaining / v[i].second) << endl;
            total_profit += v[i].first * ((float)remaining / v[i].second); // add its profit to the total profit
            // cout<<total_profit<<endl;
            break;
        }
    }
    cout << "solution : " << total_profit << endl
         << endl;
}
int main()
{
    ifstream input("knapsack.txt");
    int n, x;
    input >> n;
    int capacity;
    input >> capacity;
    vector<int> weight;
    vector<int> profit;
    for (int i = 1; i <= n; i++)
    {
        input >> x;
        profit.pb(x);
    }
    for (int i = 1; i <= n; i++)
    {
        input >> x;
        weight.pb(x);
        // items[i].ratio = (double)items[i].profit / items[i].weight;
    }
    input.close();
    // vector<pair<int, int>> v;
    // for (int i = 0; i < n; ++i) {
    //     v.push_back(make_pair(profit[i], weight[i]));
    // }
    // sort(v.begin(), v.end(), greater<pair<int, int>>());
    // for (auto i : v) {
    // cout << i.first << " " << i.second << endl;}
    cout << "Taking the elements in the order of profit" << endl;
    maxProfit(weight, profit, n, capacity);
    cout << "Taking the elements in the order of weight" << endl;
    maxweight(weight, profit, n, capacity);
    cout << "Taking the elements in the order of lesser weight" << endl;
    lesserweight(weight, profit, n, capacity);
    cout << "Taking the elements in the order of profit to weight ratio" << endl;
    profitToweight(weight, profit, n, capacity);
}
