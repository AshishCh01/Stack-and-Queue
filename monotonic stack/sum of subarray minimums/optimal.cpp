#include <iostream>
#include <vector>
#include <stack>
using namespace std;
int sumSubarrayMins(vector<int>& arr) {
    int MOD = 1e9 + 7;
    int n = arr.size();

    vector<int> pse(n), nse(n);
    stack<int> st;

    // Previous Smaller Element (Strictly Smaller)
    for (int i = 0; i < n; i++) {
        while (!st.empty() && arr[st.top()] > arr[i]) {
            st.pop();
        }

        if (st.empty())
            pse[i] = -1;
        else
            pse[i] = st.top();

        st.push(i);
    }

    while (!st.empty())
        st.pop();

    // Next Smaller Element (Smaller or Equal)
    for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() && arr[st.top()] >= arr[i]) {
            st.pop();
        }

        if (st.empty())
            nse[i] = n;
        else
            nse[i] = st.top();

        st.push(i);
    }

    long long ans = 0;

    for (int i = 0; i < n; i++) {
        long long left = i - pse[i];
        long long right = nse[i] - i;

        ans = (ans + (left * right % MOD) * arr[i] % MOD) % MOD;
    }

    return (int)ans;
}
int main()
{
    vector<int> arr = {3,1,2,4};
    cout << sumSubarrayMins(arr);
    return 0;
}