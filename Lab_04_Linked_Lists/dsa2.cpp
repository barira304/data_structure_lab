#include <iostream>
using namespace std;

struct Node
{
    string patientID;
    Node* next;
};

void addPatient(Node*& head, string patientID)
{
    Node* newNode = new Node;
    newNode->patientID = patientID;
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

void displayPatients(Node* head)
{
    cout << "Waiting Patients:" << endl;

    Node* temp = head;

    while (temp != NULL)
    {
        cout << temp->patientID;

        if (temp->next != NULL)
        {
            cout << " -> ";
        }

        temp = temp->next;
    }

    cout << endl;
}

void removeFirstPatient(Node*& head)
{
    if (head == NULL)
    {
        cout << "No patients waiting." << endl;
        return;
    }

    Node* temp = head;

    cout << "Patient " << head->patientID << " is being served." << endl;

    head = head->next;

    delete temp;
}

int main()
{
    Node* head = NULL;

    addPatient(head, "P101");
    addPatient(head, "P102");
    addPatient(head, "P103");
    addPatient(head, "P104");

    displayPatients(head);

    removeFirstPatient(head);

    cout << "Updated Queue:" << endl;
    displayPatients(head);

    return 0;
}
