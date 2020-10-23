#ifndef CASH_H
#define CASH_H

#include "Transaction.h"

using namespace std;

class Cash: public Transaction
{
public:
    Cash();
    Cash(int, int, int, double, double, double);
    ~Cash();
    Cash(const Cash& copy);
    Cash& operator=(const Cash& copy);
    void display() const override;
    void save(ofstream &file) const override;

private:
    double totalPaid;
    double changeDue;
};
#endif
