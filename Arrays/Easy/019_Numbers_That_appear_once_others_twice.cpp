#include <bits/stdc++.h>
using namespace std;

// 🔹 1. Brute Force (Nested Loop)
int findSingleBrute(vector<int> &arr) {
    int n = arr.size();

    for(int i = 0; i < n; i++) {
        int count = 0;

        for(int j = 0; j < n; j++) {
            if(arr[i] == arr[j]) {
                count++;
            }
        }

        if(count == 1) return arr[i];
    }

    return -1;
}

// 🔹 2. Better (Hashing)
int findSingleHash(vector<int> &arr) {
    unordered_map<int, int> freq;

    for(auto it : arr) {
        freq[it]++;
    }

    for(auto it : freq) {
        if(it.second == 1) {
            return it.first;
        }
    }

    return -1;
}

// 🔹 3. Better (Sorting)
int findSingleSort(vector<int> &arr) {
    sort(arr.begin(), arr.end());
    int n = arr.size();

    for(int i = 0; i < n - 1; i += 2) {
        if(arr[i] != arr[i + 1]) {
            return arr[i];
        }
    }

    return arr[n - 1];
}

// 🔹 4. Optimal (XOR)
int findSingleXOR(vector<int> &arr) {
    int result = 0;

    for(auto it : arr) {
        result ^= it;
    }

    return result;
}

// 🔹 Driver Code
int main() {
    vector<int> arr = {4, 1, 2, 1, 2};

    cout << "Array: ";
    for(auto it : arr) cout << it << " ";
    cout << endl;

    cout << "\nBrute Force: " << findSingleBrute(arr) << endl;
    cout << "Hashing: " << findSingleHash(arr) << endl;
    cout << "Sorting: " << findSingleSort(arr) << endl;
    cout << "Optimal XOR: " << findSingleXOR(arr) << endl;

    return 0;
}