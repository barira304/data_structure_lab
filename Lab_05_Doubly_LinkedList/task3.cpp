#include <iostream>
using namespace std;

class Node
{
public:
    const char* player;
    Node* next;

    Node(const char* name)
    {
        player = name;
        next = NULL;
    }
};

class Game
{
private:
    Node* head;
    Node* tail;

public:
    Game()
    {
        head = NULL;
        tail = NULL;
    }

    void addPlayer(const char* player)
    {
        Node* newNode = new Node(player);

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

    void displayTurns()
    {
        cout << "Player Turns:" << endl;

        Node* temp = head;

        if (head != NULL)
        {
            do
            {
                cout << temp->player << endl;
                temp = temp->next;
            }
            while (temp != head);
        }

        cout << "After the last player, turn returns to: "
             << head->player << endl;
    }
};

int main()
{
    Game game;

    game.addPlayer("Player 1");
    game.addPlayer("Player 2");
    game.addPlayer("Player 3");
    game.addPlayer("Player 4");
    game.addPlayer("Player 5");

    game.displayTurns();

    return 0;
}
