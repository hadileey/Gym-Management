#include "../include/PremiumMember.h"
#include <sstream>

PremiumMember::PremiumMember(int id, string name, int age, string phone, string joinDate, bool hasTrainer)
    : Member(id, name, age, phone, joinDate, 100.0, "Premium"), hasPersonalTrainer(hasTrainer) {
    trainerFee = hasTrainer ? 50.0 : 0.0;
}

void PremiumMember::display() const {
    Member::display();
    cout << " | Trainer: " << (hasPersonalTrainer ? "Yes" : "No") << endl;
}

string PremiumMember::toRecord() const {
    stringstream ss;
    ss << Member::toRecord() << "," << hasPersonalTrainer;
    return ss.str();
}

double PremiumMember::operator*(int months) const {
    double total = (monthlyFee + trainerFee) * months;
    if (months >= 6) {
        cout << " [Applied 10% Discount] ";
        return total * 0.90;
    }
    return total;
}