#include <iostream>

// Definition for a binary tree node.
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
    int diameter(TreeNode* root, int& ans) {
        if (root == NULL)
            return 0;

        int lt = diameter(root->left, ans);
        int rt = diameter(root->right, ans);
        // diameter calculation
        ans = std::max(ans, lt + rt);
        // height calculation
        return std::max(lt, rt) + 1;
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        int ans = 0;
        diameter(root, ans);
        return ans;
    }
};

int main() {
    // Create a binary tree: 
    //       1
    //      / \
    //     2   3
    //    / \
    //   4   5
    
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    
    Solution solution;
    int diameter = solution.diameterOfBinaryTree(root);
    
    std::cout << "Diameter of the binary tree: " << diameter << std::endl;
    
    // Clean up the allocated nodes
    delete root->left->left;
    delete root->left->right;
    delete root->left;
    delete root->right;
    delete root;
    
    return 0;
}
