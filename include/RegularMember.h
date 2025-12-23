#ifndef REGULARMEMBER_H
#define REGULARMEMBER_H

#include "Member.h"

class RegularMember : public Member {
public:
    RegularMember(int id, string name, int age, string phone, string joinDate);

    void display() const override;
    string toRecord() const override;
    double operator*(int months) const override;
};

#endif