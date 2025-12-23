#include "../include/GymManager.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>

GymManager::GymManager() {
    loadFromFile();
}

GymManager::~GymManager() {
    saveToFile();
    for (Member* m : members) {
        delete m;
    }
    members.clear();
}

void GymManager::addMember() {
    int choice;
    cout << "\nSelect Member Type:\n1. Regular\n2. Premium\n3. Student\nChoice: ";
    cin >> choice;

    int id, age;
    string name, phone, joinDate;
    
    cout << "Enter ID: "; cin >> id;
    cin.ignore();
    cout << "Enter Name: "; getline(cin, name);
    cout << "Enter Age: "; cin >> age;
    cout << "Enter Phone: "; cin >> phone;
    cout << "Enter Join Date (DD/MM/YYYY): "; cin >> joinDate;

    if (choice == 1) {
        members.push_back(new RegularMember(id, name, age, phone, joinDate));
    } 
    else if (choice == 2) {
        char trainer;
        cout << "Need Personal Trainer? (y/n): "; cin >> trainer;
        bool hasTrainer = (trainer == 'y' || trainer == 'Y');
        members.push_back(new PremiumMember(id, name, age, phone, joinDate, hasTrainer));
    } 
    else if (choice == 3) {
        string college;
        cout << "Enter College Name: "; cin.ignore(); getline(cin, college);
        members.push_back(new StudentMember(id, name, age, phone, joinDate, college));
    }
    cout << "Member added successfully!\n";
    saveToFile();
}

void GymManager::displayAllMembers() const {
    if (members.empty()) {
        cout << "No members found.\n";
        return;
    }
    cout << "\n--- Member List ---\n";
    for (const auto& m : members) {
        m->display();
    }
    cout << "-------------------\n";
}

void GymManager::removeMember(int id) {
    auto it = std::remove_if(members.begin(), members.end(), [id](Member* m) {
        if (m->getId() == id) {
            delete m; 
            return true;
        }
        return false;
    });

    if (it != members.end()) {
        members.erase(it, members.end());
        cout << "Member removed.\n";
        saveToFile();
    } else {
        cout << "Member ID not found.\n";
    }
}

void GymManager::calculateFees() const {
    int id, months;
    cout << "Enter Member ID to calculate fee: "; cin >> id;
    
    bool found = false;
    for (const auto& m : members) {
        if (m->getId() == id) {
            cout << "Enter duration (months): "; cin >> months;
            
            double total = *m * months; 
            
            cout << "Total Fee for " << months << " months: $" << total << endl;
            
            double withExtra = *m + 15.0; 
            cout << "(Monthly fee if Locker added: $" << withExtra << ")\n";
            
            found = true;
            break;
        }
    }
    if (!found) cout << "Member not found.\n";
}

void GymManager::saveToFile() {
    ofstream outFile(filename);
    if (!outFile) {
        cout << "Error opening file for saving.\n";
        return;
    }
    for (const auto& m : members) {
        outFile << m->toRecord() << endl;
    }
    outFile.close();
}

void GymManager::loadFromFile() {
    ifstream inFile(filename);
    if (!inFile) return;

    string line;
    while (getline(inFile, line)) {
        stringstream ss(line);
        string type, segment;
        vector<string> data;

        while (getline(ss, segment, ',')) {
            data.push_back(segment);
        }

        if (data.size() < 7) continue;

        string typeStr = data[0];
        int id = stoi(data[1]);
        string name = data[2];
        int age = stoi(data[3]);
        string phone = data[4];
        string date = data[5];

        if (typeStr == "Regular") {
            members.push_back(new RegularMember(id, name, age, phone, date));
        } else if (typeStr == "Premium") {
            bool hasTrainer = stoi(data[7]);
            members.push_back(new PremiumMember(id, name, age, phone, date, hasTrainer));
        } else if (typeStr == "Student") {
            string college = data[7];
            members.push_back(new StudentMember(id, name, age, phone, date, college));
        }
    }
    inFile.close();
}