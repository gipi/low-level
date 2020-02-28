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
};


template<typename T>
T& Stack<T>::push(T& value) {
    this->insert(value);

    return value;
}

template<typename T>
T& Stack<T>::pop() {
    if (this->isEmpty()) {
        throw std::string("stack empty, you cannot pop from it");
    }
    T& value = this->next->value;
    this->remove(value);

    return value;
}

#endif // STACK_H
