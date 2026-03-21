#include <bits/stdc++.h>
using namespace std;

// ======================
// 1. Brute Force
// ======================
bool twoSumBrute(vector<int>& nums, int target) {
    int n = nums.size();

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (nums[i] + nums[j] == target) {
                cout << "Brute Pair Indices: (" << i << ", " << j << ")\n";
                return true;
            }
        }
    }
    return false;
}

// ======================
// 2. Optimal (Hashing)
// ======================
vector<int> twoSumHash(vector<int>& nums, int target) {
    unordered_map<int, int> mp; // value -> index

    for (int i = 0; i < nums.size(); i++) {
        int need = target - nums[i];

        if (mp.find(need) != mp.end()) {
            return {mp[need], i};
        }

        mp[nums[i]] = i;
    }

    return {-1, -1};
}

// ======================
// 3. Optimal (Two Pointer - YES/NO)
// ======================
bool twoSumTwoPointer(vector<int> nums, int target) {
    sort(nums.begin(), nums.end());

    int left = 0, right = nums.size() - 1;

    while (left < right) {
        int sum = nums[left] + nums[right];

        if (sum == target) return true;
        else if (sum < target) left++;
        else right--;
    }

    return false;
}

// ======================
// Utility: Print Array
// ======================
void printArray(vector<int>& nums) {
    cout << "[ ";
    for (auto x : nums) cout << x << " ";
    cout << "]\n";
}

// ======================
// Driver Code
// ======================
int main() {

    vector<vector<int>> testCases = {
        {2, 7, 11, 15},
        {3, 2, 4},
        {3, 3},
        {1, 5, 3, 7},
        {-1, -2, -3, -4, -5}
    };

    vector<int> targets = {9, 6, 6, 8, -8};

    for (int t = 0; t < testCases.size(); t++) {
        vector<int> nums = testCases[t];
        int target = targets[t];

        cout << "============================\n";
        cout << "Test Case " << t + 1 << "\n";
        cout << "Array: ";
        printArray(nums);
        cout << "Target: " << target << "\n\n";

        // Brute
        bool bruteRes = twoSumBrute(nums, target);
        cout << "Brute Exists: " << (bruteRes ? "YES" : "NO") << "\n";

        // Hashing
        vector<int> hashRes = twoSumHash(nums, target);
        if (hashRes[0] != -1)
            cout << "Hash Indices: " << hashRes[0] << " " << hashRes[1] << "\n";
        else
            cout << "Hash: No pair found\n";

        // Two Pointer
        bool tpRes = twoSumTwoPointer(nums, target);
        cout << "Two Pointer Exists: " << (tpRes ? "YES" : "NO") << "\n";

        cout << endl;
    }

    return 0;
}