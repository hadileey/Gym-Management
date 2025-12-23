#include <iostream>
#include "../include/GymManager.h"

using namespace std;

void showMenu() {
    cout << "\n=== Gym Membership Management System ===\n";
    cout << "1. Add Member\n";
    cout << "2. Display All Members\n";
    cout << "3. Calculate Membership Fee\n";
    cout << "4. Remove Member\n";
    cout << "5. Exit\n";
    cout << "Enter choice: ";
}

int main() {
    GymManager manager;
    int choice;

    do {
        showMenu();
        cin >> choice;

        switch (choice) {
            case 1: manager.addMember(); break;
            case 2: manager.displayAllMembers(); break;
            case 3: manager.calculateFees(); break;
            case 4: 
                int id;
                cout << "Enter ID to remove: "; cin >> id;
                manager.removeMember(id); 
                break;
            case 5: cout << "Exiting system...\n"; break;
            default: cout << "Invalid choice!\n";
        }
    } while (choice != 5);

    return 0;
}