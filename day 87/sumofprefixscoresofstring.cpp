#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    struct trienode {
        int count = 0;
        trienode* children[26];
    };

    trienode* getnode() { 
        trienode* new_node = new trienode();
        for (int i = 0; i < 26; i++) {
            new_node->children[i] = NULL;
        }
        new_node->count = 0;
        return new_node;
    }

    void insert(string& word, trienode* root) { 
        trienode* crawl = root;
        for (char& ch : word) {
            int index = ch - 'a';
            if (!crawl->children[index]) {
                crawl->children[index] = getnode(); 
            }
            crawl->children[index]->count += 1;
            crawl = crawl->children[index];
        }
    }

    int getscore(string word, trienode* root) {
        trienode* crawl = root;
        int score = 0;
        for (char& ch : word) {
            int index = ch - 'a';
            if (crawl->children[index] == NULL) {
                return score; 
            }
            score += crawl->children[index]->count;
            crawl = crawl->children[index];
        }
        return score; 
    }

    vector<int> sumPrefixScores(vector<string>& words) {
        int n = words.size();
        trienode* root = getnode();
        for (string& word : words) { 
            insert(word, root); 
        }
        vector<int> result(n);
        for (int i = 0; i < n; i++) {
            result[i] = getscore(words[i], root);
        }
        return result;
    }
};

int main() {
    // Create a Solution object
    Solution solution;

    // Test case: list of words
    vector<string> words = {"abc", "ab", "bc", "b"};

    // Call the sumPrefixScores function
    vector<int> result = solution.sumPrefixScores(words);

    // Output the result
    cout << "Prefix Scores: ";
    for (int score : result) {
        cout << score << " ";
    }
    cout << endl;

    return 0;
}
