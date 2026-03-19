#include <bits/stdc++.h>
using namespace std;


vector<int> intersectionNested(vector<int>& a, vector<int>& b) {
    int n = a.size(), m = b.size();
    vector<int> vis(m, 0);  
    vector<int> ans;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i] == b[j] && vis[j] == 0) {
                ans.push_back(a[i]);
                vis[j] = 1;
                break; 
            }
            else if (b[j] > a[i]) break; 
        }
    }
    return ans;
}


vector<int> intersectionOptimal(vector<int>& a, vector<int>& b) {
    int i = 0, j = 0;
    vector<int> ans;
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    while (i < a.size() && j < b.size()) {
        if (a[i] < b[j]) {
            i++;
        }
        else if (a[i] > b[j]) {
            j++;
        }
        else {
            ans.push_back(a[i]); 
            i++;
            j++;
        }
    }
    return ans;
}


int main() {
    vector<int> a = {1, 2, 2, 3, 4};
    vector<int> b = {2, 2, 3, 5, 6};

    cout << "Array 1: ";
    for (auto x : a) cout << x << " ";
    cout << endl;

    cout << "Array 2: ";
    for (auto x : b) cout << x << " ";
    cout << endl;


    vector<int> res1 = intersectionNested(a, b);
    cout << "\nIntersection (Nested + Vis): ";
    for (auto x : res1) cout << x << " ";
    cout << endl;

    vector<int> res2 = intersectionOptimal(a, b);
    cout << "Intersection (2 Pointer): ";
    for (auto x : res2) cout << x << " ";
    cout << endl;

    return 0;
}