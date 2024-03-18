//
// Created by Lawrence Degoma on 3/13/24.
//

#include "NodeIterator.h"

template<typename T>
NodeIterator<T>::NodeIterator() : _current(nullptr){}

template<typename T>
NodeIterator<T>::NodeIterator(Node<T> *current) : _current(current) {}

template<typename T>
NodeIterator<T> &NodeIterator<T>::operator++() {
    if (_current)
        _current = _current->next;
    return *this;
}

template<typename T>
NodeIterator<T> NodeIterator<T>::operator++(int) {
    NodeIterator tmp(*this);
    operator++();
    return tmp;
}

template<typename T>
NodeIterator<T> &NodeIterator<T>::operator--() {
    if (_current)
        _current = _current->prev;
    return *this;
}

template<typename T>
NodeIterator<T> NodeIterator<T>::operator--(int) {
    NodeIterator tmp = *this;
    operator--();
    return tmp;
}

template<typename T>
T &NodeIterator<T>::operator*() {
    return _current->data;
}

template<typename U>
bool operator==(const NodeIterator<U> &lhs, const NodeIterator<U> &rhs) {
    return lhs._current == rhs._current;
}

template<typename U>
bool operator!=(const NodeIterator<U> &lhs, const NodeIterator<U> &rhs) {
    return !(lhs == rhs);
}
