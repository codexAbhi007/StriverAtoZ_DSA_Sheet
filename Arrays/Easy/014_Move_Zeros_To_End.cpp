//https://leetcode.com/problems/move-zeroes/description/

#include <bits/stdc++.h>
using namespace std;

// 🔹 BRUTE FORCE
void bruteForce(int arr[], int n) {
    vector<int> temp;

    // store non-zero elements
    for(int i = 0; i < n; i++) {
        if(arr[i] != 0) {
            temp.push_back(arr[i]);
        }
    }

    // copy back non-zero elements
    int k = temp.size();
    for(int i = 0; i < k; i++) {
        arr[i] = temp[i];
    }

    // fill remaining with zeros
    for(int i = k; i < n; i++) {
        arr[i] = 0;
    }
}


// 🔹 OPTIMAL (Two Pointer)
void optimal(int arr[], int n) {
    int j = 0; // position for next non-zero

    for(int i = 0; i < n; i++) {
        if(arr[i] != 0) {
            swap(arr[i], arr[j]);
            j++;
        }
    }
}


// 🔹 DRIVER CODE
int main() {
    int arr[] = {0, 1, 0, 3, 12};
    int n = sizeof(arr) / sizeof(arr[0]);

    // choose one:
    // bruteForce(arr, n);
    optimal(arr, n);

    // print result
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}