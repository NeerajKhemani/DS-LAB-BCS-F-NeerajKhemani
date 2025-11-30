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
    if (!root) return new Node(key);

    if (key < root->val) root->left = insertNode(root->left, key);
    else if (key > root->val) root->right = insertNode(root->right, key);
    else return root;

    root->height = 1 + max(getHeight(root->left), getHeight(root->right));

    int bal = getBalance(root);

    if (bal > 1 && key < root->left->val) return rotateRight(root);
    if (bal < -1 && key > root->right->val) return rotateLeft(root);
    if (bal > 1 && key > root->left->val) {
        root->left = rotateLeft(root->left);
        return rotateRight(root);
    }
    if (bal < -1 && key < root->right->val) {
        root->right = rotateRight(root->right);
        return rotateLeft(root);
    }

    return root;
}

void inorder(Node* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->val << "(BF=" << getBalance(root) << ") ";
    inorder(root->right);
}

int main() {
    Node* root = nullptr;

    int arr[] = {10, 5, 15, 3, 7};
    for (int v : arr)
        root = insertNode(root, v);

    root = insertNode(root, 12);

    cout << "Inorder traversal of balanced AVL tree (with balance factors):\n";
    inorder(root);
    cout << "\n";

    cout << "Height of tree: " << getHeight(root) << "\n";

    return 0;
}
