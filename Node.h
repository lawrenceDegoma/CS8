//
// Created by Lawrence Degoma on 3/12/24.
//

#ifndef LINKEDLISTNOTES_NODE_H
#define LINKEDLISTNOTES_NODE_H
template<typename T>
struct Node{
    T data;
    Node<T> *next = nullptr, *prev = nullptr;
};

#endif //LINKEDLISTNOTES_NODE_H
