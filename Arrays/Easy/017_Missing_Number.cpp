#include <bits/stdc++.h>
using namespace std;

// 🔴 1. Brute (Linear Search)
int missing_brute(vector<int>& nums) {
    int n = nums.size();

    for(int i = 0; i <= n; i++){
        bool found = false;
        for(int j = 0; j < n; j++){
            if(nums[j] == i){
                found = true;
                break;
            }
        }
        if(!found) return i;
    }
    return -1;
}

// 🟡 2. Better (Hashing)
int missing_hash(vector<int>& nums) {
    int n = nums.size();
    vector<int> hash(n+1, 0);

    for(int i = 0; i < n; i++){
        hash[nums[i]] = 1;
    }

    for(int i = 0; i <= n; i++){
        if(hash[i] == 0) return i;
    }

    return -1;
}

// 🟢 3. Optimal (Sum Formula)
int missing_sum(vector<int>& nums) {
    int n = nums.size();

    long long sum_n = (long long)n * (n + 1) / 2;
    long long sum_arr = 0;

    for(int i = 0; i < n; i++){
        sum_arr += nums[i];
    }

    return (int)(sum_n - sum_arr);
}

// 🔵 4. Optimal (XOR)
int missing_xor(vector<int>& nums) {
    int n = nums.size();

    int xor1 = 0, xor2 = 0;

    for(int i = 0; i < n; i++){
        xor2 ^= nums[i];
        xor1 ^= (i + 1);
    }

    return xor1 ^ xor2;
}

// 🧪 Driver Code
int main() {

    // Test Case 1
    vector<int> nums1 = {3, 0, 1};

    // Test Case 2
    vector<int> nums2 = {0, 1};

    // Test Case 3
    vector<int> nums3 = {9,6,4,2,3,5,7,0,1};

    cout << "=== Test Case 1 ===\n";
    cout << "Brute: " << missing_brute(nums1) << endl;
    cout << "Hashing: " << missing_hash(nums1) << endl;
    cout << "Sum: " << missing_sum(nums1) << endl;
    cout << "XOR: " << missing_xor(nums1) << endl;

    cout << "\n=== Test Case 2 ===\n";
    cout << "Brute: " << missing_brute(nums2) << endl;
    cout << "Hashing: " << missing_hash(nums2) << endl;
    cout << "Sum: " << missing_sum(nums2) << endl;
    cout << "XOR: " << missing_xor(nums2) << endl;

    cout << "\n=== Test Case 3 ===\n";
    cout << "Brute: " << missing_brute(nums3) << endl;
    cout << "Hashing: " << missing_hash(nums3) << endl;
    cout << "Sum: " << missing_sum(nums3) << endl;
    cout << "XOR: " << missing_xor(nums3) << endl;

    return 0;
}