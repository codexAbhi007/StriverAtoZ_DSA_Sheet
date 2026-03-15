#include <bits/stdc++.h>
using namespace std;

void bubbleSort(int a[], int n)
{
    for (int i = 0; i <= n - 2; ++i)
    {
        int isSwapped = 0;
        for (int j = 0; j <= n - i - 1; ++j)
        {
            if (a[j + 1] < a[j])
            {
                swap(a[j + 1], a[j]);
                isSwapped = 1;
            }
        }
        if (!isSwapped)
            break;
    }
}

int main()
{
    int n = 5;
    int arr[n] = {64, 25, 12, 22, 11};
    bubbleSort(arr, n);
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
}