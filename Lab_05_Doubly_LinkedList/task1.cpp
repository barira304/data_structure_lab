#include <iostream>
using namespace std;

class Node
{
public:
    const char* website;
    Node* prev;
    Node* next;

    Node(const char* name)
    {
        website = name;
        prev = NULL;
        next = NULL;
    }
};

class BrowserHistory
{
private:
    Node* head;
    Node* tail;

public:
    BrowserHistory()
    {
        head = NULL;
        tail = NULL;
    }

    void addWebsite(const char* website)
    {
        Node* newNode = new Node(website);

        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    void displayForward()
    {
        cout << "Browser History (First to Last):" << endl;

        Node* temp = head;

        while (temp != NULL)
        {
            cout << temp->website << endl;
            temp = temp->next;
        }
    }

    void displayBackward()
    {
        cout << "Browser History (Last to First):" << endl;

        Node* temp = tail;

        while (temp != NULL)
        {
            cout << temp->website << endl;
            temp = temp->prev;
        }
    }
};

int main()
{
    BrowserHistory history;

    history.addWebsite("Google");
    history.addWebsite("YouTube");
    history.addWebsite("GitHub");
    history.addWebsite("Wikipedia");
    history.addWebsite("ChatGPT");

    history.displayForward();

    cout << endl;

    history.displayBackward();

    return 0;
}

   
