#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
// here i use dfs approach to starting with current, and recursively builds new numbers by appending digits 0-9 to current.
   //Time Complexity: O(n), since we are visiting each number from 1 to n exactly once.
   //Space Complexity: O(n) for the result vector, but the recursive stack space is O(log n), as each recursive call goes deeper by adding digits.
    void solve(int current,int n,vector<int>& result){
        if(current > n){
            return;
        }
        result.push_back(current);
        for(int i=0;i<=9;i++){
            int newNum = current * 10 + i;
            if(newNum > n){
                return;
            }
            solve(newNum,n,result);
        }
    }
    vector<int> lexicalOrder(int n) {
      vector<int> result;
      for(int start= 1;start <= 9;start++){
            solve(start,n,result);

      }
      return result;
        // here i use DFS approach to find all the numbers in range [1 to n] in lexicographical order
         // T.c = O(n)s we are iterating from 1 to n and visiting each number once.,s.c = O(1)extra space (excluding the result vector).
        // vector<int> ans;
        // int curr = 1;
        // for(int i=0;i<n;i++){
        //     ans.push_back(curr);
        //     if(curr * 10 <= n){
        //         curr *= 10;
        //     }
        //     else{
        //         if(curr >= n){
        //             curr /= 10;
        //         }
        //         curr++; // here i move to the next
        //         while(curr % 10 == 0){
        //         curr /= 10;
        //         }
        //     }
        // }
        // return ans;
        
    }
};
int main() {
    int n = 13;
    Solution sol;
    vector<int> result = sol.lexicalOrder(n);
    
    // Print the result
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}