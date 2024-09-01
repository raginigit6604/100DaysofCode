#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
       int rows = mat.size();
       int cols = mat[0].size();
        if (rows * cols != r * c) {
            return mat; 
        }
        vector<vector<int>> result(r,vector<int>(c));
        int index=0;
         int new_rows = 0;
         int new_cols = 0;
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                result[new_rows][new_cols] = mat[i][j];
                new_cols ++;
                if(new_cols == c){
                    new_rows ++;
                    new_cols = 0;
                }
            }
        }
        return result;
    }
};
int main() {
    Solution solution;
    vector<vector<int>> mat = {
        {1, 2},
        {3, 4}
    };

    int r = 1, c = 4;
    vector<vector<int>> result = solution.matrixReshape(mat, r, c);
    for (const auto& row : result) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}