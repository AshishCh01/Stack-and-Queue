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

// Queue class
class Queue {
private:
    Node* front;
    Node* rear;
    int count;

public:
    // Constructor
    Queue() {
        front = nullptr;
        rear = nullptr;
        count = 0;
    }

    // Enqueue operation
    void enqueue(int value) {
        Node* newNode = new Node(value);

        if (isEmpty()) {    // OR if(front == nullptr)
            front = rear = newNode;     
        }
        else {
            rear->next = newNode;
            rear = newNode;
        }

        count++;
        cout << value << " inserted into queue.\n";
    }

    // Dequeue operation
    void dequeue() {
        if (isEmpty()) {
            cout << "Queue Underflow!\n";
            return;
        }

        Node* temp = front;
        cout << temp->data << " removed from queue.\n";

        front = front->next;

        // Queue becomes empty
        if (front == nullptr) {
            rear = nullptr;
        }

        delete temp;
        count--;
    }

    // Peek operation
    int peek() {
        if (isEmpty()) {
            cout << "Queue is empty.\n";
            return -1;
        }

        return front->data;
    }

    // Check if queue is empty
    bool isEmpty() {
        return front == nullptr;
    }

    // Return size
    int size() {
        return count;
    }

    // Display queue
    void display() {
        if (isEmpty()) {
            cout << "Queue is empty.\n";
            return;
        }

        cout << "Queue (Front -> Rear): ";

        Node* temp = front;

        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }

        cout << endl;
    }

    // Destructor
    ~Queue() {
        while (!isEmpty()) {
            Node* temp = front;
            front = front->next;
            delete temp;
        }
        rear = nullptr;
    }
};

int main() {

    Queue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);

    q.display();

    cout << "Front Element: " << q.peek() << endl;

    q.dequeue();
    q.display();

    cout << "Current Size: " << q.size() << endl;

    return 0;
}