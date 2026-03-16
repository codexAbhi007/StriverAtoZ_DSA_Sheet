//https://leetcode.com/problems/remove-duplicates-from-sorted-array/description/
#include <bits/stdc++.h>
using namespace std;

//SC -> O(n) TC -> O(nlogn + n)
int bruteForce(int a[],int n){
    set<int> st;
    for(int i = 0; i < n; ++i){
        st.insert(a[i]);
    }

    int index =0;
    for(auto it:st){
        a[index] = it;
        index++;
    }
    return index ;
}
    
//SC -> O(1) TC -> O(1)
int removeDuplicates(int a[], int n){
    if(n == 1) return 1;

    int i = 0;
    for(int j = 1; j < n ; ++j){
        if( a[j] != a[i] ){
            a[i+1] = a[j];
            i++;
        }
    }
    return i+1;
}

int main(){
    int arr[6] = {1,1,2,2,3,3};
    int n = 6;
    // int k = bruteForce(arr,n);
    // cout << k << endl;
    // for(int i = 0; i < n; ++i){
    //     cout << arr[i] << " ";
    // }
    int k = bruteForce(arr,n);
    cout << k << endl;
    for(int i = 0; i < n; ++i){
        cout << arr[i] << " ";
    }
    
}