// circular queue using array

#include <iostream>
using namespace std;

class CircularQueue {
private:
    int arr[5];
    int front;
    int rear;
    int size;
    int capacity;

public:
    CircularQueue() {
        front = -1;
        rear = -1;
        size = 0;
        capacity = 5;
    }

    // Insert an element
    void enqueue(int x) {
        if (size == capacity) {
            cout << "Queue Overflow" << endl;
            return;
        }

        // First element
        if (front == -1) {
            front = 0;
            rear = 0;
        }
        else {
            rear = (rear + 1) % capacity;
        }

        arr[rear] = x;
        size++;
    }

    // Remove an element
    int dequeue() {
        if (size == 0) {
            cout << "Queue Underflow" << endl;
            return -1;
        }

        int value = arr[front];

        // If only one element is present
        if (size == 1) {
            front = -1;
            rear = -1;
        }
        else {
            front = (front + 1) % capacity;
        }

        size--;

        return value;
    }

    // Return front element
    int Front() {
        if (size == 0) {
            cout << "Queue is Empty" << endl;
            return -1;
        }

        return arr[front];
    }

    bool isEmpty() {
        return size == 0;
    }

    bool isFull() {
        return size == capacity;
    }
};

int main() {
    CircularQueue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    cout << "Front: " << q.Front() << endl;

    cout << "Removed: " << q.dequeue() << endl;

    cout << "Front: " << q.Front() << endl;

    q.enqueue(40);
    q.enqueue(50);
    q.enqueue(60);

    while (!q.isEmpty()) {
        cout << q.dequeue() << " ";
    }

    return 0;
}