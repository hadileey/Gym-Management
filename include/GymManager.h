#ifndef GYMMANAGER_H
#define GYMMANAGER_H

#include <vector>
#include "Member.h"
#include "RegularMember.h"
#include "PremiumMember.h"
#include "StudentMember.h"

class GymManager {
private:
    vector<Member*> members;
    const string filename = "data/members.txt";

public:
    GymManager();
    ~GymManager();

    void addMember();
    void displayAllMembers() const;
    void removeMember(int id);
    void calculateFees() const;
    
    void saveToFile();
    void loadFromFile();
};

#endif