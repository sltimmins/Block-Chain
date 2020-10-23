#include "Peer.h"

Peer::Peer()
{
    id = rand();
    name = "null";
}

Peer::Peer(int id, string name)
{
    this->id = id;
    this->name = name;
}

void Peer::addTransaction(Transaction *transaction)
{
    ledger.insert(transaction);
}

void Peer::display()
{
    for(int i = 0; i < ledger.getSize(); i++)
    {
        ledger.at(i)->display();
    }
}

void Peer::save(ofstream &file)
{
    for(int i = 0; i < ledger.getSize(); i++)
    {
        ledger.at(i)->save(file);
    }
}
