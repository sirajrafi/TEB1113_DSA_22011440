#include <iostream>
using namespace std;

class Node {
public:
    string name;
    Node* left;
    Node* right;

    Node(string n) {
        name = n;
        left = nullptr;
        right = nullptr;
    }
};

class Tree {
public:
    Node* root;

    Tree() {
        root = nullptr;
    }

    void add_root(string name) {
        root = new Node(name);
    }

    void add_left(Node* parent, string name) {
        parent->left = new Node(name);
    }

    void add_right(Node* parent, string name) {
        parent->right = new Node(name);
    }
};

int main() {
    Tree tree;

    tree.add_root("A");
    tree.add_left(tree.root, "B");
    tree.add_right(tree.root, "C");
    tree.add_left(tree.root->left, "D");
    tree.add_right(tree.root->left, "E");
    tree.add_left(tree.root->right, "F");
    tree.add_right(tree.root->right, "G");

    cout << "Root: " << tree.root->name << endl;
    cout << "Left child of root: " << tree.root->left->name << endl;
    cout << "Right child of root: " << tree.root->right->name << endl;
    cout << "Left child of B: " << tree.root->left->left->name << endl;
    cout << "Right child of B: " << tree.root->left->right->name << endl;
    cout << "Left child of C: " << tree.root->right->left->name << endl;
    cout << "Right child of C: " << tree.root->right->right->name << endl;

    return 0;
}
