#include <iostream>
using namespace std;

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* solve(TreeNode* root, TreeNode* p, TreeNode* q) {
       if(!root){
            return NULL;
        }
        if(root == p || root == q){
            return root;
        }
        TreeNode* lst = solve(root->left,p,q);
        TreeNode* rst = solve(root->right,p,q);
        if(lst && rst){
            return root;
        }
        else if(lst){
            return lst;
        }
        else if(rst){
            return rst;
        }
        return NULL;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return solve(root, p, q);
    }
};

    // bool findpath(TreeNode* root,TreeNode* node,vector<TreeNode*>& path){
    //       //base case
    //      if(root == node){
    //         path.push_back(root);
    //         return true;
    //      }
    //      if(root== NULL){
    //         return false;
    //      }
    //      path.push_back(root);
    //      if(findpath(root->left,node,path)){
    //         return true;
    //      }
         
    //      if(findpath(root->right,node,path)){
    //         return true;
    //      }
    //      path.pop_back();
    //      return false;

    // }
    // TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    //    if(!root){
    //       return NULL;
    //    }
    //   vector<TreeNode*> path1,path2;
    //   findpath(root,p,path1);
    //   findpath(root,q,path2);
    //   for(int i = min(path1.size(),path2.size()) - 1;i>=0;i--){ // for index
    //     if(path1[i] == path2[i]){
    //          return path1[i];
    //     }
    //   } 
    //   return NULL; 
    // }
    // };


// Helper function to create a new tree node
TreeNode* newNode(int val) {
    TreeNode* node = new TreeNode(val);
    node->left = nullptr;
    node->right = nullptr;
    return node;
}

int main() {
    // Create a sample binary tree
    TreeNode* root = newNode(3);
    root->left = newNode(5);
    root->right = newNode(1);
    root->left->left = newNode(6);
    root->left->right = newNode(2);
    root->right->left = newNode(0);
    root->right->right = newNode(8);
    root->left->right->left = newNode(7);
    root->left->right->right = newNode(4);

    Solution sol;
    TreeNode* p = root->left; // Node with value 5
    TreeNode* q = root->right; // Node with value 1

    TreeNode* lca = sol.lowestCommonAncestor(root, p, q);

    if (lca) {
        cout << "Lowest Common Ancestor: " << lca->val << endl;
    } else {
        cout << "Lowest Common Ancestor not found" << endl;
    }

    return 0;
}
