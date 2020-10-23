#ifndef PROGRAM5_LINKEDLIST_H
#define PROGRAM5_LINKEDLIST_H

#include <iostream>

template <typename T>
struct Node
{
    T data;
    Node *next;
};

template <typename T>
class LinkedList {
public:
    LinkedList();
    ~LinkedList();
    LinkedList(const LinkedList &copy);
    LinkedList& operator=(const LinkedList&);

    void insert(T);
    void remove(T);
    T at(int index);
    void display();
    int getSize();

private:
    int size;
    Node<T> *head;
    Node<T> *tail;
};

template <typename T>
LinkedList<T>::LinkedList()
{
    head = nullptr;
    tail = nullptr;
    size = 0;
}

template <typename T>
LinkedList<T>::~LinkedList()
{
    auto curr = this->head;
    auto currNext = curr->next;

    for(int i = 0; i < size; i++)
    {
        delete curr;
        curr = currNext;
        if(curr != nullptr)
        {
            currNext = curr->next;
        }
    }
}

template <typename T>
LinkedList<T>::LinkedList(const LinkedList &copy)
{
    auto curr = copy.head;
    size = copy.size;

    head = nullptr;
    tail = nullptr;

    while(curr != nullptr)
    {
        auto currNext = curr->next;

        auto *newNode = new Node<T>();
        newNode->data = curr->data;
        newNode->next = nullptr;

        if(head == nullptr)
        {
            head = newNode;
            tail = newNode;
        } else
        {
            tail->next = newNode;
            tail = newNode;
        }
        curr = currNext;
    }
}

template <typename T>
LinkedList<T>& LinkedList<T>::operator=(const LinkedList &copy)
{
    auto curr = head;
    size = copy.size;

    while(curr != nullptr)
    {
        auto currNext = curr->next;
        delete curr;
        curr = currNext;
    }

    curr = copy.head;
    while(curr != nullptr)
    {
        auto currNext = curr->next;
        auto *node = new Node<T>();
        node->data = curr->data;
        node->next = nullptr;

        if(head == nullptr)
        {
            head = node;
            tail = node;
        } else
        {
            tail->next = node;
            tail = node;
        }
        curr = currNext;
    }
}

template <typename T>
T LinkedList<T>::at(int index)
{
    auto currNode = this->head;

    if(index >= size || index < 0)
    {
        std::cout << "Index out of range" << std::endl;
        exit(1);
    }
    else {
        for (int i = 0; i < index; i++) {
            currNode = currNode->next;
        }
        return currNode->data;
    }
}

template <typename T>
void LinkedList<T>::insert(T data)
{
    auto node = new Node<T>();
    node->data = data;
    node->next = nullptr;

    if(head != nullptr)
    {
        tail->next = node;
        tail = node;
    } else{
        head = node;
        tail = node;
    }
    size++;
}

template <typename T>
void LinkedList<T>::remove(T data)
{
    if(head != nullptr)
    {
        Node<T> *temp = head;
        head = head->next;
        delete temp;
    }
}

template <typename T>
void LinkedList<T>::display()
{
    auto curr = this->head;
    while(curr != nullptr)
    {
        curr->data->display();
        curr = curr->next;
    }
}

template <typename T>
int LinkedList<T>::getSize()
{
    return size;
}


#endif //PROGRAM5_LINKEDLIST_H
