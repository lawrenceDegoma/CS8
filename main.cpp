#include <iostream>
#include "LinkedList.cpp"
#include <vector>

int main() {

    LinkedList<int> list;
    for (int i = 0; i < 10; i++)
        list.push_back(i);


    std::cout << "\n\n Iterator Test\n";
    for (auto i: list) {
        std::cout << i;
    }
    std::cout << "\n\n Const Iterator Test\n";
    for(auto i = list.cbegin(); i != list.cend(); ++i)
    {
        std::cout << *i << " ";
    }

    std::cout << "\n\n reverse Iterator Test\n";
    for(auto i = list.rbegin(); i != list.rend(); ++i)
    {
        std::cout << *i << " ";
    }
    return 0;
}



/* Linked List
 * A list of data connected by nodes in random parts of memory
 *
 * Fixes the problem:
 * inserting in middle of list
 * resizing arrays
 * deleting from arrays
 * sequential memory allocation
 *
 * What is a node:
 * Data and some node pointer
 * Node pointers are used to connect the nodes together
 * To keep track of where the next and prev node in the list are
 *
 * Creating a first node
 *
 * template<T>
 * Struct Node {
 *      T data;
 *      node<T>* next, prev
 *
 * Node<T>* n = new Node<T>
 * n->next = nullptr;
 * n->prev = nullptr;
 * head = n;
 * tail = n;
 *
 * Push_front:
 * Node<T>* n = new Node<t>
 * head->prev = n;
 * n->next = head;
 * head = n;
 * n->prev = nullptr;
 *
 * Iterators
*/

