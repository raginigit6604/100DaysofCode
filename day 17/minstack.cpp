#include <bits/stdc++.h>
#include <string>
using namespace std;
class MinStack {
public:
   stack<int> s;
   stack<int> ss; // ss= supporting stack
    MinStack() {  // minstack is a constructor
        
    }
    
    void push(int val) {
        s.push(val);
        if(ss.empty()){
            ss.push(val);
        }
        else{
            if(ss.top()>= val){
                ss.push(val);
            }
        }
    }
    
    void pop() {
        if(s.top() == ss.top()){
           ss.pop();
        }
            s.pop();
    }
    
    int top() {
       return s.top(); 
    }
    
    int getMin() {
       return ss.top(); 
    }
};

int main() {
    MinStack minStack;
    
    minStack.push(3);
    minStack.push(5);
    cout << "Current Min: " << minStack.getMin() << endl; // Expected output: 3
    
    minStack.push(2);
    minStack.push(1);
    cout << "Current Min: " << minStack.getMin() << endl; // Expected output: 1
    
    minStack.pop();
    cout << "Current Min: " << minStack.getMin() << endl; // Expected output: 2
    
    minStack.pop();
    cout << "Current Top: " << minStack.top() << endl;    // Expected output: 5
    cout << "Current Min: " << minStack.getMin() << endl; // Expected output: 3
    
    minStack.pop();
    cout << "Current Top: " << minStack.top() << endl;    // Expected output: 3
    cout << "Current Min: " << minStack.getMin() << endl; // Expected output: 3
    
    return 0;
}