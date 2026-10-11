#include <iostream>
#include <string>
using namespace std;

struct Node {
    string coach;
    Node* next;

    Node(string name) {
        coach = name;
        next = nullptr;
    }
};

Node* head = nullptr;

void addBeginning(string name) {
    Node* newNode = new Node(name);
    newNode->next = head;
    head = newNode;
    cout << "Coach added at the beginning.\n";
}

void addEnd(string name) {
    Node* newNode = new Node(name);

    if (head == nullptr) {
        head = newNode;
        return;
    }

    Node* temp = head;
    while (temp->next != nullptr)
        temp = temp->next;

    temp->next = newNode;
    cout << "Coach added at the end.\n";
}

void removeCoach(string name) {
    if (head == nullptr) {
        cout << "Train is empty.\n";
        return;
    }

    if (head->coach == name) {
        Node* temp = head;
        head = head->next;
        delete temp;
        cout << "Coach removed.\n";
        return;
    }

    Node* temp = head;
    while (temp->next != nullptr &&
           temp->next->coach != name) {
        temp = temp->next;
    }

    if (temp->next == nullptr) {
        cout << "Coach not found.\n";
    } else {
        Node* del = temp->next;
        temp->next = del->next;
        delete del;
        cout << "Coach removed.\n";
    }
}

void display() {
    if (head == nullptr) {
        cout << "Train is empty.\n";
        return;
    }

    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->coach << " -> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

int main() {
    int choice;
    string name;

    do {
        cout << "\n--- Train Coach Management ---\n";
        cout << "1. Add coach at beginning\n";
        cout << "2. Add coach at end\n";
        cout << "3. Remove a coach\n";
        cout << "4. Display all coaches\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter coach name: ";
            cin >> name;
            addBeginning(name);
            break;

        case 2:
            cout << "Enter coach name: ";
            cin >> name;
            addEnd(name);
            break;

        case 3:
            cout << "Enter coach name to remove: ";
            cin >> name;
            removeCoach(name);
            break;

        case 4:
            display();
            break;

        case 5:
            cout << "Exiting program.\n";
            break;

        default:
            cout << "Invalid choice.\n";
        }
    } while (choice != 5);

    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}
