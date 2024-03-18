//
// Created by Lawrence Degoma on 3/17/24.
//

#include "ConstNodeIterator.h"

template<typename T>
ConstNodeIterator<T>::ConstNodeIterator() : _current(nullptr){}

template<typename T>
ConstNodeIterator<T>::ConstNodeIterator(const Node<T>* current) : _current(current){}

template<typename T>
ConstNodeIterator<T>& ConstNodeIterator<T>::operator++(){
    if (_current)
        _current = _current->next;
    return *this;
}

template<typename T>
ConstNodeIterator<T> ConstNodeIterator<T>::operator++(int){
    ConstNodeIterator tmp(*this);
    operator++();
    return tmp;
}

template<typename T>
ConstNodeIterator<T>& ConstNodeIterator<T>::operator--() {
    if (_current)
        _current = _current->prev;
    return *this;
}

template<typename T>
ConstNodeIterator<T> ConstNodeIterator<T>::operator--(int) {
    ConstNodeIterator tmp = *this;
    operator--();
    return tmp;
}

template<typename T>
const T &ConstNodeIterator<T>::operator*() const {
    return _current->data;
}

template<typename U>
bool operator==(const ConstNodeIterator<U>& lhs, const ConstNodeIterator<U>& rhs){
    return lhs._current == rhs._current;
}

template<typename U>
bool operator!=(const ConstNodeIterator<U>& lhs, const ConstNodeIterator<U>& rhs){
    return !(lhs == rhs);
}