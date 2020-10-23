#ifndef PROGRAM5_PEER_H
#define PROGRAM5_PEER_H

#include "LinkedList.h"
#include "Transaction.h"

class Peer
{
    int id;
    string name;
    LinkedList<Transaction*> ledger;

public:
    Peer();
    Peer(int id, string name);
    void addTransaction(Transaction* transaction);
    void display();
    void save(ofstream&);
};

#endif //PROGRAM5_PEER_H
