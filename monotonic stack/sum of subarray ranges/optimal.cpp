#include <bits/stdc++.h>
using namespace std;

// Next Smaller Element
vector<int> findNSE(vector<int>& arr) {
    int n = arr.size();
    vector<int> ans(n);
    stack<int> st;

    for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() && arr[st.top()] >= arr[i])
            st.pop();

        ans[i] = st.empty() ? n : st.top();
        st.push(i);
    }

    return ans;
}

// Previous Smaller or Equal Element
vector<int> findPSEE(vector<int>& arr) {
    int n = arr.size();
    vector<int> ans(n);
    stack<int> st;

    for (int i = 0; i < n; i++) {
        while (!st.empty() && arr[st.top()] > arr[i])
            st.pop();

        ans[i] = st.empty() ? -1 : st.top();
        st.push(i);
    }

    return ans;
}

// Next Greater Element
vector<int> findNGE(vector<int>& arr) {
    int n = arr.size();
    vector<int> ans(n);
    stack<int> st;

    for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() && arr[st.top()] <= arr[i])
            st.pop();

        ans[i] = st.empty() ? n : st.top();
        st.push(i);
    }

    return ans;
}

// Previous Greater or Equal Element
vector<int> findPGEE(vector<int>& arr) {
    int n = arr.size();
    vector<int> ans(n);
    stack<int> st;

    for (int i = 0; i < n; i++) {
        while (!st.empty() && arr[st.top()] < arr[i])
            st.pop();

        ans[i] = st.empty() ? -1 : st.top();
        st.push(i);
    }

    return ans;
}

long long sumSubarrayMins(vector<int>& arr) {
    vector<int> nse = findNSE(arr);
    vector<int> psee = findPSEE(arr);

    long long sum = 0;
    int n = arr.size();

    for (int i = 0; i < n; i++) {
        long long left = i - psee[i];
        long long right = nse[i] - i;

        sum += 1LL * arr[i] * left * right;
    }

    return sum;
}

long long sumSubarrayMaxs(vector<int>& arr) {
    vector<int> nge = findNGE(arr);
    vector<int> pgee = findPGEE(arr);

    long long sum = 0;
    int n = arr.size();

    for (int i = 0; i < n; i++) {
        long long left = i - pgee[i];
        long long right = nge[i] - i;

        sum += 1LL * arr[i] * left * right;
    }

    return sum;
}


long long subArrayRanges(vector<int>& arr) {
    return sumSubarrayMaxs(arr) - sumSubarrayMins(arr);
}

int main()
{
    vector<int> arr = {1,2,3};
    cout << subArrayRanges(arr);
    return 0;
}