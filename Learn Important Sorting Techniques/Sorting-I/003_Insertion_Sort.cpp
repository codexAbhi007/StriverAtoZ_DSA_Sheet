#include <bits/stdc++.h>
using namespace std;


void insertionSort(int a[], int n){
    for(int i = 1; i < n;++i){
        int key = a[i];
        int j = i -1;
        for(;j >= 0 && a[j] > key;){
            a[j+1] = a[j];
            --j;
        }
        a[j+1] = key;
    }
}




int main()
{
    int n = 5;
    int arr[n] = {64, 25, 12, 22, 11};
    insertionSort(arr, n);
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
}