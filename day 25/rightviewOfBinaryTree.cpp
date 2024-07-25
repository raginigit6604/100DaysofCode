#include <iostream>
#include <vector>
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    void solve(TreeNode* root, int depth, std::vector<int>& ans) {
        if (!root) {
            return;
        }
        if (depth == ans.size()) {
            ans.push_back(root->val);
        }
        solve(root->right, depth + 1, ans);
        solve(root->left, depth + 1, ans);
    }
    
    std::vector<int> rightSideView(TreeNode* root) {
        std::vector<int> ans;
        solve(root, 0, ans);
        return ans;
    }
};

int main() {
    // Create a binary tree: 
    //       1
    //      / \
    //     2   3
    //      \   \
    //       5   4
    
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(4);
    
    Solution solution;
    std::vector<int> result = solution.rightSideView(root);
    
    std::cout << "Right side view of the binary tree: ";
    for (int val : result) {
        std::cout << val << " ";
    }
    std::cout << std::endl;
    
    // Clean up the allocated nodes (simple example, not handling all nodes)
    delete root->left->right;
    delete root->right->right;
    delete root->left;
    delete root->right;
    delete root;
    
    return 0;
}
