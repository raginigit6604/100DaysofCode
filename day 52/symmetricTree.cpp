#include <iostream>
using namespace std;

class TreeNode {
public:
    int val;
    TreeNode *left;
    TreeNode *right;
    
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    bool solve(TreeNode* left, TreeNode* right) {
        if (left == nullptr && right == nullptr) {
            return true;
        }
        if (left == nullptr || right == nullptr) {
            return false;
        }
        return (left->val == right->val && solve(left->left, right->right) && solve(left->right, right->left));
    }

    bool isSymmetric(TreeNode* root) {
        if (root == nullptr) return true;
        return solve(root->left, root->right);  
    }
};

TreeNode* newNode(int data) {
    return new TreeNode(data);
}

int main() {
    // Creating the following tree:
    //         1
    //       /   \
    //      2     2
    //     / \   / \
    //    3   4 4   3
    
    TreeNode* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(2);
    root->left->left = newNode(3);
    root->left->right = newNode(4);
    root->right->left = newNode(4);
    root->right->right = newNode(3);
    
    Solution solution;
    bool result = solution.isSymmetric(root);
    
    if(result) {
        cout << "The tree is symmetric." << endl;
    } else {
        cout << "The tree is not symmetric." << endl;
    }
    
    return 0;
}
