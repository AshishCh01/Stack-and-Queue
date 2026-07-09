#include <iostream>
#include <stack>
using namespace std;
class MinStack {
private:
    stack<long long> st;
    long long mini;

public:
    MinStack() {

    }

    void push(int val) {

        if (st.empty()) {
            mini = val;
            st.push(val);
        }
        else {

            if (val >= mini) {
                st.push(val);
            }
            else {
                st.push(2LL * val - mini);  // 2ll is a long long
                mini = val;
            }
        }
    }

    void pop() {

        if (st.empty()) return;

        if (st.top() >= mini) {
            st.pop();
        }
        else {
            mini = 2LL * mini - st.top();
            st.pop();
        }
    }

    int top() {

        if (st.top() >= mini)
            return st.top();

        return mini;
    }

    int getMin() {
        return mini;
    }
};

int main()
{
    
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