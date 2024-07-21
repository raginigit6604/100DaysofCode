#include <iostream>
#include <algorithm>
using namespace std;

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
    int maxDepth(TreeNode* root) {
        if (root == NULL)
            return 0;
        if (root->left == NULL)
            return 1 + maxDepth(root->right);
        if (root->right == NULL)
            return 1 + maxDepth(root->left);

        int h1 = maxDepth(root->left);
        int h2 = maxDepth(root->right);

        return 1 + max(h1, h2);
    }
};

// Function to build a binary tree from user input
TreeNode* BuildTree() {
    int data;
    cin >> data;

    // Base case: if data is -1, return NULL
    if (data == -1) {
        return NULL;
    }

    // Create a new node with the given data
    TreeNode* root = new TreeNode(data);

    // Recursively build the left and right subtrees
    root->left = BuildTree();
    root->right = BuildTree();

    return root;
}

int main() {
    // Build the binary tree from user input
    cout << "Enter the tree nodes in level order (use -1 for NULL):" << endl;
    TreeNode* root = BuildTree();

    // Create an instance of Solution
    Solution sol;

    // Find the maximum depth of the binary tree
    int depth = sol.maxDepth(root);

    // Output the maximum depth
    cout << "Maximum Depth of Binary Tree: " << depth << endl;

    return 0;
}
