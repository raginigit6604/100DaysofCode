
#include <bits/stdc++.h>
using namespace std;
class MyCircularDeque {
public:
    vector<int> deq;
    int k;  // k is the maximum size of the deque
    int front;
    int rear;
    int currentCount;

    MyCircularDeque(int k) {
        this->k = k;
        deq = vector<int>(k, 0);
        front = 0;
        rear = k - 1;
        currentCount = 0;
    }
    
    bool insertFront(int value) {
        if (isFull()) {
            return false;
        }
        front = (front - 1 + k) % k; 
        deq[front] = value; // Insert value at the front
        currentCount++;
        return true;
    }
    
    bool insertLast(int value) {
        if (isFull()) {
            return false;
        }
        rear = (rear + 1) % k; 
        deq[rear] = value; 
        currentCount++;
        return true;
    }
    
    bool deleteFront() {
        if (isEmpty()) {
            return false;
        }
        front = (front + 1) % k; 
        currentCount--;
        return true;
    }
    
    bool deleteLast() {
        if (isEmpty()) {
            return false;
        }
        rear = (rear - 1 + k) % k; 
        currentCount--;
        return true;
    }
    
    int getFront() {
        if (isEmpty()) {
            return -1; 
        }
        return deq[front]; 
    }
    
    int getRear() {
        if (isEmpty()){ 
            return -1; 
        }
        return deq[rear]; 
    }
    
    bool isEmpty() {
        return currentCount == 0; // here we check if deque is empty
    }
    
    bool isFull() {
        return currentCount == k; // here we check if deque is full
    }
};


int main() {
    // Initialize the circular deque with a size of 5
    MyCircularDeque* deque = new MyCircularDeque(5);
    
    // Insert elements at the front
    cout << "Insert Front 10: " << deque->insertFront(10) << endl; // Should return true
    cout << "Insert Front 20: " << deque->insertFront(20) << endl; // Should return true
    cout << "Insert Last 30: " << deque->insertLast(30) << endl;   // Should return true
    cout << "Insert Last 40: " << deque->insertLast(40) << endl;   // Should return true
    cout << "Insert Last 50: " << deque->insertLast(50) << endl;   // Should return true
    cout << "Insert Last 60 (full): " << deque->insertLast(60) << endl; // Should return false

    // Display front and rear elements
    cout << "Front: " << deque->getFront() << endl; // Should return 20
    cout << "Rear: " << deque->getRear() << endl;   // Should return 50

    // Delete an element from the front
    cout << "Delete Front: " << deque->deleteFront() << endl; // Should return true

    // Display front and rear elements again
    cout << "Front after deleting front: " << deque->getFront() << endl; // Should return 10
    cout << "Rear: " << deque->getRear() << endl;   // Should return 50

    // Delete an element from the rear
    cout << "Delete Last: " << deque->deleteLast() << endl; // Should return true

    // Display front and rear again
    cout << "Front: " << deque->getFront() << endl; // Should return 10
    cout << "Rear after deleting last: " << deque->getRear() << endl; // Should return 40

    // Insert more elements
    cout << "Insert Front 60: " << deque->insertFront(60) << endl; // Should return true
    cout << "Insert Last 70: " << deque->insertLast(70) << endl; // Should return true

    // Display front and rear again
    cout << "Front: " << deque->getFront() << endl; // Should return 60
    cout << "Rear: " << deque->getRear() << endl;   // Should return 70

    // Check if the deque is empty or full
    cout << "Is deque empty? " << deque->isEmpty() << endl; // Should return false
    cout << "Is deque full? " << deque->isFull() << endl; // Should return false

    // Clean up
    delete deque;
    return 0;
}
