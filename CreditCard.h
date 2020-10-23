#ifndef CREDITCARD_H
#define CREDITCARD_H

#include "Transaction.h"

using namespace std;

class CreditCard: public Transaction
{
public:
    CreditCard();
    ~CreditCard();
    CreditCard(int, int, int, double, string, string, string);
    CreditCard(const CreditCard &copy);
    CreditCard& operator=(const CreditCard &copy);

    void display() const override;
    void save(ofstream &file) const override;

private:
    string cardNumber;
    string expirationDate;
    string cvv;
};


#endif
