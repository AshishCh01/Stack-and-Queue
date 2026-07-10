#include <iostream>
#include <vector>
#include <stack>
using namespace std;
vector<int> nextGreater(vector<int>& nums) {
    stack<int> st;  // Stack to store elements
    int n = nums.size();
    vector<int> res(n); // another vector is taken of size n 
    for (int i=n-1; i>=0; i--) {    // Traverse from right to left
        // Pop all smaller or equal elements
        while (!st.empty() && st.top() <= nums[i]) {
            st.pop();
        }
        // If stack is empty, no greater element
        if(st.empty()) {
            res[i] = -1;
        }
         // Else top of stack is the answer
        else {
            res[i] = st.top();
        }
        // Push current element
        st.push(nums[i]);
    }
    return res; // Return the result
}
int main()
{
    vector<int> nums = {4, 5, 2, 10};
    vector<int> ans = nextGreater(nums);

    for (int x : ans) {
        cout << x << " ";
    }

    cout << endl;
    return 0;
}

// T.C - O(2n)
//S.C - O(2n)