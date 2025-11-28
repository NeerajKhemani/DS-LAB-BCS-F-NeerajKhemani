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

Node* rightRotate(Node* y) {
    Node* x = y->left;
    Node* t2 = x->right;

    x->right = y;
    y->left = t2;

    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;

    return x;
}

Node* leftRotate(Node* x) {
    Node* y = x->right;
    Node* t2 = y->left;

    y->left = x;
    x->right = t2;

    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;

    return y;
}

Node* insertNode(Node* root, int key) {
    if (!root) return new Node(key);

    if (key < root->val) root->left = insertNode(root->left, key);
    else if (key > root->val) root->right = insertNode(root->right, key);
    else return root;

    root->height = 1 + max(getHeight(root->left), getHeight(root->right));

    int bal = getBalance(root);

    if (bal > 1 && key < root->left->val) return rightRotate(root);
    if (bal < -1 && key > root->right->val) return leftRotate(root);
    if (bal > 1 && key > root->left->val) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }
    if (bal < -1 && key < root->right->val) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

void printInorder(Node* root) {
    if (!root) return;
    printInorder(root->left);
    cout << root->val << " ";
    printInorder(root->right);
}

int main() {
    Node* root = nullptr;

    int values[] = {50, 30, 70, 20, 40, 60, 80};
    for (int v : values) {
        root = insertNode(root, v);
    }

    root = insertNode(root, 55);

    root = leftRotate(root);

    cout << "Tree after left rotation on root (inorder): ";
    printInorder(root);
    cout << endl;

    return 0;
}
