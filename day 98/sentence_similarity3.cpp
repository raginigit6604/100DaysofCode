#include <bits/stdc++.h>
#include <string>
using namespace std;

class Solution {
public:
    bool areSentencesSimilar(string sentence1, string sentence2) {
        deque<string> a, b;
        sentence1 += ' ', sentence2 += ' ';
        string temp = "";
        
        for(int i = 0; i < sentence1.length(); i++) {
            if(sentence1[i] == ' ') {
                a.push_back(temp);
                temp = "";
            } else {
                temp += sentence1[i];
            }
        }
        
        temp = "";
        for(int i = 0; i < sentence2.length(); i++) {
            if(sentence2[i] == ' ') {
                b.push_back(temp);
                temp = "";
            } else {
                temp += sentence2[i];
            }
        }
        
        // Remove common words from the start
        while(a.size() && b.size() && a.front() == b.front()) {
            a.pop_front();
            b.pop_front();
        }
        
        // Remove common words from the end
        while(a.size() && b.size() && a.back() == b.back()) {
            a.pop_back();
            b.pop_back();
        }
        
        // If either deque is empty, the sentences are similar
        return a.empty() || b.empty();
    }
};

int main() {
    Solution solution;

    // Test case 1
    string sentence1 = "My name is Alice";
    string sentence2 = "Alice";
    bool result = solution.areSentencesSimilar(sentence1, sentence2);
    cout << "Test case 1 - Are sentences similar? " << (result ? "Yes" : "No") << endl;

    // Test case 2
    sentence1 = "This is an example";
    sentence2 = "This example";
    result = solution.areSentencesSimilar(sentence1, sentence2);
    cout << "Test case 2 - Are sentences similar? " << (result ? "Yes" : "No") << endl;

    // Test case 3
    sentence1 = "Hello world";
    sentence2 = "Hello";
    result = solution.areSentencesSimilar(sentence1, sentence2);
    cout << "Test case 3 - Are sentences similar? " << (result ? "Yes" : "No") << endl;

    return 0;
}
