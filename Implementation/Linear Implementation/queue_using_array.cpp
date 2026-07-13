#include <iostream>
using namespace std;

class Queue {
private:
    int *arr;
    int front;
    int rear;
    int size;

public:
    Queue(int s) {
        size = s;
        arr = new int[size];
        front = 0;
        rear = -1;
    }

    void enqueue(int x) {
        if (rear == size - 1) {
            cout << "Queue Overflow\n";
            return;
        }

        arr[++rear] = x;
    }

    int dequeue() {
        if (isEmpty()) {
            cout << "Queue Underflow\n";
            return -1;
        }

        return arr[front++];
    }

    int Front() {
        if (isEmpty()) {
            cout << "Queue is Empty\n";
            return -1;
        }

        return arr[front];
    }

    bool isEmpty() {
        return front > rear;
    }

    bool isFull() {
        return rear == size - 1;
    }
};

int main() {
    Queue q(5);

    q.enqueue(10);  // enqueue is the function name
    q.enqueue(20);
    q.enqueue(30);

    cout << "Front: " << q.Front() << endl;

    cout << "Dequeued: " << q.dequeue() << endl;

    cout << "Front: " << q.Front() << endl;

    q.enqueue(40);
    q.enqueue(50);

    while (!q.isEmpty()) {
        cout << q.dequeue() << " ";
    }

    return 0;
}

// Queue creation using stl
// int main() {
//     std::queue<int> q;

//     // Push elements into the queue (Enqueue)
//     q.push(10);
//     q.push(20);
//     q.push(30);

//     // View front and back elements
//     std::cout << "Front element: " << q.front() << std::endl; // Outputs 10
//     std::cout << "Back element: " << q.back() << std::endl;   // Outputs 30

//     // Remove elements from the queue (Dequeue)
//     q.pop(); // Removes 10

//     std::cout << "New front element: " << q.front() << std::endl; // Outputs 20
//     std::cout << "Queue size: " << q.size() << std::endl;         // Outputs 2

//     return 0;
// }