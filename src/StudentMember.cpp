#include "../include/StudentMember.h"
#include <sstream>

StudentMember::StudentMember(int id, string name, int age, string phone, string joinDate, string college)
    : Member(id, name, age, phone, joinDate, 40.0, "Student"), collegeName(college) {}

void StudentMember::display() const {
    Member::display();
    cout << " | College: " << collegeName << endl;
}

string StudentMember::toRecord() const {
    stringstream ss;
    ss << Member::toRecord() << "," << collegeName;
    return ss.str();
}

double StudentMember::operator*(int months) const {
    cout << " [Applied 20% Student Discount] ";
    return (monthlyFee * months) * 0.80;
}