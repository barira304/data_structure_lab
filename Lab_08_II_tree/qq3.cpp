
#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    string folder;
    Node* left;
    Node* right;

    Node(string name) {
        folder = name;
        left = NULL;
        right = NULL;
    }
};

void inorder(Node* root) {

    if (root == NULL) {
        return;
    }

    inorder(root->left);

    cout << root->folder << " ";

    inorder(root->right);
}

void preorder(Node* root) {

    if (root == NULL) {
        return;
    }

    cout << root->folder << " ";

    preorder(root->left);

    preorder(root->right);
}

void postorder(Node* root) {

    if (root == NULL) {
        return;
    }

    postorder(root->left);

    postorder(root->right);

    cout << root->folder << " ";
}

int main() {

    Node* root = new Node("Root");

    root->left = new Node("Documents");
    root->right = new Node("Media");

    root->left->left = new Node("Work");
    root->left->right = new Node("Study");

    root->right->left = new Node("Images");
    root->right->right = new Node("Videos");

    cout << "COMPUTER FILE EXPLORER\n\n";

    cout << "Inorder Traversal: ";
    inorder(root);

    cout << "\nPreorder Traversal: ";
    preorder(root);

    cout << "\nPostorder Traversal: ";
    postorder(root);

    cout << endl;

    return 0;
}

