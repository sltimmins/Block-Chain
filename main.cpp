#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include "Transaction.h"
#include "CreditCard.h"
#include "Check.h"
#include "Cash.h"
#include "LinkedList.h"
#include "Network.h"

using namespace std;

int main(int argc, char* argv[]) {
    if (argc != 2) {
        cout << "Invalid number of arguments. Correct usage: ./a.out <filename>" << endl;
        return -1;
    }

    // fileName contains the name of the file that needs to be read
    ifstream file;
    file.open(argv[1]);

    ofstream peer1("../peer1.csv"), peer2("../peer2.csv"), peer3("../peer3.csv"); //open peer files for writiing

    Network network = Network(); //create the network
    network.processTransactions(file); //process the the transactions file

    network.display(); //display transactions to terminal

    peer1 << "Id,Sender,Receiver,Amount\n"; //Add title line to the peer's csv files
    peer2 << "Id,Sender,Receiver,Amount\n";
    peer3 << "Id,Sender,Receiver,Amount\n";
    network.save(peer1, peer2, peer3); //Write to the peer's csv files

    return 0;
}