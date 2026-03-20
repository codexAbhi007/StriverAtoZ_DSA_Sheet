#include <bits/stdc++.h>
using namespace std;

// ===================== 1. BRUTE FORCE =====================
// Generate all subarrays
int longestSubarray_brute(vector<int>& arr, int k) {
    int n = arr.size();
    int maxLen = 0;

    for(int i = 0; i < n; i++) {
        int sum = 0;
        for(int j = i; j < n; j++) {
            sum += arr[j];

            if(sum == k) {
                maxLen = max(maxLen, j - i + 1);
            }
        }
    }

    return maxLen;
}

// ===================== 2. BETTER (PREFIX SUM + MAP) =====================
// Works for +ve, -ve, zero
int longestSubarray_better(vector<int>& arr, int k) {
    unordered_map<int, int> mp; // prefixSum -> first index
    int sum = 0, maxLen = 0;

    for(int i = 0; i < arr.size(); i++) {
        sum += arr[i];

        // case 1: sum itself is k
        if(sum == k) {
            maxLen = i + 1;
        }

        // case 2: (sum - k) exists
        if(mp.find(sum - k) != mp.end()) {
            int len = i - mp[sum - k];
            maxLen = max(maxLen, len);
        }

        // store only first occurrence
        if(mp.find(sum) == mp.end()) {
            mp[sum] = i;
        }
    }

    return maxLen;
}

// ===================== 3. OPTIMAL (SLIDING WINDOW) =====================
// Only works when all elements >= 0
int longestSubarray_optimal(vector<int>& arr, int k) {
    int left = 0, right = 0;
    int sum = 0, maxLen = 0;

    while(right < arr.size()) {
        sum += arr[right];

        // shrink window if sum > k
        while(left <= right && sum > k) {
            sum -= arr[left];
            left++;
        }

        // check
        if(sum == k) {
            maxLen = max(maxLen, right - left + 1);
        }

        right++;
    }

    return maxLen;
}

// ===================== DRIVER =====================
int main() {

    vector<vector<int>> testArrays = {
        {1, 2, 3, 1, 1, 1, 1},
        {1, -1, 5, -2, 3},
        {2, 0, 0, 3},
        {3, 1, 2, 1, 1, 1},
        {1, 2, 1, 1, 1},
        {5, -2, 3, 1, 2},
        {1, 1, 1, 1, 1},
        {2, 3, 5},
        {1, -1, 1, -1, 1, -1, 1}
    };

    vector<int> kValues = {3, 3, 3, 4, 3, 4, 2, 5, 0};

    for(int t = 0; t < testArrays.size(); t++) {
        vector<int> arr = testArrays[t];
        int k = kValues[t];

        cout << "Test Case " << t+1 << ":\n";
        cout << "Array: ";
        for(int x : arr) cout << x << " ";
        cout << "\nK = " << k << endl;

        int brute = longestSubarray_brute(arr, k);
        int better = longestSubarray_better(arr, k);

        cout << "Brute: " << brute << endl;
        cout << "Better (Prefix Map): " << better << endl;

        // check if all elements >= 0 for sliding window
        bool nonNegative = true;
        for(int x : arr) {
            if(x < 0) {
                nonNegative = false;
                break;
            }
        }

        if(nonNegative) {
            int optimal = longestSubarray_optimal(arr, k);
            cout << "Optimal (Sliding Window): " << optimal << endl;
        } else {
            cout << "Optimal (Sliding Window): Not applicable (negative elements present)" << endl;
        }

        cout << "----------------------------------\n";
    }

    return 0;
}