#include <bits/stdc++.h>
using namespace std;

int partition(int a[], int l, int r)
{
    int pivot = a[l];
    int i = l;
    int j = r;

    while (i < j)
    {
        while (a[i] <= pivot && i <= r - 1)
            i++;
        while (a[j] > pivot && j >= l + 1)
            j--;
        if (i < j)
        {
            swap(a[i], a[j]);
        }
    }
    swap(a[l], a[j]);
    return j;
}

void quickSort(int a[], int l, int r)
{
    if (l < r)
    {
        int p = partition(a, l, r);
        quickSort(a, l, p - 1);
        quickSort(a, p + 1, r);
    }
}

int main()
{
    int n = 5;
    int arr[n] = {64, 25, 12, 22, 11};
    int l = 0;
    int r = n - 1;
    quickSort(arr, l, r);
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
}