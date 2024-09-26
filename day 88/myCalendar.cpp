#include<bits/stdc++.h>
using namespace std;

class MyCalendar {
public:
    set<pair<int,int>> st;
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        auto it = st.lower_bound({start, end});
        
        // Check if the new event overlaps with the next event
        if (it != st.end() && it->first < end) {
            return false;
        }
        
        // Check if the new event overlaps with the previous event
        if (it != st.begin()) {
            auto prev_it = prev(it);
            if (start < prev_it->second) {
                return false;
            }
        }
        
        // Insert the new event into the set
        st.insert({start, end});
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */
int main() {
    MyCalendar* myCalendar = new MyCalendar();

    // Test case 1: Booking event [10, 20]
    if (myCalendar->book(10, 20)) {
        cout << "Booking [10, 20] successful." << endl;
    } else {
        cout << "Booking [10, 20] failed." << endl;
    }

    // Test case 2: Booking event [15, 25], overlaps with [10, 20]
    if (myCalendar->book(15, 25)) {
        cout << "Booking [15, 25] successful." << endl;
    } else {
        cout << "Booking [15, 25] failed." << endl;
    }

    // Test case 3: Booking event [20, 30], no overlap with [10, 20]
    if (myCalendar->book(20, 30)) {
        cout << "Booking [20, 30] successful." << endl;
    } else {
        cout << "Booking [20, 30] failed." << endl;
    }

    delete myCalendar; 
    return 0;
}
