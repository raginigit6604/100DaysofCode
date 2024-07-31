#include<bits/stdc++.h>
using namespace std;

class node {
    public:
    int data;
    node* left;
    node* right;
    
    node(int data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

node* insertBST(node* root, int data) {
    if(root == NULL) {
        root = new node(data);
        return root;
    }
    if(data < root->data) {
        root->left = insertBST(root->left, data);
    } else {
        root->right = insertBST(root->right, data);
    }
    return root;
}

node* createBST() {
    int data;
    cin >> data;
    if(data == -1) {
        return NULL;
    }
    node* root = NULL;
    while(data != -1) {
        root = insertBST(root, data);
        cin >> data;
    }
    return root;
}

void inorderPrint(node* root) {
    if(root == NULL) {
        return;
    }
    inorderPrint(root->left);
    cout << root->data << " ";
    inorderPrint(root->right);
}

vector<int> convertTreetoArray(node* root, vector<int>& arr) {  
    if(!root) {
        return arr;
    }
    convertTreetoArray(root->left, arr);
    arr.push_back(root->data);
    convertTreetoArray(root->right, arr);
    return arr;
}

int kthSmallest(node* root, int k) {
    priority_queue<int> pq;
    vector<int> arr;
    convertTreetoArray(root, arr);
    int n = arr.size();
    for(int i = 0; i < n; i++) {
        pq.push(arr[i]);
        if(pq.size() > k) {
            pq.pop();
        }
    }
    return pq.top();
}

int main() {
    node* root = createBST();
    
    cout << "Inorder Traversal of BST: ";
    inorderPrint(root);
    cout << endl;
    
    int k;
    cout << "Enter value of k: ";
    cin >> k;
    
    int kthSmallestElement = kthSmallest(root, k);
    cout <<"kth smallest element in the BST is: " << kthSmallestElement << endl;
    
    return 0;
}
