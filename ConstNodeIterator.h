//
// Created by Lawrence Degoma on 3/17/24.
//

#ifndef LINKEDLISTNOTES_CONSTNODEITERATOR_H
#define LINKEDLISTNOTES_CONSTNODEITERATOR_H

#include "Node.h"
#include <iterator>

template <typename T>
class ConstNodeIterator : public std::iterator<std::bidirectional_iterator_tag, const T>{
private:
    const Node<T>* _current;
public:
    ConstNodeIterator();
    ConstNodeIterator(const Node<T>* current);

    // prefix ++
    ConstNodeIterator& operator++();

    // postfix ++
    ConstNodeIterator operator++(int);

    // prefix --
    ConstNodeIterator& operator--();

    // postfix --
    ConstNodeIterator operator--(int);

    // Dereference
    const T& operator*() const;

    // Comparisons
    template<typename U>
    friend bool operator==(const ConstNodeIterator<U>& lhs, const ConstNodeIterator<U>& rhs);

    template<typename U>
    friend bool operator!=(const ConstNodeIterator<U>& lhs, const ConstNodeIterator<U>& rhs);
};


#endif //LINKEDLISTNOTES_CONSTNODEITERATOR_H
