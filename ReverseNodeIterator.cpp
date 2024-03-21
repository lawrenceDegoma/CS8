//
// Created by Lawrence Degoma on 3/18/24.
//

#include "ReverseNodeIterator.h"

template<typename T>
ReverseNodeIterator<T>::ReverseNodeIterator() : _current(nullptr){}

template<typename T>
ReverseNodeIterator<T>::ReverseNodeIterator(Node<T> *current) : _current(current) {}

template<typename T>
ReverseNodeIterator<T> &ReverseNodeIterator<T>::operator++() {
    if (_current)
        _current = _current->prev;
    return *this;
}

template<typename T>
ReverseNodeIterator<T> ReverseNodeIterator<T>::operator++(int) {
    ReverseNodeIterator tmp(*this);
    operator++();
    return tmp;
}

template<typename T>
ReverseNodeIterator<T> &ReverseNodeIterator<T>::operator--() {
    if (_current)
        _current = _current->next;
    return *this;
}

template<typename T>
ReverseNodeIterator<T> ReverseNodeIterator<T>::operator--(int) {
    ReverseNodeIterator tmp(*this);
    operator--();
    return tmp;
}

template<typename T>
T &ReverseNodeIterator<T>::operator*() {
    return _current->data;
}

template<typename U>
bool operator==(const ReverseNodeIterator<U> &lhs, const ReverseNodeIterator<U> &rhs) {
    return lhs._current == rhs._current;
}

template<typename U>
bool operator!=(const ReverseNodeIterator<U> &lhs, const ReverseNodeIterator<U> &rhs) {
    return !(lhs == rhs);
}