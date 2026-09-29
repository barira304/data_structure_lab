#include <iostream>
using namespace std;

struct Node
{
    string productID;
    Node* next;
};

void addProduct(Node*& head, string productID)
{
    Node* newNode = new Node;
    newNode->productID = productID;
    newNode->next = NULL;

    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        Node* temp = head;

        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newNode;
    }
}

void displayCart(Node* head)
{
    cout << "Shopping Cart:" << endl;

    Node* temp = head;

    while (temp != NULL)
    {
        cout << temp->productID;

        if (temp->next != NULL)
        {
            cout << " -> ";
        }

        temp = temp->next;
    }

    cout << endl;
}

void removeProduct(Node*& head, string productID)
{
    if (head == NULL)
    {
        cout << "Cart is empty." << endl;
        return;
    }

    if (head->productID == productID)
    {
        Node* temp = head;
        head = head->next;
        delete temp;
        return;
    }

    Node* temp = head;

    while (temp->next != NULL)
    {
        if (temp->next->productID == productID)
        {
            Node* deleteNode = temp->next;
            temp->next = temp->next->next;
            delete deleteNode;
            return;
        }

        temp = temp->next;
    }

    cout << "Product Not Found" << endl;
}

int main()
{
    Node* head = NULL;

    addProduct(head, "P101");
    addProduct(head, "P205");
    addProduct(head, "P310");
    addProduct(head, "P415");

    displayCart(head);

    string productID;

    cout << "Remove Product: ";
    cin >> productID;

    removeProduct(head, productID);

    cout << "Updated Cart:" << endl;
    displayCart(head);

    return 0;
}
