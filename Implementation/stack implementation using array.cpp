#include <iostream>
using namespace std;

class Stack {
private:
    int *arr;
    int top;
    int size;

public:
    Stack(int s) {
        size = s;
        arr = new int[size];
        top = -1;
    }

    void push(int x) {
        if (top == size - 1) {
            cout << "Stack Overflow\n";
            return;
        }

        arr[++top] = x;
    }

    int pop() {
        if (top == -1) {
            cout << "Stack Underflow\n";
            return -1;
        }

        return arr[top--];
    }

    int peek() {
        if (top == -1) {
            cout << "Stack is Empty\n";
            return -1;
        }

        return arr[top];
    }

    bool isEmpty() {
        return top == -1;
    }

    bool isFull() {
        return top == size - 1;
    }
};

int main() {
    Stack st(5);

    st.push(10);
    st.push(20);
    st.push(30);

    cout << "Top: " << st.peek() << endl;

    cout << "Popped: " << st.pop() << endl;
    cout << "Top: " << st.peek() << endl;

    st.push(40);
    st.push(50);
    st.push(60);

    while (!st.isEmpty()) {
        cout << st.pop() << " ";
    }

    return 0;
}

// statk creation using stl
// int main() {
//     // Declare a stack of integers
//     std::stack<int> s;

//     // Push elements onto the stack
//     s.push(10);
//     s.push(20);
//     s.push(30);

//     // View the top element (Output: 30)
//     std::cout << "Top element: " << s.top() << std::endl;

//     // Remove the top element (30)
//     s.pop();

//     // Check size and emptiness
//     std::cout << "Stack size: " << s.size() << std::endl; // Output: 2
    
//     if (s.empty()) {
//         std::cout << "Stack is empty." << std::endl;
//     } else {
//         std::cout << "Stack is not empty." << std::endl;
//     }

//     // Printing and clearing the stack
//     std::cout << "Remaining elements: ";
//     while (!s.empty()) {
//         std::cout << s.top() << " "; // Print top
//         s.pop();                     // Remove top to access next element
//     }
    
//     return 0;
// }