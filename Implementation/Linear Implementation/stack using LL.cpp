#include <iostream>
using namespace std;

// Node class
class Node {
public:
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = nullptr;
    }
};

// Stack class
class Stack {
private:
    Node* topNode;
    int count;

public:
    // Constructor
    Stack() {
        topNode = nullptr;
        count = 0;
    }

    // Push operation
    void push(int value) {
        Node* newNode = new Node(value);

        newNode->next = topNode;
        topNode = newNode;

        count++;

        cout << value << " pushed into stack.\n";
    }

    // Pop operation
    void pop() {
        if (isEmpty()) {
            cout << "Stack Underflow!\n";
            return;
        }

        Node* temp = topNode;
        cout << temp->data << " popped from stack.\n";

        topNode = topNode->next;
        delete temp;

        count--;
    }

    // Return top element
    int top() {
        if (isEmpty()) {
            cout << "Stack is empty.\n";
            return -1;
        }

        return topNode->data;
    }

    // Check if stack is empty
    bool isEmpty() {
        return topNode == nullptr;
    }

    // Return size
    int size() {
        return count;
    }

    // Display stack
    void display() {
        if (isEmpty()) {
            cout << "Stack is empty.\n";
            return;
        }

        cout << "Stack (Top -> Bottom): ";

        Node* temp = topNode;

        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }

        cout << endl;
    }

    // Destructor - It is used to delete all the nodes from the stack
    // ~Stack() {
    //     while (!isEmpty()) {
    //         pop();
    //     }
    // }
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