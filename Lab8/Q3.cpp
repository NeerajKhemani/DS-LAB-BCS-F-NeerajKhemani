#include <iostream>
#include <string>
using namespace std;

struct Student {
    string name;
    int roll;
    int score;
};

struct Node {
    Student data;
    Node* left;
    Node* right;
};

Node* createNode(Student s) {
    Node* n = new Node();
    n->data = s;
    n->left = nullptr;
    n->right = nullptr;
    return n;
}

Node* insertNode(Node* root, Student s) {
    if (!root) return createNode(s);
    if (s.name < root->data.name)
        root->left = insertNode(root->left, s);
    else
        root->right = insertNode(root->right, s);
    return root;
}

Node* findMin(Node* root) {
    while (root->left) root = root->left;
    return root;
}

Node* deleteNode(Node* root, string key) {
    if (!root) return root;

    if (key < root->data.name)
        root->left = deleteNode(root->left, key);
    else if (key > root->data.name)
        root->right = deleteNode(root->right, key);
    else {
        if (!root->left && !root->right) {
            delete root;
            return nullptr;
        }
        else if (!root->left) {
            Node* t = root->right;
            delete root;
            return t;
        }
        else if (!root->right) {
            Node* t = root->left;
            delete root;
            return t;
        }
        else {
            Node* t = findMin(root->right);
            root->data = t->data;
            root->right = deleteNode(root->right, t->data.name);
        }
    }
    return root;
}

Node* searchNode(Node* root, string key) {
    if (!root) return nullptr;
    if (root->data.name == key) return root;
    if (key < root->data.name)
        return searchNode(root->left, key);
    return searchNode(root->right, key);
}

void deleteLowScores(Node*& root) {
    if (!root) return;

    deleteLowScores(root->left);
    deleteLowScores(root->right);

    if (root->data.score < 10) {
        root = deleteNode(root, root->data.name);
    }
}

void getMaxScore(Node* root, Student &best) {
    if (!root) return;
    if (root->data.score > best.score)
        best = root->data;
    getMaxScore(root->left, best);
    getMaxScore(root->right, best);
}

void inorder(Node* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->data.name << " (" << root->data.score << ") ";
    inorder(root->right);
}

int main() {
    Student arr[10] = {
        {"Ali",1,12},{"Bilal",2,9},{"Hamza",3,17},{"Sana",4,5},{"Kiran",5,20},
        {"Usman",6,14},{"Ayesha",7,3},{"Zara",8,19},{"Taimoor",9,8},{"Farah",10,11}
    };

    Node* root = nullptr;

    // Just store first 7 students (no randomness)
    for (int i = 0; i < 7; i++)
        root = insertNode(root, arr[i]);

    cout << "Initial Tree: ";
    inorder(root);
    cout << "\n";

    cout << "Enter name to search: ";
    string key;
    cin >> key;

    Node* found = searchNode(root, key);
    if (found)
        cout << "Found: " << found->data.name << " Score=" << found->data.score << "\n";
    else
        cout << "Not found\n";

    deleteLowScores(root);

    cout << "After deleting scores < 10: ";
    inorder(root);
    cout << "\n";

    Student best = {"",0,-1};
    getMaxScore(root, best);

    cout << "Top student: " << best.name << " Score=" << best.score << "\n";

    return 0;
}
