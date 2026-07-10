#include <bits/stdc++.h>
using namespace std;
vector<int> nextGreaterElements(vector<int>& arr) {
    int n = arr.size();
    stack<int> st;
    vector<int> ans(n);
    // Start traversing from the back
    for(int i = 2*n-1; i >= 0; i--) {
        
        // Get the actual index
        int ind = i % n;
        
        // Get the current element
        int currEle = arr[ind];
        
        /* Pop the elements in the stack until 
        the stack is not empty and the top 
        element is not the greater element */
        while(!st.empty() && st.top() <= currEle) {
            st.pop();
        }
        
        // Store the answer for the second half
        if(i < n) {
            
            /* If the greater element is not 
            found, stack will be empty */
            if(st.empty()) 
                ans[i] = -1;
                
            // Else store the answer
            else 
                ans[i] = st.top();
        }
        
        /* Push the current element in the stack 
        maintaining the decreasing order */
        st.push(currEle);
    }
    
    // Return the result
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