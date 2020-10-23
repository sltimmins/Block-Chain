#include <iostream>
#include <iomanip>
#include "CreditCard.h"

using namespace std;

CreditCard::CreditCard()
{
    cardNumber = "0000 0000 0000 0000";
    expirationDate = "01/01/2020";
    cvv = "000";
}

CreditCard::CreditCard(int id, int sender, int receiver, double amount, string cardNumber, string expirationDate, string cvv)
{
    this->id = id;
    this->sender = sender;
    this->receiver = receiver;
    this->amount = amount;
    this->cardNumber = cardNumber;
    this->expirationDate = expirationDate;
    this->cvv = cvv;
}

CreditCard::~CreditCard(){}

CreditCard::CreditCard(const CreditCard &copy) : Transaction(copy), cardNumber(copy.cardNumber), expirationDate(copy.expirationDate), cvv(copy.cvv){}

CreditCard& CreditCard::operator=(const CreditCard &copy){
    Transaction::operator=(copy);
    cardNumber = copy.cardNumber;
    expirationDate = copy.expirationDate;
    cvv = copy.cvv;
    return *this;
}

void CreditCard::display() const
{
    Transaction::display();

    cout << "\tPayment Method: Credit Card" << endl << "\tCard Number: " << cardNumber << endl << "\tExp. Date: " << expirationDate << endl
        << "\tCVV: " << cvv << endl;
}

void CreditCard::save(ofstream &file) const
{
    file << fixed << setprecision(2) << id << "," << Transaction::getSenderName() << "," << Transaction::getReceiverName() << "," << amount << endl;
}