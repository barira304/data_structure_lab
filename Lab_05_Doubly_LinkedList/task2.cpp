#include <iostream>
using namespace std;

class Node
{
public:
    const char* image;
    Node* prev;
    Node* next;

    Node(const char* name)
    {
        image = name;
        prev = NULL;
        next = NULL;
    }
};

class ImageGallery
{
private:
    Node* head;
    Node* tail;

public:
    ImageGallery()
    {
        head = NULL;
        tail = NULL;
    }

    void addImage(const char* image)
    {
        Node* newNode = new Node(image);

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
        cout << "Images (First to Last):" << endl;

        Node* temp = head;

        while (temp != NULL)
        {
            cout << temp->image << endl;
            temp = temp->next;
        }
    }

    void displayBackward()
    {
        cout << "Images (Last to First):" << endl;

        Node* temp = tail;

        while (temp != NULL)
        {
            cout << temp->image << endl;
            temp = temp->prev;
        }
    }
};

int main()
{
    ImageGallery gallery;

    gallery.addImage("Image1.jpg");
    gallery.addImage("Image2.jpg");
    gallery.addImage("Image3.jpg");
    gallery.addImage("Image4.jpg");
    gallery.addImage("Image5.jpg");

    gallery.displayForward();

    cout << endl;

    gallery.displayBackward();

    return 0;
}
