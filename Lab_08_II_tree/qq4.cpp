
#include <iostream>
using namespace std;

class Node {
public:
    int id;
    int height;
    Node* left;
    Node* right;

    Node(int value) {
        id = value;
        height = 1;
        left = NULL;
        right = NULL;
    }
};

class AVL {
private:
    Node* root;

    int getHeight(Node* node) {
        if (node == NULL)
            return 0;

        return node->height;
    }

    int getBalance(Node* node) {
        if (node == NULL)
            return 0;

        return getHeight(node->left) -
               getHeight(node->right);
    }

    int max(int a, int b) {
        return (a > b) ? a : b;
    }

    Node* rightRotate(Node* y) {

        Node* x = y->left;
        Node* temp = x->right;

        x->right = y;
        y->left = temp;

        y->height = 1 + max(getHeight(y->left),
                            getHeight(y->right));

        x->height = 1 + max(getHeight(x->left),
                            getHeight(x->right));

        return x;
    }

    Node* leftRotate(Node* x) {

        Node* y = x->right;
        Node* temp = y->left;

        y->left = x;
        x->right = temp;

        x->height = 1 + max(getHeight(x->left),
                            getHeight(x->right));

        y->height = 1 + max(getHeight(y->left),
                            getHeight(y->right));

        return y;
    }

    Node* insert(Node* node, int id) {

        if (node == NULL)
            return new Node(id);

        if (id < node->id)
            node->left = insert(node->left, id);

        else if (id > node->id)
            node->right = insert(node->right, id);

        else
            return node;

        node->height = 1 + max(getHeight(node->left),
                               getHeight(node->right));

        int balance = getBalance(node);

        // LL Case
        if (balance > 1 && id < node->left->id)
            return rightRotate(node);

        // RR Case
        if (balance < -1 && id > node->right->id)
            return leftRotate(node);

        // LR Case
        if (balance > 1 && id > node->left->id) {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }

        // RL Case
        if (balance < -1 && id < node->right->id) {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }

        return node;
    }

    void inorder(Node* node) {
        if (node == NULL)
            return;

        inorder(node->left);
        cout << node->id << " ";
        inorder(node->right);
    }

    void displayTree(Node* node, int space) {
        if (node == NULL)
            return;

        space += 5;

        displayTree(node->right, space);

        cout << endl;

        for (int i = 5; i < space; i++)
            cout << " ";

        cout << node->id
             << " (H:" << node->height
             << ", BF:" << getBalance(node) << ")";

        displayTree(node->left, space);
    }

    void destroy(Node* node) {
        if (node == NULL)
            return;

        destroy(node->left);
        destroy(node->right);
        delete node;
    }

public:
    AVL() {
        root = NULL;
    }

    ~AVL() {
        destroy(root);
    }

    void insertID(int id) {
        root = insert(root, id);
    }

    void displayInorder() {
        inorder(root);
        cout << endl;
    }

    void showTree() {
        displayTree(root, 0);
        cout << endl;
    }

    void showHeight() {
        cout << "Tree Height: " << getHeight(root) << endl;
    }
};

int main() {

    AVL tree;

    int tokens[] = {15, 25, 35, 45, 55, 65, 75};

    cout << "HOSPITAL APPOINTMENT SYSTEM\n\n";

    cout << "Inserting appointment tokens:\n";

    for (int i = 0; i < 7; i++) {
        cout << "Inserting: " << tokens[i] << endl;
        tree.insertID(tokens[i]);
    }

    cout << "\nInorder Traversal: ";
    tree.displayInorder();

    cout << "\nFinal Balanced AVL Tree:\n";
    tree.showTree();

    cout << "\n";
    tree.showHeight();

    return 0;
}

