#include <bits/stdc++.h>
using namespace std;
class MyCircularQueue {
public:
    vector<int> queue; 
    int k;             // k is the maximum size of the queue
    int front; 
    int rear;         
    int currentCount; // Current number of elements in the queue

    MyCircularQueue(int k) {
        this->k = k;
        queue = vector<int>(k); 
        front = 0;
        rear = -1; // Rear is initialized to -1 because it will be incremented on the first enqueue
        currentCount = 0; // Initially, the queue is empty
    }
    
    bool enQueue(int value) {
        if (isFull()) {
           return false;
        } 
        rear = (rear + 1) % k; // Circular increment
        queue[rear] = value; 
        currentCount++; 
        return true; 
    }
    
    bool deQueue() {
        if (isEmpty()) {
           return false; 
        }
        front = (front + 1) % k; 
        currentCount--; 
        return true; 
    }
    
    int Front() {
        if (isEmpty()) {
            return -1; 
        }
        return queue[front]; 
    }
    
    int Rear() {
        if (isEmpty()) return -1; 
        return queue[rear]; 
    }
    
    bool isEmpty() {
        return currentCount == 0; 
    }
    
    bool isFull() {
        return currentCount == k; 
    }
};


int main() {
    // Initialize the circular queue with a size of 5
    MyCircularQueue* obj = new MyCircularQueue(5);
    
    // Enqueue elements
    cout << "Enqueue 10: " << obj->enQueue(10) << endl; // Should return true
    cout << "Enqueue 20: " << obj->enQueue(20) << endl; // Should return true
    cout << "Enqueue 30: " << obj->enQueue(30) << endl; // Should return true
    cout << "Enqueue 40: " << obj->enQueue(40) << endl; // Should return true
    cout << "Enqueue 50: " << obj->enQueue(50) << endl; // Should return true
    cout << "Enqueue 60 (full): " << obj->enQueue(60) << endl; // Should return false

    // Display front and rear elements
    cout << "Front: " << obj->Front() << endl; // Should return 10
    cout << "Rear: " << obj->Rear() << endl; // Should return 50

    // Dequeue an element
    cout << "Dequeue: " << obj->deQueue() << endl; // Should return true

    // Display front and rear elements again
    cout << "Front after dequeue: " << obj->Front() << endl; // Should return 20
    cout << "Rear: " << obj->Rear() << endl; // Should return 50

    // Enqueue more elements
    cout << "Enqueue 60: " << obj->enQueue(60) << endl; // Should return true

    // Display front and rear again
    cout << "Front: " << obj->Front() << endl; // Should return 20
    cout << "Rear: " << obj->Rear() << endl; // Should return 60

    // Check if the queue is empty or full
    cout << "Is queue empty? " << obj->isEmpty() << endl; // Should return false
    cout << "Is queue full? " << obj->isFull() << endl; // Should return false

    // Clean up
    delete obj;
    return 0;
}

