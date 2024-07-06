#include<iostream>
#include<vector>
#include<string>
using namespace std;
class Solution {
public:
    vector<vector<int>> directions = {{1,0},{-1,0},{0,1},{0,-1}};
    bool find(vector<vector<char>>& board, int i, int j, int index, string& word) {
        if (index == word.length()) {
            return true;
        }
        if (i < 0 || j < 0 || i >= board.size() || j >= board[0].size() || board[i][j] != word[index] || board[i][j] == '$') {
            return false;
        }
        char temp = board[i][j];
        board[i][j] = '$';
        for (int k = 0; k < directions.size(); k++) {
            int new_i = i + directions[k][0];
            int new_j = j + directions[k][1];
            if (find(board, new_i, new_j, index + 1, word)) {
                return true;
            }
        }
        board[i][j] = temp; // backtracking
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (board[i][j] == word[0] && find(board, i, j, 0, word)) {
                    return true;
                }
            }
        }
        return false;
    }
};
int main() {
    vector<vector<char>> board = {{'A', 'B', 'C', 'E'}, {'S', 'F', 'C', 'S'}, {'A', 'D', 'E', 'E'}};
    string word = "ABCCED";
    Solution solution;
    bool result = solution.exist(board, word);
    cout << result << endl; // Output: 1 (true)
    return 0;
}