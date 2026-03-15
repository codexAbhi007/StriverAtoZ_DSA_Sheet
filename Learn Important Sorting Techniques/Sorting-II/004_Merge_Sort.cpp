#include <bits/stdc++.h>
using namespace std;

void merge(int a[], int l, int mid, int r)
{
    int n1 = mid - l + 1;
    int n2 = r - mid;
    vector<int> left(n1);
    vector<int> right(n2);

    for (int i = 0; i < n1; ++i)
    {
        left[i] = a[l + i];
    }
    for (int j = 0; j < n2; ++j)
    {
        right[j] = a[mid + 1 + j];
    }

    int i=0,j=0,k=l;
    while (i < n1 && j < n2)
    {
        if (left[i] <= right[j])
        {
            a[k++] = left[i++];
        }
        else
        {
            a[k++] = right[j++];
        }
    }

    while (i < n1)
    {
        a[k++] = left[i++];
    }
    while (j < n2)
    {
        a[k++] = right[j++];
    }
}

void mergeSort(int a[], int l, int r)
{
    if (l >= r)
        return;

    int mid = (l + r) / 2;
    mergeSort(a, l, mid);
    mergeSort(a, mid + 1, r);
    merge(a, l, mid, r);
}

int main()
{
    int n = 5;
    int arr[n] = {64, 25, 12, 22, 11};
    int l = 0;
    int r = n - 1;
    mergeSort(arr, l, r);
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
}