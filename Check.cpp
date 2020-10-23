#include <iostream>
#include <iomanip>
#include "Check.h"

using namespace std;

Check::Check()
{
    routingNumber = "0000000000";
    accountNumber = "0000000000";
}

Check::Check(int id, int sender, int receiver, double amount, string routingNumber, string accountNumber)
{
    this->id = id;
    this->sender = sender;
    this->receiver = receiver;
    this->amount = amount;
    this->routingNumber = routingNumber;
    this->accountNumber = accountNumber;
}

Check::~Check(){}

Check::Check(const Check &copy) : Transaction(copy), routingNumber(copy.routingNumber), accountNumber(copy.accountNumber){}

Check& Check::operator=(const Check &copy){
    Transaction::operator=(copy);
    routingNumber = copy.routingNumber;
    accountNumber = copy.accountNumber;
}

void Check::display() const
{
    Transaction::display();

    cout << "\tPayment Method: Check" << endl << "\tRouting number: " << routingNumber << endl << "\tAccount number: " << accountNumber << endl;
}

void Check::save(ofstream &file) const
{
    file << fixed << setprecision(2) << id << "," << Transaction::getSenderName() << "," << Transaction::getReceiverName() << "," << amount << endl;
}
