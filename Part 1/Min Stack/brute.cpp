#include <bits/stdc++.h>
using namespace std;
class MinStack {
private:
    stack<int> st;

public:
    MinStack() {

    }

    void push(int val) {
        st.push(val);
    }

    void pop() {
        if (!st.empty()) {
            st.pop();
        }
    }

    int top() {
        return st.top();
    }

    int getMin() {
        stack<int> temp;
        int mini = INT_MAX;

        // Find the minimum element
        while (!st.empty()) {
            mini = min(mini, st.top());
            temp.push(st.top());
            st.pop();
        }

        // Restore the original stack
        while (!temp.empty()) {
            st.push(temp.top());
            temp.pop();
        }

        return mini;
    }
};

int main() {

    MinStack minStack;
    minStack.push(-2);
    minStack.push(0);
    minStack.push(1);
    minStack.push(-3);
    cout << "Minimum Element: " << minStack.getMin() << endl; // Returns -3
    minStack.pop();
    cout << "Top Element: " << minStack.top() << endl;    // Returns 1
    cout << "Minimum Element: " << minStack.getMin() << endl; // Returns -2

    return 0;
}