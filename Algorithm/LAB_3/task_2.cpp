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

void merge(std::vector<int> &arr, int left, int middle, int right)
{
    int n1 = middle - left + 1;
    int n2 = right - middle;

    std::vector<int> leftArr(n1);
    std::vector<int> rightArr(n2);

    for (int i = 0; i < n1; i++)
    {
        leftArr[i] = arr[left + i];
    }
    for (int j = 0; j < n2; j++)
    {
        rightArr[j] = arr[middle + 1 + j];
    }

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2)
    {
        if (leftArr[i] <= rightArr[j])
        {
            arr[k] = leftArr[i];
            i++;
        }
        else
        {
            arr[k] = rightArr[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        arr[k] = leftArr[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = rightArr[j];
        j++;
        k++;
    }
}

void mergeSort(std::vector<int> &arr, int left, int right)
{
    if (left < right)
    {
        int middle = left + (right - left) / 2;
        mergeSort(arr, left, middle);
        mergeSort(arr, middle + 1, right);
        merge(arr, left, middle, right);
    }
}

void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}
int partition(vector<int> array, int low, int high)
{

    int pivot = array[high];
    int i = (low - 1);

    for (int j = low; j < high; j++)
    {
        if (array[j] <= pivot)
        {
            i++;
            swap(&array[i], &array[j]);
        }
    }

    swap(&array[i + 1], &array[high]);
    return (i + 1);
}

void quickSort(vector<int> &array, int low, int high)
{
    if (low < high)
    {

        int pi = partition(array, low, high);
        quickSort(array, low, pi - 1);

        quickSort(array, pi + 1, high);
    }
}

int main()
{

    vector<string> name = {"1000", "2500", "5000", "7500", "10000", "12500", "15000", "17500", "20000"};
    //int arr[] = {1000, 2500, 5000, 7500, 10000, 12500, 15000, 17500, 20000};
    vector<int> vec;
    cout<<"No. of data\t  merge sort       \tquick sort "<<endl;
    cout<<"-----------------------------------------------------------"<<endl;
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
        int n = vec.size();
        cout << name[i] << "\t\t";
        auto start_time = std::chrono::high_resolution_clock::now();
        mergeSort(vec, 0, n - 1);
        auto end_time = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time);
        std::cout << duration.count() << " miliseconds"
                  << " \t\t";

        start_time = std::chrono::high_resolution_clock::now();
        quickSort(vec, 0, n - 1);
        end_time = std::chrono::high_resolution_clock::now();
        duration = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time);
        cout << duration.count() << " milliseconds" << endl;
        // cout << maxVal << "   " << minVal << endl;
        vec.clear();
    }
    return 0;
}