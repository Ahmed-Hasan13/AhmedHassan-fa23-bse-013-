#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

struct Patient {
    string name;
    int priority;

    bool operator<(const Patient& other) const {
        return priority < other.priority;
    }
};

void treatPatient(priority_queue<Patient>& pq) {
    if (pq.empty()) {
        cout << "No patients." << endl;
        return;
    }
    Patient current = pq.top();
    pq.pop();
    cout << "Treating: " << current.name << " (Priority: " << current.priority << ")" << endl;
}

void addPatient(priority_queue<Patient>& pq) {
    Patient newPatient;
    cout << "Enter patient name: ";
    cin >> newPatient.name;
    cout << "Enter priority (higher number = higher priority): ";
    cin >> newPatient.priority;
    pq.push(newPatient);
    cout << newPatient.name << " added." << endl;
}

int main() {
    priority_queue<Patient> patientQueue;
    int choice;

    do {
        cout << "\nHospital Queue" << endl;
        cout << "1. Add Patient" << endl;
        cout << "2. Treat Next Patient" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            addPatient(patientQueue);
        } else if (choice == 2) {
            treatPatient(patientQueue);
        } else if (choice == 0) {
            cout << "Exiting." << endl;
        } else {
            cout << "Invalid choice." << endl;
        }
    } while (choice != 0);

    return 0;
}
