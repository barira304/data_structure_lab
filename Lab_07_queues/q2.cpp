
#include <iostream>
using namespace std;

const int SIZE = 5;

class CircularQueue {
    int queue[SIZE];
    int front, rear, count;

public:
    CircularQueue() {
        front = 0;
        rear = -1;
        count = 0;
    }

    void enqueue(int packet) {
        if (count == SIZE) {
            cout << "Queue is full. Cannot add packet.\n";
            return;
        }

        rear = (rear + 1) % SIZE;
        queue[rear] = packet;
        count++;

        cout << "Packet " << packet << " added.\n";
    }

    void dequeue() {
        if (count == 0) {
            cout << "Queue is empty. No packet to transmit.\n";
            return;
        }

        cout << "Packet " << queue[front] << " transmitted.\n";
        front = (front + 1) % SIZE;
        count--;
    }

    void display() {
        if (count == 0) {
            cout << "No packets waiting for transmission.\n";
            return;
        }

        cout << "Waiting packets: ";
        for (int i = 0; i < count; i++) {
            cout << queue[(front + i) % SIZE] << " ";
        }
        cout << endl;
    }
};

int main() {
    CircularQueue packets;
    int choice, packet;

    do {
        cout << "\n--- Network Packet Management ---\n";
        cout << "1. Add packet\n";
        cout << "2. Transmit packet\n";
        cout << "3. Display packets\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter packet ID: ";
                cin >> packet;
                packets.enqueue(packet);
                break;

            case 2:
                packets.dequeue();
                break;

            case 3:
                packets.display();
                break;

            case 4:
                cout << "Program ended.\n";
                break;

            default:
                cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 4);

    return 0;
}

