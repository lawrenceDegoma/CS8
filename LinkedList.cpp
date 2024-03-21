//
// Created by Lawrence Degoma on 3/12/24.
//

#include "LinkedList.h"

template<typename T>
LinkedList<T>::LinkedList() {}

template<typename T>
LinkedList<T>::LinkedList(const LinkedList &list) {
    *this = list;
}

template <typename T>
void LinkedList<T>::addFirstNode(Node<T> *node) {
    node->next = nullptr;
    node->prev = nullptr;
    head = node;
    tail = node;
    empty = false;
}

template<typename T>
LinkedList<T>::~LinkedList() {
    while(head)
        pop_front();
}

template<typename T>
void LinkedList<T>::operator=(const LinkedList<T>& list){
    if(&list != this)
    {
        this->~LinkedList();
        ConstNodeIterator<T> iter = list.cbegin();
        for (; iter != list.cend(); ++iter){
            push_back(*iter);
        }
    }
}

template<typename T>
Node<T> *LinkedList<T>::createNode(const T &data) {
    auto* n = new Node<T>;
    n->data = data;
    return n;
}

template<typename T>
void LinkedList<T>::remove(Node<T> *node) {
    if (!empty) {
        auto *target = head;
        while (target != nullptr && target->data != node->data) {
            target = target->next;
        }
        if (target == nullptr)
            return;
        else {
            auto *previous = target->prev;
            auto *cur = target->next;

            previous->next = cur;
            cur->prev = previous;
            delete target;
        }
    }
}

template<typename T>
void LinkedList<T>::push_front(Node<T>* node) {
    if (head == nullptr){
        addFirstNode(node);
    }
    else {
        head->prev = node;
        node->next = head;
        head = node;
        node->prev = nullptr;
    }
}

template<typename T>
void LinkedList<T>::push_back(Node<T>* node) {
    if (head == nullptr){
        addFirstNode(node);
    }
    else {
        tail->next = node;
        node->prev = tail;
        tail = node;
        node->next = nullptr;
    }
}

template<typename T>
void LinkedList<T>::push_front(const T &item) {
    auto* node = createNode(item);
    push_front(node);
}

template<typename T>
void LinkedList<T>::push_back(const T &item) {
    auto* node = createNode(item);
    push_back(node);
}

template<typename T>
Node<T> *LinkedList<T>::search(const T &data) {
    Node<T>* ptr = head;
    while(ptr != NULL){
        if (ptr->data == data)
            return ptr;
        ptr = ptr->next;
    }
    return nullptr;
}

template<typename T>
void LinkedList<T>::pop_back() {
    if (empty){
        return;
    }
    Node<T>* target = tail;
    tail = tail->prev;
    if (tail != nullptr)
        tail->next = nullptr;
    else
        head = nullptr;
    remove(target);
}

template<typename T>
void LinkedList<T>::pop_front() {
    if (empty){
        return;
    }
    Node<T>* target = head;
    head = head->next;
    if (head != nullptr)
        head->prev = nullptr;
    else
        tail = nullptr;
    remove(target);
}

template<typename U>
std::ostream &operator<<(std::ostream &out, const LinkedList<U> &list) {
    for (const auto &i : list)
        out << i << " ";
    return out;
}

template<typename T>
LinkedList<T>& LinkedList<T>::operator+=(const LinkedList<T>& list){
    for (const T& item : list)
        push_back(item);
    return *this;
}

template<typename T>
typename LinkedList<T>::iterator LinkedList<T>::begin(){
    return NodeIterator<T>(head);
}

template<typename T>
typename LinkedList<T>::iterator LinkedList<T>::end(){
    return NodeIterator<T>(nullptr);
}

template<typename T>
typename LinkedList<T>::const_iterator LinkedList<T>::cbegin() const{
    return ConstNodeIterator<T>(head);
}

template<typename T>
typename LinkedList<T>::const_iterator LinkedList<T>::cend() const{
    return ConstNodeIterator<T>(nullptr);
}

template<typename T>
typename LinkedList<T>::reverse_iterator LinkedList<T>::rbegin(){
    return ReverseNodeIterator<T>(tail);
}

template<typename T>
typename LinkedList<T>::reverse_iterator LinkedList<T>::rend(){
    return ReverseNodeIterator<T>(nullptr);
}