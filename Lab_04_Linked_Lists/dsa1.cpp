#include <iostream>
using namespace std;

struct Node
{
    int rollNumber;
    Node* next;
};

void addStudent(Node*& head, int rollNumber)
{
    Node* newNode = new Node;
    newNode->rollNumber = rollNumber;
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

void displayStudents(Node* head)
{
    cout << "Registered Students:" << endl;

    Node* temp = head;

    while (temp != NULL)
    {
        cout << temp->rollNumber;

        if (temp->next != NULL)
        {
            cout << " -> ";
        }

        temp = temp->next;
    }

    cout << endl;
}

void searchStudent(Node* head, int rollNumber)
{
    Node* temp = head;

    while (temp != NULL)
    {
        if (temp->rollNumber == rollNumber)
        {
            cout << "Student Found" << endl;
            return;
        }

        temp = temp->next;
    }

    cout << "Student Not Found" << endl;
}

int main()
{
    Node* head = NULL;

    addStudent(head, 101);
    addStudent(head, 105);
    addStudent(head, 108);
    addStudent(head, 112);

    displayStudents(head);

    int rollNumber;

    cout << "Enter Roll Number to Search: ";
    cin >> rollNumber;

    searchStudent(head, rollNumber);

    return 0;
}
