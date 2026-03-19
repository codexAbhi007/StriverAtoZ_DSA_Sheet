#include <bits/stdc++.h>
using namespace std;

// 🔴 Brute Force (check every subarray)
int maxConsecutiveOnes_brute(vector<int>& nums) {
    int n = nums.size();
    int maxi = 0;

    for(int i = 0; i < n; i++){
        int count = 0;

        for(int j = i; j < n; j++){
            if(nums[j] == 1){
                count++;
                maxi = max(maxi, count);
            } else {
                break;
            }
        }
    }
    return maxi;
}

// 🟢 Optimal (single pass)
int maxConsecutiveOnes_optimal(vector<int>& nums) {
    int count = 0, maxi = 0;

    for(int i = 0; i < nums.size(); i++){
        if(nums[i] == 1){
            count++;
            maxi = max(maxi, count);
        } else {
            count = 0;
        }
    }

    return maxi;
}

// 🧪 Driver Code
int main() {

    // Test Case 1
    vector<int> nums1 = {1,1,0,1,1,1};

    // Test Case 2
    vector<int> nums2 = {1,0,1,1,0,1};

    // Test Case 3
    vector<int> nums3 = {0,0,0,0};

    cout << "=== Test Case 1 ===\n";
    cout << "Brute: " << maxConsecutiveOnes_brute(nums1) << endl;
    cout << "Optimal: " << maxConsecutiveOnes_optimal(nums1) << endl;

    cout << "\n=== Test Case 2 ===\n";
    cout << "Brute: " << maxConsecutiveOnes_brute(nums2) << endl;
    cout << "Optimal: " << maxConsecutiveOnes_optimal(nums2) << endl;

    cout << "\n=== Test Case 3 ===\n";
    cout << "Brute: " << maxConsecutiveOnes_brute(nums3) << endl;
    cout << "Optimal: " << maxConsecutiveOnes_optimal(nums3) << endl;

    return 0;
}