
#include <iostream>
using namespace std;

const int SIZE = 5;

class Deque {
    int arr[SIZE];
    int front, rear, count;

public:
    Deque() {
        front = 0;
        rear = -1;
        count = 0;
    }

    void insertFront(int id) {
        if (count == SIZE) {
            cout << "Deque is full.\n";
            return;
        }

        if (count == 0) {
            front = 0;
            rear = 0;
        } else {
            front = (front - 1 + SIZE) % SIZE;
        }

        arr[front] = id;
        count++;

        cout << "Request " << id << " added at front.\n";
    }

    void insertRear(int id) {
        if (count == SIZE) {
            cout << "Deque is full.\n";
            return;
        }

        if (count == 0) {
            front = 0;
            rear = 0;
        } else {
            rear = (rear + 1) % SIZE;
        }

        arr[rear] = id;
        count++;

        cout << "Request " << id << " added at rear.\n";
    }

    void deleteFront() {
        if (count == 0) {
            cout << "Deque is empty.\n";
            return;
        }

        cout << "Request " << arr[front]
             << " removed from front.\n";

        front = (front + 1) % SIZE;
        count--;

        if (count == 0) {
            front = 0;
            rear = -1;
        }
    }

    void deleteRear() {
        if (count == 0) {
            cout << "Deque is empty.\n";
            return;
        }

        cout << "Request " << arr[rear]
             << " removed from rear.\n";

        rear = (rear - 1 + SIZE) % SIZE;
        count--;

        if (count == 0) {
            front = 0;
            rear = -1;
        }
    }

    void display() {
        if (count == 0) {
            cout << "No passenger requests waiting.\n";
            return;
        }

        cout << "Front -> ";

        for (int i = 0; i < count; i++) {
            cout << arr[(front + i) % SIZE] << " ";
        }

        cout << "<- Rear\n";
    }
};

int main() {
    Deque station;
    int choice, id;

    do {
        cout << "\n--- Train Station Management ---\n";
        cout << "1. Insert at front\n";
        cout << "2. Insert at rear\n";
        cout << "3. Remove from front\n";
        cout << "4. Remove from rear\n";
        cout << "5. Display requests\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter passenger request ID: ";
                cin >> id;
                station.insertFront(id);
                break;

            case 2:
                cout << "Enter passenger request ID: ";
                cin >> id;
                station.insertRear(id);
                break;

            case 3:
                station.deleteFront();
                break;

            case 4:
                station.deleteRear();
                break;

            case 5:
                station.display();
                break;

            case 6:
                cout << "Program ended.\n";
                break;

            default:
                cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 6);

    return 0;
}

