#include <iostream>
#include <iomanip>
#include "Transaction.h"

using namespace std;

Transaction::Transaction(){}

Transaction::Transaction(int id, int sender, int receiver, double amount)
{
    this->id = id;
    this->sender = sender;
    this->receiver = receiver;
    this->amount = amount;
}

void Transaction::display() const
{
    string senderString;
    string receiverString;

    switch(sender)
    {
        case 1:
        {
            senderString = "Lyle School of Engineering";
            break;
        }

        case 2:
        {
            senderString = "Cox School of Business";
            break;
        }

        case 3:
        {
            senderString = "Dedman School of Law";
            break;
        }
        default:
        {
            senderString = "null";
            break;
        }
    }

    switch(receiver)
    {
        case 1:
        {
            receiverString = "Lyle School of Engineering";
            break;
        }

        case 2:
        {
            receiverString = "Cox School of Business";
            break;
        }

        case 3:
        {
            receiverString = "Dedman School of Law";
            break;
        }

        default:
        {
            receiverString = "null";
            break;
        }
    }

    cout << fixed << setprecision(2) << "Transaction #" << id << " " << senderString << " sent $" << amount << " to " << receiverString << endl;
}

void Transaction::save(ofstream &file) const
{
    file << fixed << setprecision(2)  << id << "," << sender << "," << receiver << "," << amount << endl;
}

int Transaction::getSender() { return sender;}

string Transaction::getSenderName() const {
    switch(sender)
    {
        case 1:
        {
            return "Lyle School of Engineering";
        }

        case 2:
        {
            return "Cox School of Business";
        }

        case 3:
        {
            return "Dedman School of Law";
        }
        default:
        {
            return "null";
        }
    }
}

string Transaction::getReceiverName() const {
    switch(receiver)
    {
        case 1:
        {
            return "Lyle School of Engineering";
        }

        case 2:
        {
            return "Cox School of Business";
        }

        case 3:
        {
            return "Dedman School of Law";
        }
        default:
        {
            return "null";
        }
    }
}


