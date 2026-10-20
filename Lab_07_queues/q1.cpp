
#include <iostream>
using namespace std;

const int SIZE = 5;

class LinearQueue {
    int queue[SIZE];
    int front, rear;

public:
    LinearQueue() {
        front = -1;
        rear = -1;
    }

    void enqueue(int token) {
        if (rear == SIZE - 1) {
            cout << "Queue Overflow! No space available.\n";
            return;
        }

        if (front == -1) {
            front = 0;
        }

        rear++;
        queue[rear] = token;
        cout << "Customer " << token << " added to the queue.\n";
    }

    void dequeue() {
        if (front == -1 || front > rear) {
            cout << "Queue Underflow! No customers waiting.\n";
            return;
        }

        cout << "Customer " << queue[front] << " has been served.\n";
        front++;

        if (front > rear) {
            front = -1;
            rear = -1;
        }
    }

    void display() {
        if (front == -1) {
            cout << "No customers waiting.\n";
            return;
        }

        cout << "Waiting customers: ";
        for (int i = front; i <= rear; i++) {
            cout << queue[i] << " ";
        }
        cout << endl;
    }

    void countCustomers() {
        if (front == -1) {
            cout << "Number of waiting customers: 0\n";
        } else {
            cout << "Number of waiting customers: "
                 << rear - front + 1 << endl;
        }
    }
};

int main() {
    LinearQueue bank;
    int choice, token;

    do {
        cout << "\n--- Bank Customer Service ---\n";
        cout << "1. Add customer\n";
        cout << "2. Serve customer\n";
        cout << "3. Display waiting customers\n";
        cout << "4. Count waiting customers\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter customer token number: ";
                cin >> token;
                bank.enqueue(token);
                break;

            case 2:
                bank.dequeue();
                break;

            case 3:
                bank.display();
                break;

            case 4:
                bank.countCustomers();
                break;

            case 5:
                cout << "Program ended.\n";
                break;

            default:
                cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 5);

    return 0;
}

