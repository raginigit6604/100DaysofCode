#include <iostream>
using namespace std;


struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    bool solve(ListNode* head, TreeNode* root) {
        if (head == NULL) {
            return true;  
        }
        if (root == NULL) {
            return false;  
        }
     
        return head->val == root->val && (solve(head->next, root->left) || solve(head->next, root->right));
    }

    bool isSubPath(ListNode* head, TreeNode* root) {
        if (root == NULL) {
            return false; 
        }
      
        return solve(head, root) || isSubPath(head, root->left) || isSubPath(head, root->right);
    }
};

int main() {
    // Create the linked list: 4 -> 2 -> 8
    ListNode* head = new ListNode(4);
    head->next = new ListNode(2);
    head->next->next = new ListNode(8);

    // Create the binary tree:
    //        1
    //       / \
    //      4   4
    //     /   / \
    //    2   2   5
    //   / \   \
    //  1   6   8
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(4);
    root->right = new TreeNode(4);
    root->left->left = new TreeNode(2);
    root->left->left->left = new TreeNode(1);
    root->left->left->right = new TreeNode(6);
    root->right->left = new TreeNode(2);
    root->right->left->right = new TreeNode(8);
    root->right->right = new TreeNode(5);

    Solution sol;

    if (sol.isSubPath(head, root)) {
        cout << "The linked list is a subpath in the binary tree." << endl;
    } else {
        cout << "The linked list is not a subpath in the binary tree." << endl;
    }

    return 0;
}
