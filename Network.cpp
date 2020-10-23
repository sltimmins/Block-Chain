#include <vector>
#include <sstream>
#include "Network.h"
#include "Peer.h"
#include "Cash.h"
#include "CreditCard.h"
#include "Check.h"
#include "Transaction.h"


Network::Network()
{
    numberOfPeers = 0;
    peer1 = new Peer(1, "Lyle School of Engineering");
    peer2 = new Peer(2, "Cox School of Business");
    peer3 = new Peer(3, "Dedman School of Law");
}

void Network::processTransactions(std::ifstream &inputFile)
{
    string line, transactionType;
    int index = 0;
    vector<string> fullTransaction, transactionInfo;

    while(getline(inputFile, line, '\n')) //parses each transaction to be on its own
    {
        fullTransaction.push_back(line);
    }

    for(int i = 0; i < fullTransaction.size(); i++) //parses each transaction into individual pieces
    {
        stringstream parseTransactions(fullTransaction.at(i));
        while(getline(parseTransactions, line, ' '))
        {
            transactionInfo.push_back(line);
        }
    }

    for(int i = 0; i < fullTransaction.size(); i++)
    {
        transactionType = transactionInfo.at(index); //determines the type of transaction and creates that transaction pointer then adds it to the specific peer
        if(transactionType == "Credit")
        {
            CreditCard *toAdd = new CreditCard(rand(), stoi(transactionInfo.at(index + 1)), stoi(transactionInfo.at(index + 2)),
                                               stod(transactionInfo.at(index + 3)), transactionInfo.at(index + 4),
                                               transactionInfo.at(index + 5), transactionInfo.at(index + 6));
            copyCreditTransactions(index, transactionInfo, toAdd);
            index += 7;
        }
        else if(transactionType == "Cash")
        {
            Cash *toAdd = new Cash(rand(), stoi(transactionInfo.at(index + 1)), stoi(transactionInfo.at(index + 2)),
                            stod(transactionInfo.at(index + 3)), stod(transactionInfo.at(index + 4)),
                            stod(transactionInfo.at(index + 5)));
            copyCashTransactions(index, transactionInfo, toAdd);
            index += 6;
        }
        else if(transactionType == "Check")
        {
            Check *toAdd = new Check(rand(), stoi(transactionInfo.at(index + 1)), stoi(transactionInfo.at(index + 2)),
                                    stod(transactionInfo.at(index + 3)), transactionInfo.at(index + 4),
                                    transactionInfo.at(index + 5));
            copyCheckTransactions(index, transactionInfo, toAdd);
            index += 6;
        }
    }
    peers.insert(peer1); //insert each peer into the peers linked list
    peers.insert(peer2);
    peers.insert(peer3);
}

void Network::copyCreditTransactions(int index, vector<string> transactionInfo, CreditCard *toAdd)
{
    CreditCard *copyToAdd;
    copyToAdd = new CreditCard(*toAdd);
//finds which peer to add the transaction to
    if(stoi(transactionInfo.at(index + 1)) == 1)
    {
        peer1->addTransaction(toAdd);
    }
    else if(stoi(transactionInfo.at(index + 1)) == 2)
    {
        peer2->addTransaction(toAdd);
    }
    else if(stoi(transactionInfo.at(index + 1)) == 3)
    {
        peer3->addTransaction(toAdd);
    }
    //finds which peer to add the copy of the transaction to
    if(stoi(transactionInfo.at(index + 2)) == 1)
    {
        peer1->addTransaction(copyToAdd);
    }
    else if(stoi(transactionInfo.at(index + 2)) == 2)
    {
        peer2->addTransaction(copyToAdd);
    }
    else if(stoi(transactionInfo.at(index + 2)) == 3)
    {
        peer3->addTransaction(copyToAdd);
    }
}

void Network::copyCashTransactions(int index, vector<string> transactionInfo, Cash *toAdd)
{
    Cash *copyToAdd;
    copyToAdd = new Cash(*toAdd);
//finds which peer to add the transaction to
    if(stoi(transactionInfo.at(index + 1)) == 1)
    {
        peer1->addTransaction(toAdd);
    }
    else if(stoi(transactionInfo.at(index + 1)) == 2)
    {
        peer2->addTransaction(toAdd);
    }
    else if(stoi(transactionInfo.at(index + 1)) == 3)
    {
        peer3->addTransaction(toAdd);
    }
    //finds which peer to add the copy of the transaction to
    if(stoi(transactionInfo.at(index + 2)) == 1)
    {
        peer1->addTransaction(copyToAdd);
    }
    else if(stoi(transactionInfo.at(index + 2)) == 2)
    {
        peer2->addTransaction(copyToAdd);
    }
    else if(stoi(transactionInfo.at(index + 2)) == 3)
    {
        peer3->addTransaction(copyToAdd);
    }
}

void Network::copyCheckTransactions(int index, vector<string> transactionInfo, Check *toAdd)
{
    Check *copyToAdd;
    copyToAdd = new Check(*toAdd);
    //finds which peer to add the transaction to
    if(stoi(transactionInfo.at(index + 1)) == 1)
    {
        peer1->addTransaction(toAdd);
    }
    else if(stoi(transactionInfo.at(index + 1)) == 2)
    {
        peer2->addTransaction(toAdd);
    }
    else if(stoi(transactionInfo.at(index + 1)) == 3)
    {
        peer3->addTransaction(toAdd);
    }
    //finds which peer to add the copy of the transaction to
    if(stoi(transactionInfo.at(index + 2)) == 1)
    {
        peer1->addTransaction(copyToAdd);
    }
    else if(stoi(transactionInfo.at(index + 2)) == 2)
    {
        peer2->addTransaction(copyToAdd);
    }
    else if(stoi(transactionInfo.at(index + 2)) == 3)
    {
        peer3->addTransaction(copyToAdd);
    }
}

void Network::display()
{
    for(int i = 0; i < peers.getSize(); i++)
    {
        cout << "\n-- Peer " << i + 1 << " Ledger --" << endl;
        peers.at(i)->display();
    }
}

void Network::save(ofstream &peer1File, ofstream &peer2File, ofstream &peer3File)
{
    peer1->save(peer1File);
    peer2->save(peer2File);
    peer3->save(peer3File);
}