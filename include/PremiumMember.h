#ifndef PREMIUMMEMBER_H
#define PREMIUMMEMBER_H

#include "Member.h"

class PremiumMember : public Member {
private:
    bool hasPersonalTrainer;
    double trainerFee;

public:
    PremiumMember(int id, string name, int age, string phone, string joinDate, bool hasTrainer);

    void display() const override;
    string toRecord() const override;
    
    double operator*(int months) const override;
};

#endif