#ifndef MEMBER_H
#define MEMBER_H

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class Member {
protected:
    int id;
    string name;
    int age;
    string phone;
    string joinDate;
    double monthlyFee;
    string memberType;

public:
    Member(int id, string name, int age, string phone, string joinDate, double fee, string type);
    virtual ~Member() {}

    int getId() const { return id; }
    string getName() const { return name; }
    string getType() const { return memberType; }

    virtual void display() const;
    virtual string toRecord() const; 

    virtual double operator*(int months) const;

    double operator+(double extraCharge) const;
};

#endif