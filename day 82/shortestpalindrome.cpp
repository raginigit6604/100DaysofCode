#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string shortestPalindrome(string s) {       
        // int n = s.length();
        // string revers = s;
        // reverse(revers.begin(),revers.end());
        // this code give mwmory limit exceed because hum baar substring found kr rahe hai
        // so, T.c = O(n^2), s.c = O(n);
        // for(int i=0;i<n;i++){
        //    if(s.substr(0,n - i) == revers.substr(i)){
        //       return revers.substr(0,i)+s;
        //    }
        // }

        // now we use memcmp in function in c++ that compare the string
        //   for(int i=0;i<n;i++){
        //     if(!memcmp(s.c_str(),revers.c_str()+i,n-i)){
        //         return revers.substr(0,i)+s;
        //     }
        //   }
        // return revers + s;

        // here i use Longest proper substring (lps algorithm)
       int n = s.length();
        string revers = s;
        reverse(revers.begin(), revers.end()); 
        string combined = s + "#" + revers; // Combining s, #, and reversed s

        int x = combined.length();
        vector<int> lps(x, 0);  

        for (int i = 1; i < x; i++) {
            int j = lps[i - 1];
            while (j > 0 && combined[i] != combined[j]) {
                j = lps[j - 1];
            }
            if (combined[i] == combined[j]) {
                j++;
            }
            lps[i] = j;
        }
        int longest_palindrome_prefix_len = lps.back();
        return revers.substr(0, s.size() - longest_palindrome_prefix_len) + s;
    }
};
 int main() {
    Solution solution;

    // Test case 1
    string s1 = "aacecaaa";
    string result1 = solution.shortestPalindrome(s1);
    cout << "Shortest palindrome for '" << s1 << "' is: " << result1 << endl;

    // Test case 2
    string s2 = "abcd";
    string result2 = solution.shortestPalindrome(s2);
    cout << "Shortest palindrome for '" << s2 << "' is: " << result2 << endl;

    // Test case 3
    string s3 = "racecar";
    string result3 = solution.shortestPalindrome(s3);
    cout << "Shortest palindrome for '" << s3 << "' is: " << result3 << endl;

    return 0;
}