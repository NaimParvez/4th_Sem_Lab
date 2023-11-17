#include <bits/stdc++.h>
#include <vector>
using namespace std;

void merge(std::vector<int>& vec, int start, int mid, int end) {
    int i, j, k;
    int n1 = mid - start + 1;
    int n2 = end - mid;

    std::vector<int> L(n1), R(n2);

    for (i = 0; i < n1; i++)
        L[i] = vec[start + i];
    for (j = 0; j < n2; j++)
        R[j] = vec[mid + 1 + j];  

    i = 0;
    j = 0;
    k = start;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            vec[k] = L[i];
            i++;
        } else {
            vec[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        vec[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        vec[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(std::vector<int>& vec, int start, int end) {
    if (start < end) {
        int mid = start + (end - start) / 2;

        mergeSort(vec, start, mid);
        mergeSort(vec, mid + 1, end);

        merge(vec, start, mid, end);

        // Print vector after every merge
        for (int i = 0; i < vec.size(); i++)
            std::cout << vec[i] << " ";
        std::cout << "\n";
    }
}

int main() {
    std::vector<int> vec = {12, 11, 13, 7, 6, 4};
    int vec_size = vec.size();

    std::cout << "Given vector is \n";
    for (int i = 0; i < vec_size; i++)
        std::cout << vec[i] << " ";
    std::cout << "\n\nwhile sorting\n";

    mergeSort(vec, 0, vec_size - 1);

    std::cout << "\nSorted vector is \n";
    for (int i = 0; i < vec_size; i++)
        std::cout << vec[i] << " ";
    return 0;
}