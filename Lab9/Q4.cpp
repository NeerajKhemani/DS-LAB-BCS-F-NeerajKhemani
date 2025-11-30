#include <iostream>
using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;
    int height;

    Node(int v) {
        val = v;
        left = right = nullptr;
        height = 1;
    }
};

int getHeight(Node* n) {
    return n ? n->height : 0;
}

int getBalance(Node* n) {
    return n ? getHeight(n->left) - getHeight(n->right) : 0;
}

Node* rotateRight(Node* y) {
    Node* x = y->left;
    Node* t = x->right;
    x->right = y;
    y->left = t;
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
    return x;
}

Node* rotateLeft(Node* x) {
    Node* y = x->right;
    Node* t = y->left;
    y->left = x;
    x->right = t;
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
    return y;
}

Node* insertNode(Node* root, int key) {
    if(!root) return new Node(key);
    if(key < root->val) root->left = insertNode(root->left,key);
    else if(key > root->val) root->right = insertNode(root->right,key);
    else return root;
    root->height = 1 + max(getHeight(root->left), getHeight(root->right));
    int bal = getBalance(root);
    if(bal > 1 && key < root->left->val) return rotateRight(root);
    if(bal < -1 && key > root->right->val) return rotateLeft(root);
    if(bal > 1 && key > root->left->val) {
        root->left = rotateLeft(root->left);
        return rotateRight(root);
    }
    if(bal < -1 && key < root->right->val) {
        root->right = rotateRight(root->right);
        return rotateLeft(root);
    }
    return root;
}

void inorder(Node* root, int &count, int k, int &res) {
    if(!root) return;
    inorder(root->left,count,k,res);
    count++;
    if(count==k) res=root->val;
    inorder(root->right,count,k,res);
}

int kthSmallest(Node* root, int k) {
    int count=0, res=-1;
    inorder(root,count,k,res);
    return res;
}

int kthLargest(Node* root, int k) {
    int count=0, res=-1;
    // reverse inorder
    if(!root) return -1;
    if(root->right) kthLargest(root->right,k);
    count++;
    if(count==k) res=root->val;
    if(root->left) kthLargest(root->left,k);
    return res;
}

int main() {
    Node* root=nullptr;
    int values[]={50,30,70,20,40,60,80};
    for(int v:values) root=insertNode(root,v);

    int k;
    cout<<"Enter k: ";
    cin>>k;

    int small=kthSmallest(root,k);
    cout<<"kth smallest: "<<small<<"\n";

    int large=kthSmallest(root,8-k); // kth largest using total nodes
    cout<<"kth largest: "<<large<<"\n";

    cout<<"Left subtree height of root: "<<getHeight(root->left)<<"\n";
    cout<<"Right subtree height of root: "<<getHeight(root->right)<<"\n";

    return 0;
}
