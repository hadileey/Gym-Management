#ifndef STUDENTMEMBER_H
#define STUDENTMEMBER_H

#include "Member.h"

class StudentMember : public Member {
private:
    string collegeName;

public:
    StudentMember(int id, string name, int age, string phone, string joinDate, string college);

    void display() const override;
    string toRecord() const override;

    double operator*(int months) const override;
};

#endif