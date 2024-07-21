// Count no. of nodes in a Binary Tree
#include <bits/stdc++.h>
using namespace std;
class node{
    public:
    int data;
    node* left;
    node* right;
        node(int val){
            data = val;
            left = NULL;
            right = NULL;
        }
};
node*BuildTree(){
    int data;
    cin>>data;
    // data == -1 (Base case)
    if(data==-1){
        return NULL;
    }
    node*root=new node(data);
    root->left=BuildTree();
    root->right=BuildTree();

    return root;
};
int countNodes(node* root){
    if(root == NULL)
    return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}
int main(){
    node*root=BuildTree();
    cout<<"Total node in binary tree: ";
    cout<<countNodes(root);
}