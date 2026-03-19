#include <bits/stdc++.h>
using namespace std;

int myMax(int a, int b) {
    return (a > b) ? a : b;
}

vector<int> unionBrute(vector<int>& a, vector<int>& b) {
    set<int> s;
    int n = a.size();
    int m = b.size();
    for (int i = 0; i < n; i++) {
        s.insert(a[i]);
    }
    for (int i = 0; i < m; i++) {
        s.insert(b[i]);
    }

    vector<int> ans;
    for (auto it = s.begin(); it != s.end(); ++it) {
        ans.push_back(*it);
    }

    return ans;
}


vector<int> unionOptimal(vector<int>& a, vector<int>& b) {
    int i = 0, j = 0;
    vector<int> ans;
    int n = a.size();
    int m = b.size();
    while (i < n && j < m) {
        if (a[i] <= b[j]) {
            if (ans.empty() || ans.back() != a[i]) {
                ans.push_back(a[i]);
            }
            i++;
        } else {
            if (ans.empty() || ans.back() != b[j]) {
                ans.push_back(b[j]);
            }
            j++;
        }
    }


    while (i < n) {
        if (ans.empty() || ans.back() != a[i]) {
            ans.push_back(a[i]);
        }
        i++;
    }


    while (j < m) {
        if (ans.empty() || ans.back() != b[j]) {
            ans.push_back(b[j]);
        }
        j++;
    }

    return ans;
}


int main() {
    vector<int> a = {1, 2, 2, 3, 4};
    vector<int> b = {2, 3, 5, 5, 6};

    cout << "Array 1: ";
    for (auto x : a) cout << x << " ";
    cout << endl;

    cout << "Array 2: ";
    for (auto x : b) cout << x << " ";
    cout << endl;


    vector<int> brute = unionBrute(a, b);
    cout << "\nUnion (Brute - Set): ";
    for (auto x : brute) cout << x << " ";
    cout << endl;

    vector<int> optimal = unionOptimal(a, b);
    cout << "Union (Optimal - 2 Pointer): ";
    for (auto x : optimal) cout << x << " ";
    cout << endl;

    return 0;
}