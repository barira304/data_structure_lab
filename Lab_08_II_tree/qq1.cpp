
#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    string name;
    Node* left;
    Node* right;

    Node(string n) {
        name = n;
        left = NULL;
        right = NULL;
    }
};

void display(Node* root) {
    if (root == NULL) {
        return;
    }

    cout << "Member: " << root->name << endl;

    cout << "Left Child: ";
    if (root->left == NULL) {
        cout << "NULL";
    }
    else {
        cout << root->left->name;
    }

    cout << endl;

    cout << "Right Child: ";
    if (root->right == NULL) {
        cout << "NULL";
    }
    else {
        cout << root->right->name;
    }

    cout << endl << endl;

    display(root->left);
    display(root->right);
}

int main() {

    Node* root = new Node("Dr. Ali (HOD)");

    root->left = new Node("Ahmed (Coordinator)");
    root->right = new Node("Sara (Coordinator)");

    root->left->left = new Node("Usman (Faculty)");
    root->left->right = new Node("Ayesha (Faculty)");

    root->right->left = new Node("Hamza (Faculty)");
    root->right->right = new Node("Zara (Faculty)");

    cout << "UNIVERSITY DEPARTMENT HIERARCHY" << endl;
    cout << "================================" << endl << endl;

    display(root);

    return 0;
}

