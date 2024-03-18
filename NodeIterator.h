//
// Created by Lawrence Degoma on 3/13/24.
//

#ifndef LINKEDLISTNOTES_NODEITERATOR_H
#define LINKEDLISTNOTES_NODEITERATOR_H
#include"Node.h"
#include <iterator>

// input iterator
// output iterator
// forward iterator
// bidirectional iterator **
// random access iterator

template <typename T>
class NodeIterator : public std::iterator<std::bidirectional_iterator_tag, T>{
private:
    Node<T>* _current;

public:
    NodeIterator();
    NodeIterator(Node<T>* current);

    // ++ prefix
    // ++ changes iterator, therefore should be a member function. Otherwise it would be a friend
    NodeIterator& operator++();

    // ++ postfix makes a copy, increments, returns copy
    NodeIterator operator++(int);

    // -- prefix
    NodeIterator& operator--();

    // -- postfix makes a copy, increments, returns copy
    NodeIterator operator--(int);

    // dereference
    T& operator*();

    // equal to
    template <typename U>
    friend bool operator==(const NodeIterator<U>& lhs, const NodeIterator<U>& rhs);

    // not equal
    template <typename U>
    friend bool operator!=(const NodeIterator<U>& lhs, const NodeIterator<U>& rhs);
};


#endif //LINKEDLISTNOTES_NODEITERATOR_H
