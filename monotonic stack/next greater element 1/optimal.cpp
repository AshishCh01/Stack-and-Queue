#include <bits/stdc++.h>
using namespace std;
vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
    stack<int> st;
    unordered_map<int, int> mp;

    // Find the next greater element for every element in nums2
    for (int i = nums2.size() - 1; i >= 0; i--) {
        while (!st.empty() && st.top() <= nums2[i]) {
            st.pop();
        }

        if (st.empty()) {
            mp[nums2[i]] = -1;
        } else {
            mp[nums2[i]] = st.top();
        }

        st.push(nums2[i]);
    }

    // Build the answer for nums1 using the hash map
    vector<int> ans;
    for (int num : nums1) {
        ans.push_back(mp[num]);
    }

    return ans;
}
int main()
{
    vector<int> nums1 = {4,1,2};
    vector<int> nums2 = {1,3,4,2};
    vector<int> ans = nextGreaterElement(nums1, nums2);

    for (int x : ans) {
        cout << x << " ";
    }

    cout << endl;
    return 0;
}