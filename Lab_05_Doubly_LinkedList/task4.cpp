#include <iostream>
using namespace std;

class Node
{
public:
    const char* song;
    Node* next;

    Node(const char* name)
    {
        song = name;
        next = NULL;
    }
};

class Playlist
{
private:
    Node* head;
    Node* tail;

public:
    Playlist()
    {
        head = NULL;
        tail = NULL;
    }

    void addSong(const char* song)
    {
        Node* newNode = new Node(song);

        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
            tail->next = head;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
            tail->next = head;
        }
    }

    void displayPlaylist()
    {
        cout << "Playlist:" << endl;

        Node* temp = head;

        if (head != NULL)
        {
            do
            {
                cout << temp->song << endl;
                temp = temp->next;
            }
            while (temp != head);
        }
    }

    void playTwoRounds()
    {
        cout << endl;
        cout << "Playing Playlist for 2 Rounds:" << endl;

        Node* temp = head;

        for (int round = 1; round <= 2; round++)
        {
            cout << "Round " << round << ":" << endl;

            for (int i = 1; i <= 5; i++)
            {
                cout << temp->song << endl;
                temp = temp->next;
            }
        }
    }
};

int main()
{
    Playlist playlist;

    playlist.addSong("Song 1");
    playlist.addSong("Song 2");
    playlist.addSong("Song 3");
    playlist.addSong("Song 4");
    playlist.addSong("Song 5");

    playlist.displayPlaylist();

    playlist.playTwoRounds();

    return 0;
}
