#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <fstream>

using namespace std;

class Transaction
{
public:
    Transaction();
    Transaction(int id, int sender, int receiver, double amount);
    virtual void display() const;
    virtual void save(ofstream &file) const;
    int getSender();
    string getSenderName() const;
    string getReceiverName() const;

protected:
    int id;
    int sender;
    int receiver;
    double amount;
};


#endif
