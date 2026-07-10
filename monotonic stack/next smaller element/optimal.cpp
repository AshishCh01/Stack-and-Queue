#include <bits/stdc++.h>
using namespace std;

vector<int> nextSmallerElement(vector<int>& arr) {
    int n = arr.size();
    vector<int> ans(n, -1);
    stack<int> st;

    // Traverse from right to left
    for (int i = n - 1; i >= 0; i--) {

        // Remove all greater than or equal elements
        while (!st.empty() && st.top() >= arr[i]) {
            st.pop();
        }

        // If stack is not empty, top is the next smaller element
        if (!st.empty()) {
            ans[i] = st.top();
        }

        // Push current element
        st.push(arr[i]);
    }

    return ans;
}

int main() {
    vector<int> arr = {4, 8, 5, 2, 25};

    vector<int> ans = nextSmallerElement(arr);

    cout << "The next smaller elements are: ";
    for (int x : ans) {
        cout << x << " ";
    }

    return 0;
}