#include <iostream>
#include <queue>
using namespace std;

class Stack {
private:
    queue<int> q;

public:

    // Push operation
    void push(int value) {

        q.push(value);

        int n = q.size();

        // Rotate previous elements
        for (int i = 1; i < n; i++) {
            q.push(q.front());
            q.pop();
        }

        cout << value << " pushed into stack.\n";
    }

    // Pop operation
    void pop() {

        if (isEmpty()) {
            cout << "Stack Underflow!\n";
            return;
        }

        cout << q.front() << " popped from stack.\n";
        q.pop();
    }

    // Return top element
    int top() {

        if (isEmpty()) {
            cout << "Stack is empty.\n";
            return -1;
        }

        return q.front();
    }

    // Check if stack is empty
    bool isEmpty() {
        return q.empty();
    }

    // Return size
    int size() {
        return q.size();
    }

    // Display stack
    void display() {

        if (isEmpty()) {
            cout << "Stack is empty.\n";
            return;
        }

        queue<int> temp = q;

        cout << "Stack (Top -> Bottom): ";

        while (!temp.empty()) {
            cout << temp.front() << " ";
            temp.pop();
        }

        cout << endl;
    }
};

int main() {

    Stack st;

    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);

    st.display();

    cout << "Top Element: " << st.top() << endl;

    st.pop();

    st.display();

    cout << "Current Size: " << st.size() << endl;

    return 0;
}

// #include <queue>
// using namespace std;

// class MyStack {
// private:
//     queue<int> q;

// public:
//     MyStack() {
        
//     }

//     void push(int x) {
//         q.push(x);

//         int n = q.size();

//         // Rotate the previous elements
//         for (int i = 1; i < n; i++) {
//             q.push(q.front());
//             q.pop();
//         }
//     }

//     int pop() {
//         int value = q.front();
//         q.pop();
//         return value;
//     }

//     int top() {
//         return q.front();
//     }

//     bool empty() {
//         return q.empty();
//     }
// };

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */