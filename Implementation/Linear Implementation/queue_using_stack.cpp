#include <iostream>
#include <stack>
using namespace std;

class Queue {
private:
    stack<int> s1;
    stack<int> s2;

public:

    // Push operation   T.C - O(2n)
    void push(int value) {

        // Move all elements from s1 to s2
        while (!s1.empty()) {
            s2.push(s1.top());
            s1.pop();
        }

        // Insert new element
        s1.push(value);

        // Move all elements back to s1
        while (!s2.empty()) {
            s1.push(s2.top());
            s2.pop();
        }

        cout << value << " inserted into queue.\n";
    }

    // Pop operation
    void pop() {

        if (isEmpty()) {
            cout << "Queue Underflow!\n";
            return;
        }

        cout << s1.top() << " removed from queue.\n";
        s1.pop();
    }

    // Peek operation
    int peek() {

        if (isEmpty()) {
            cout << "Queue is empty.\n";
            return -1;
        }

        return s1.top();
    }

    // Check if queue is empty
    bool isEmpty() {
        return s1.empty();
    }

    // Return size
    int size() {
        return s1.size();
    }

    // Display queue
    void display() {

        if (isEmpty()) {
            cout << "Queue is empty.\n";
            return;
        }

        stack<int> temp = s1;

        cout << "Queue (Front -> Rear): ";

        while (!temp.empty()) {
            cout << temp.top() << " ";
            temp.pop();
        }

        cout << endl;
    }
};

int main() {

    Queue q;

    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);

    q.display();

    cout << "Front Element: " << q.peek() << endl;

    q.pop();

    q.display();

    cout << "Current Size: " << q.size() << endl;

    return 0;
}