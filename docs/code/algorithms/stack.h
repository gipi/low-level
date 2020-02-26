#ifndef STACK_H
#define STACK_H
/*
 * Stack implementation using a linked list.
 *
 * */
#include "linked.h"

template<typename T>
class Stack : public Head<T> {
public:
    T& push(T&);
    T& pop();
    bool isEmpty();
};


template<typename T>
T& Stack<T>::push(T& value) {
    Node<T>* wrapper = new Node<T>(value);
    this->insert(*wrapper);

    return value;
}

template<typename T>
T& Stack<T>::pop() {
    Node<T>& top = *this->next;
    this->remove(top);

    T& value = top.value;

    delete &top;

    return value;
}

#endif // STACK_H
