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
int k = 0;

void display(vector<int> vec)
{
    for (auto i : vec)
    {
        cout << i << " ";
    }
    cout << endl;
}

int partition(vector<int> &arr, int low, int high)
{
    int pivot = arr[low];
    int i = low + 1;
    int j = high;
    k++;
    while (true)
    {
        while (i <= j && arr[i] < pivot)
        {
            i++;
        } 
        while (i <= j && arr[j] > pivot)
        {
            j--;
        }

        if (i <= j)
        {
            swap(arr[i], arr[j]);
        }
        else
        {
            break;
        }
    }

    swap(arr[low], arr[j]);
    return j;
}

void quicksort(vector<int> &arr, int low, int high)
{
    if (low < high)
    {
        int pivotIndex = partition(arr, low, high);
        cout << "After " << k << " partitions :" << endl;
        cout << "Pivot : " << arr[pivotIndex] << endl;
        display(arr);
        quicksort(arr, low, pivotIndex - 1);
        quicksort(arr, pivotIndex + 1, high);
    }
}

int main()
{
    vector<int> arr = {329, 126, 637, -10, 42, 47, 809, 503, 89, 103, 82};
    int n = arr.size();
    cout << endl;
    cout << "Before Sorting : ";
    fr02m(n)
    {
        cout << arr[i] << " ";
    }
    cout << endl
         << endl;
    quicksort(arr, 0, n - 1);

    cout << "\nAfter Sorting  :";
    fr02m(n)
    {
        cout << arr[i] << " ";
    }
    cout << endl
         << endl;

    return 0;
}
