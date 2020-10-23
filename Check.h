#ifndef CHECK_H
#define CHECK_H

#include "Transaction.h"

using namespace std;

class Check: public Transaction
{
public:
    Check();
    Check(int, int, int, double, string, string);
    ~Check();
    Check(const Check &copy);
    Check& operator=(const Check&);
    void display() const override;
    void save(ofstream &file) const override;

private:
    string routingNumber;
    string accountNumber;
};

#endif
