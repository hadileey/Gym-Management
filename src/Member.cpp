#include "../include/Member.h"
#include <sstream>

Member::Member(int id, string name, int age, string phone, string joinDate, double fee, string type)
    : id(id), name(name), age(age), phone(phone), joinDate(joinDate), monthlyFee(fee), memberType(type) {}

void Member::display() const {
    cout << "ID: " << id << " | Type: " << memberType << " | Name: " << name 
         << " | Fee: $" << monthlyFee << "/mo";
}

string Member::toRecord() const {
    stringstream ss;
    ss << memberType << "," << id << "," << name << "," << age << "," 
       << phone << "," << joinDate << "," << monthlyFee;
    return ss.str();
}

double Member::operator*(int months) const {
    return monthlyFee * months;
}

double Member::operator+(double extraCharge) const {
    return monthlyFee + extraCharge;
}