#include <iostream>
#include <cassert>
#include <vector>
#include "LinkedList.h"
#include "Transaction.h"
#include "CreditCard.h"
#include "Cash.h"
#include "Check.h"

using namespace std;

struct SimpleData {
    int data;
};

int main() {
    srand(time(nullptr));

    cout << "-- Test Bench --\n" << endl;

    //ensure that list can be created with ints and that insert works
    LinkedList<int> test1;
    test1.insert(1);
    assert(test1.at(0) == 1);

    //ensure that remove and at methods work with ints
    LinkedList<int> test2;
    test2.insert(1);
    test2.insert(2);
    test2.insert(3);
    test2.remove(2);
    assert(test2.at(1) == 3);

    //ensure copy constructor works for ints
    LinkedList<int> test3;
    test3.insert(1);
    LinkedList<int> test4 = LinkedList<int>(test3);
    assert(test3.at(0) == test4.at(0));

    //ensure copy assignemt works for ints
    LinkedList<int> test9;
    test9.insert(1);
    LinkedList<int> test9Copy;
    test9Copy = test9;
    assert(test9.at(0) == test9Copy.at(0));

    //ensure linked list works with object pointers
    LinkedList<Transaction*> test5;
    Transaction *pointer = new Transaction(0, 0, 0, 0.0);
    test5.insert(pointer);
    assert(test5.at(0)->getSender() == 0);

    //ensure remove works with object pointers
    LinkedList<Transaction*> test6;
    Transaction *pointer1 = new Transaction(0, 1,0,0);
    Transaction *pointer2 = new Transaction(0, 2,0,0);
    Transaction *pointer3 = new Transaction(0, 3,0,0);
    test6.insert(pointer1);
    test6.insert(pointer2);
    test6.insert(pointer3);
    test6.remove(pointer2);
    assert(test6.at(1)->getSender() == 3);

    //ensure copy function works for object pointers
    LinkedList<Transaction*> test7;
    test7.insert(pointer1);
    test7.insert(pointer2);
    test7.insert(pointer3);
    LinkedList<Transaction*> test7Copy = LinkedList<Transaction*>(test7);
    assert(test7.at(0)->getSender() == 1);
    assert(test7.at(1)->getSender() == 2);
    assert(test7.at(2)->getSender() == 3);

    //ensure assignment operator works for object pointers
    LinkedList<Transaction*> test8;
    test8.insert(pointer1);
    test8.insert(pointer2);
    test8.insert(pointer3);
    LinkedList<Transaction*> test8Copy;
    test8Copy = test8;
    assert(test8.at(0)->getSender() == 1);
    assert(test8.at(1)->getSender() == 2);
    assert(test8.at(2)->getSender() == 3);

    cout << "\n\nInsert, remove, at tests:\n" << endl;

    //ensure insert, remove, and at functions work with subclasses
    LinkedList<Transaction*> test10;
    CreditCard *creditCard = new CreditCard();
    Check *check = new Check();
    Cash *cash = new Cash();
    test10.insert(creditCard);
    test10.insert(check);
    test10.insert(cash);
    test10.at(1)->display();
    test10.remove(check);
    test10.at(1)->display();

    cout << "\n\nCopy constructor tests:\n" << endl;

    //ensure copy constructor works for subclasses
    LinkedList<Transaction*> test11;
    test11.insert(creditCard);
    test11.insert(check);
    test11.insert(cash);
    LinkedList<Transaction*> test11Copy = LinkedList<Transaction*>(test11);
    test11Copy.display();

    cout << "\n\nCopy assignment tests:\n" << endl;

    LinkedList<Transaction*> test12;
    test12.insert(creditCard);
    test12.insert(check);
    test12.insert(cash);
    LinkedList<Transaction*> test12Copy;
    test12Copy = test12;
    test12Copy.display();

    cout << "All Tests Passed!" << endl;

    return 0;
}