#include "../include/RegularMember.h"

RegularMember::RegularMember(int id, string name, int age, string phone, string joinDate)
    : Member(id, name, age, phone, joinDate, 50.0, "Regular") {} 

void RegularMember::display() const {
    Member::display();
    cout << endl;
}

string RegularMember::toRecord() const {
    return Member::toRecord();
}

double RegularMember::operator*(int months) const {
    return monthlyFee * months; 
}