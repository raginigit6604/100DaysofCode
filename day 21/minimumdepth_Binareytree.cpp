#include <bits/stdc++.h>
using namespace std;

class node {
public:
    int data;
    node* left;
    node* right;

    // Constructor to initialize a new node
    node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

// Function to build a binary tree from user input
node* BuildTree() {
    int data;
    cin >> data;

    // Base case: if data is -1, return NULL
    if (data == -1) {
        return NULL;
    }

    // Create a new node with the given data
    node* root = new node(data);

    // Recursively build the left and right subtrees
    root->left = BuildTree();
    root->right = BuildTree();

    return root;
}

// Helper function to find the minimum depth of a binary tree
int solve(node* root) {
    if (root == NULL)
        return INT_MAX;
    if (root->left == NULL && root->right == NULL)
        return 1;
    return 1 + min(solve(root->left), solve(root->right));
}

// Function to find the minimum depth of a binary tree
int minDepth(node* root) {
    if (root == NULL)
        return 0;
    return solve(root);
}

int main() {
    // Build the binary tree from user input
    node* root = BuildTree();

    // Output the minimum depth of the binary tree
    cout << "Minimum Depth of Binary Tree: " << minDepth(root);

    return 0;
}
