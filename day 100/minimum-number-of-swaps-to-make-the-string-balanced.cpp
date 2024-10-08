#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minSwaps(string s) {
        int n = s.length();
        int size = 0;
        for(char& c: s){
            if(c == '['){
                size++;
            }
            else if(size > 0){
                size--;
            }
        }
        return (size+1) / 2;
        // stack<char> st;
        // for(int i = 0;i<n;i++){
        //     if(s[i] == '['){
        //         st.push(s[i]);
        //     }
        //     else if(!st.empty()){
        //         st.pop();
        //     }
        // }
        // return (st.size() + 1)/2;
    }
};

int main() {
    Solution solution;
    
    // Example input
    string s;
    cout << "Enter the string of brackets: ";
    cin >> s;
    
    // Calculate the minimum number of swaps
    int result = solution.minSwaps(s);
    
    // Output the result
    cout << "Minimum number of swaps to make the string balanced: " << result << endl;
    
    return 0;
}
