#include<bits/stdc++.h>
using namespace std;
class node{
    public:
    int data;
    node* left;
    node* right;
    node(int data){
        this->data = data;
        left = NULL;
        right = NULL;
    }
};
node* insertBST(node* root,int data){
   if(root == NULL){
    root = new node(data);
    return root;
   }
    if(data < root->data){
        //data jo hai vo root ke data se chota hai
      root->left = insertBST(root->left,data);
    }
    else{
        //data jo hai vo root ke data se bada hai
        root->right = insertBST(root->right,data);
    }
    return root;
}
node* createBST(){
    int data;
    cin>>data;
    if(data == -1){
        return NULL;
    }
    node* root= NULL;
    while(data != -1){
        root = insertBST(root,data);
        cin>>data;
    }
    return root;
}

void preorder(node* root){
    if(!root){
        return;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

void inorder(node* root){
    if(!root){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

void postorder(node* root){
    if(!root){
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}
int rangeSumBST(node* root, int low, int high) {
        if(!root){
            return 0;
        }
        int sum = 0;
        if(root->data >= low && root->data <= high){
            sum += root->data;
        }
        int lst = rangeSumBST(root->left,low,high);
        int rst = rangeSumBST(root->right,low,high);
        return sum + lst + rst;
    }
int main(){
      node* root = createBST();
      int low,high;
      cin>>low>>high;
      cout<<"PreOrder"<<endl;
      preorder(root);
      cout<<endl;
      cout<<"postorder"<<endl;
      postorder(root);
      cout<<endl;
      cout<<"InOrder"<<endl;
      inorder(root);
      cout<<endl; 
     int sum = rangeSumBST(root,low,high);
     cout<<"Sum is : "<<sum<<endl;
      
    return 0;
}