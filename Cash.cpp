#include <iostream>
#include <iomanip>
#include "Cash.h"

using namespace std;

Cash::Cash()
{
    totalPaid = 0.0;
    changeDue = 0.0;
}

Cash::Cash(int id, int sender, int receiver, double amount, double totalPaid, double changeDue)
{
    this->id = id;
    this ->sender = sender;
    this->receiver = receiver;
    this->amount = amount;
    this->totalPaid = totalPaid;
    this->changeDue = changeDue;
}

Cash::~Cash(){}

Cash::Cash(const Cash &copy) : Transaction(copy), totalPaid(copy.totalPaid), changeDue(copy.changeDue){}

Cash& Cash::operator=(const Cash &copy) {
    Transaction::operator=(copy);
    totalPaid = copy.totalPaid;
    changeDue = copy.changeDue;
    return *this;
}

void Cash::display() const
{
    Transaction::display();

    cout << fixed << setprecision(2) << "\tPayment Method: Cash" << endl << "\tAmount Paid: $" << totalPaid << endl << "\tChange due: $" << changeDue << endl;
}

void Cash::save(ofstream &file) const
{
    file << fixed << setprecision(2) << id << "," << Transaction::getSenderName() << "," << Transaction::getReceiverName() << "," << amount << endl;
}
