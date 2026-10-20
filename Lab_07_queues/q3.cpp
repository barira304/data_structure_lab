
#include <iostream>
using namespace std;

const int SIZE = 5;

struct Patient {
    int id;
    int priority;
};

class PriorityQueue {
    Patient patients[SIZE];
    int count;

public:
    PriorityQueue() {
        count = 0;
    }

    void insert(int id, int priority) {
        if (count == SIZE) {
            cout << "Queue is full. Cannot add patient.\n";
            return;
        }

        patients[count].id = id;
        patients[count].priority = priority;
        count++;

        cout << "Patient P" << id << " added.\n";
    }

    void treatPatient() {
        if (count == 0) {
            cout << "No patients waiting.\n";
            return;
        }

        int highest = 0;

        for (int i = 1; i < count; i++) {
            if (patients[i].priority < patients[highest].priority) {
                highest = i;
            }
        }

        cout << "Treating patient P" << patients[highest].id
             << " with priority "
             << patients[highest].priority << ".\n";

        for (int i = highest; i < count - 1; i++) {
            patients[i] = patients[i + 1];
        }

        count--;
    }

    void display() {
        if (count == 0) {
            cout << "No patients waiting.\n";
            return;
        }

        cout << "Waiting patients:\n";

        for (int i = 0; i < count; i++) {
            cout << "Patient P" << patients[i].id
                 << " | Priority: " << patients[i].priority << endl;
        }
    }
};

int main() {
    PriorityQueue hospital;
    int choice, id, priority;

    do {
        cout << "\n--- Hospital Emergency Department ---\n";
        cout << "1. Add patient\n";
        cout << "2. Treat highest-priority patient\n";
        cout << "3. Display waiting patients\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter patient ID (e.g. 102): ";
                cin >> id;
                cout << "Enter priority (1 is highest): ";
                cin >> priority;

                if (priority < 1) {
                    cout << "Priority must be 1 or higher.\n";
                } else {
                    hospital.insert(id, priority);
                }
                break;

            case 2:
                hospital.treatPatient();
                break;

            case 3:
                hospital.display();
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

