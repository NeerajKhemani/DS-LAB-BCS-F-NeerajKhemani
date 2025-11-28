#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

struct Combatant {
    string name;
    int hp;
    int atk;
};

struct Node {
    Combatant data;
    Node* left;
    Node* right;
};

Node* createNode(Combatant c) {
    Node* n = new Node();
    n->data = c;
    n->left = nullptr;
    n->right = nullptr;
    return n;
}

Node* insertNode(Node* root, Combatant c) {
    if (!root) return createNode(c);
    if (c.name < root->data.name)
        root->left = insertNode(root->left, c);
    else
        root->right = insertNode(root->right, c);
    return root;
}

Node* findMin(Node* root) {
    while (root && root->left)
        root = root->left;
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
            Node* temp = root->right;
            delete root;
            return temp;
        }
        else if (!root->right) {
            Node* temp = root->left;
            delete root;
            return temp;
        }
        else {
            Node* temp = findMin(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data.name);
        }
    }
    return root;
}

Node* getFront(Node* root) {
    return findMin(root);
}

bool isEmpty(Node* root) {
    return root == nullptr;
}

void showTeam(Node* root) {
    if (!root) return;
    showTeam(root->left);
    cout << root->data.name << "(" << root->data.hp << ") ";
    showTeam(root->right);
}

int main() {
    srand(time(0));

    Node* heroes = nullptr;
    Node* enemies = nullptr;

    Combatant h[5] = {
        {"Aiden",40,9},
        {"Blaze",45,8},
        {"Cyra",38,10},
        {"Drax",50,7},
        {"Elara",42,9}
    };

    Combatant e[5] = {
        {"Skorn",35,7},
        {"Ravok",40,8},
        {"Morg",42,6},
        {"Venmar",38,9},
        {"Therok",45,7}
    };

    for (int i = 0; i < 5; i++) heroes = insertNode(heroes, h[i]);
    for (int i = 0; i < 5; i++) enemies = insertNode(enemies, e[i]);

    int round = 1;

    while (!isEmpty(heroes) && !isEmpty(enemies)) {

        cout << "\nRound " << round << "\n";

        cout << "Heroes: ";
        showTeam(heroes);
        cout << "\nEnemies: ";
        showTeam(enemies);
        cout << "\n";

        Node* hero = getFront(heroes);
        Node* enemy = getFront(enemies);

        int dmg = hero->data.atk + rand() % 5;
        enemy->data.hp -= dmg;
        cout << hero->data.name << " hits " << enemy->data.name << " for " << dmg << "\n";

        if (enemy->data.hp <= 0) {
            cout << enemy->data.name << " defeated\n";
            enemies = deleteNode(enemies, enemy->data.name);
        }

        if (isEmpty(enemies)) break;

        dmg = enemy->data.atk + rand() % 5;
        hero->data.hp -= dmg;
        cout << enemy->data.name << " hits " << hero->data.name << " for " << dmg << "\n";

        if (hero->data.hp <= 0) {
            cout << hero->data.name << " defeated\n";
            heroes = deleteNode(heroes, hero->data.name);
        }

        round++;
    }

    if (isEmpty(heroes))
        cout << "\nEnemies win\n";
    else
        cout << "\nHeroes win\n";

    return 0;
}
