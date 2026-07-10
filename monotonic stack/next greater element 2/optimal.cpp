#include <bits/stdc++.h>
using namespace std;

vector<int> nextGreaterElements(vector<int>& nums) {
    int n = nums.size();
    vector<int> ans(n, -1);
    stack<int> st;

    // Traverse the array twice from right to left
    for (int i = 2 * n - 1; i >= 0; i--) {
        int index = i % n;

        // Remove all smaller or equal elements
        while (!st.empty() && st.top() <= nums[index]) {
            st.pop();
        }

        // Store answer only during the second traversal
        if (i < n) {
            if (!st.empty()) {
                ans[index] = st.top();
            }
        }

        // Push current element
        st.push(nums[index]);
    }

    return ans;
}
int main()
{
    int n = 6;
    vector<int> arr = {5, 7, 1, 7, 6, 0};
    vector<int> ans = nextGreaterElements(arr);
    
    cout << "The next greater elements are: ";
    for(int i=0; i < n; i++) {
        cout << ans[i] << " ";
    }
    return 0;
}