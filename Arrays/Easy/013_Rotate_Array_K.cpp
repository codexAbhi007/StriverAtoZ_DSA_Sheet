//https://leetcode.com/problems/remove-duplicates-from-sorted-array/description/
#include <bits/stdc++.h>
using namespace std;

void bruteForce(int arr[], int n, int k) {
    k = k % n;

    int temp[k];

    // store first k elements
    for(int i = 0; i < k; i++) {
        temp[i] = arr[i];
    }

    // shift remaining elements
    for(int i = k; i < n; i++) {
        arr[i - k] = arr[i];
    }

    // copy temp to end
    for(int i = 0; i < k; i++) {
        arr[n - k + i] = temp[i];
    }
}

void reverseArr(int arr[], int start, int end) {
    while(start < end) {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}

void optimal(int arr[], int n, int k) {
    k = k % n;

    reverseArr(arr, 0, k - 1);
    reverseArr(arr, k, n - 1);
    reverseArr(arr, 0, n - 1);
}



int main(){
    int arr[7] = {1,2,3,4,5,6,7};
    int n = 7;
    int k = 3;

    optimal(arr, n, k);  // or bruteForce(arr, n, k);

    for(int i = 0; i < n; ++i){
        cout << arr[i] << " ";
    }
}