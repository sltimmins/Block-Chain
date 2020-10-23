#ifndef PROGRAM5_NETWORK_H
#define PROGRAM5_NETWORK_H

#include "LinkedList.h"
#include "Peer.h"
#include "CreditCard.h"
#include "Cash.h"
#include "Check.h"

class Network
{
    LinkedList<Peer*> peers;
    int numberOfPeers;
    Peer *peer1;
    Peer *peer2;
    Peer *peer3;

public:
    Network();
    void processTransactions(std::ifstream& inputFile);
    void copyCreditTransactions(int, vector<string>, CreditCard*);
    void copyCashTransactions(int, vector<string>, Cash*);
    void copyCheckTransactions(int, vector<string>, Check*);
    void display();
    void save(ofstream &, ofstream &, ofstream&);
};

#endif //PROGRAM5_NETWORK_H
