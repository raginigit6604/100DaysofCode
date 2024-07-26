#include <iostream>
#include <climits>
using namespace std;

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    int solve(TreeNode* root, int& result) {
        if (!root) {
            return 0;
        }

        // Compute the maximum path sum through the left and right children
        int lt = max(solve(root->left, result), 0);
        int rt = max(solve(root->right, result), 0);

        // Compute the maximum path sum passing through the current node
        int sum = root->val + lt + rt;

        // Update the global maximum path sum if the current path sum is greater
        result = max(result, sum);

        // Return the maximum path sum starting from the current node
        return root->val + max(lt, rt);
    }

    int maxPathSum(TreeNode* root) {
        int result = INT_MIN;
        solve(root, result);
        return result;
    }
};

// Helper function to create a new tree node
TreeNode* newNode(int val) {
    TreeNode* node = new TreeNode(val);
    node->left = nullptr;
    node->right = nullptr;
    return node;
}

int main() {
    // Create a sample binary tree
    TreeNode* root = newNode(-10);
    root->left = newNode(9);
    root->right = newNode(20);
    root->right->left = newNode(15);
    root->right->right = newNode(7);

    Solution sol;
    int maxSum = sol.maxPathSum(root);

    cout << "Maximum Path Sum: " << maxSum << endl;

    return 0;
}
