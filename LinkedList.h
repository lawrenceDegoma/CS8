//
// Created by Lawrence Degoma on 3/12/24.
//

#ifndef LINKEDLISTNOTES_LINKEDLIST_H
#define LINKEDLISTNOTES_LINKEDLIST_H
#include "Node.h"
#include "NodeIterator.cpp"
#include "ConstNodeIterator.cpp"
#include "ReverseNodeIterator.cpp"
#include <iostream>

template <typename T>
class LinkedList  {
private:
    Node<T> *head = nullptr, *tail = nullptr;
    void addFirstNode(Node<T>* node); // add node as the first node in the list
    Node<T>* createNode(const T& data); // return a new node containing data
    void push_front(Node<T>* node); // add node to the front of the list
    void push_back(Node<T>* node); // add node to the back of the list

    Node<T>* search(const T& data); // return the first node containing data, otherwise nullptr
    void remove(Node<T>* node); // remove the node from the list
    int _size = 0;

public:
    typedef NodeIterator<T> iterator;
    typedef ConstNodeIterator<T> const_iterator;
    typedef ReverseNodeIterator<T> reverse_iterator;
    LinkedList();
    LinkedList(const LinkedList& list);
    ~LinkedList();
    void operator=(const LinkedList<T>& list);
    void push_front(const T& item); // create a new node containing item, and pass the node to the private push func
    void push_back(const T& item); // create a new node containing item, and pass the node to the private push func
    void pop_back();
    void pop_front();
    int size();
    bool empty = true;
    template <typename U>
    friend std::ostream& operator<<(std::ostream& out, const LinkedList<U>& list);
    LinkedList& operator+=(const LinkedList<T>& list);

    iterator begin();
    iterator end();

    const_iterator cbegin() const;
    const_iterator cend() const;

    reverse_iterator rbegin();
    reverse_iterator rend();
};

#endif //LINKEDLISTNOTES_LINKEDLIST_H
