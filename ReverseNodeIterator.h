//
// Created by Lawrence Degoma on 3/18/24.
//

#ifndef LINKEDLISTNOTES_REVERSENODEITERATOR_H
#define LINKEDLISTNOTES_REVERSENODEITERATOR_H
#include "Node.h"
#include <iterator>

template<typename T>
class ReverseNodeIterator : std::iterator<std::bidirectional_iterator_tag, T>{
private:
    Node<T>* _current;
public:
    ReverseNodeIterator();
    ReverseNodeIterator(Node<T>* current);

    ReverseNodeIterator& operator++();
    ReverseNodeIterator operator++(int);
    ReverseNodeIterator& operator--();
    ReverseNodeIterator operator--(int);

    T& operator*();

    template <typename U>
    friend bool operator==(const ReverseNodeIterator<U>& lhs, const ReverseNodeIterator<U>& rhs);

    template <typename U>
    friend bool operator!=(const ReverseNodeIterator<U>& lhs, const ReverseNodeIterator<U>& rhs);

};


#endif //LINKEDLISTNOTES_REVERSENODEITERATOR_H
