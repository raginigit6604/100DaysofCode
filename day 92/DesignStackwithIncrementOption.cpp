#include <iostream>
#include <vector>

using namespace std;

class CustomStack {
public:
    vector<int> result;
    int max = 0;
    
    CustomStack(int maxSize) {
        max = maxSize;
    }
    
    void push(int x) {
        if(result.size() < max){
            result.push_back(x);
        }
    }
    
    int pop() {
        if(result.empty()){
            return -1;
        }
        int x = result.back();
        result.pop_back();
        return x;
    }
    
    void increment(int k, int val) {
        int limit = min(k, (int)result.size());
        for(int i = 0; i < limit; i++){
            result[i] += val;
        }
    }
};

int main() {
    // Create a custom stack with max size 5
    CustomStack* stack = new CustomStack(5);
    
    // Push elements onto the stack
    stack->push(5);
    stack->push(2);
    stack->push(3);
    cout << "Stack after pushes: ";
    for(int i : stack->result) {
        cout << i << " ";
    }
    cout << endl;

    // Increment the bottom 2 elements by 100
    stack->increment(2, 100);
    cout << "Stack after increment(2, 100): ";
    for(int i : stack->result) {
        cout << i << " ";
    }
    cout << endl;

    // Pop an element
    cout << "Popped element: " << stack->pop() << endl;

    // Check the stack after pop
    cout << "Stack after pop: ";
    for(int i : stack->result) {
        cout << i << " ";
    }
    cout << endl;

    // Increment the bottom 3 elements by 50
    stack->increment(3, 50);
    cout << "Stack after increment(3, 50): ";
    for(int i : stack->result) {
        cout << i << " ";
    }
    cout << endl;

    // Pop remaining elements
    while(stack->result.size() > 0) {
        cout << "Popped element: " << stack->pop() << endl;
    }
    
    // Trying to pop from an empty stack
    cout << "Popped element from empty stack: " << stack->pop() << endl;

    delete stack;
    return 0;
}
