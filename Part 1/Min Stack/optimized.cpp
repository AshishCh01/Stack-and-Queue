#include <bits/stdc++.h>
using namespace std;

class MinStack {
private:
    stack<int> st;
    stack<int> minSt;

public:
    MinStack() {

    }

    void push(int val) {
        st.push(val);

        if (minSt.empty()) {
            minSt.push(val);
        }
        else {
            minSt.push(min(val, minSt.top()));
        }
    }

    void pop() {
        if (!st.empty()) {
            st.pop();
            minSt.pop();
        }
    }

    int top() {
        return st.top();
    }

    int getMin() {
        return minSt.top();
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