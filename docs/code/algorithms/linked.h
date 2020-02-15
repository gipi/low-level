/**
 * Implementation if a linked list.
 *
 * <Head>-----.
 *            |
 *           \ /
 *            '
 *           -------- ---
 *          | <data> | * |
 *           -------- ---
 *             .-------'
 *             |
 *            \ /
 *             '
 *           -------- ---
 *          | <data> | * |
 *           -------- ---
 *
 * In this implementation I use a head that is not a node
 * so to have special cases sorted out without special
 * handling (like removing the first node of the list).
 *
 */
#ifndef LINKED_H
#define LINKED_H

template<typename T>
class Node {
public:
    T value;
    Node() {};
    Node(T v): value(v) {};

    template<typename U>
    friend class Head;
private:
    Node<T>* next = nullptr; /* DO NOT USE REF!!! */
};

template <typename T>
class Head : Node<T> {
public:
    Head() {};
    void insert(Node<T>& n);
    void remove(Node<T>& n);
};


template <typename T>
void Head<T>::insert(Node<T>& node) {
    Node<T>* next = this->next;

    this->next = &node;
    node.next = next;
}

template<typename T>
void Head<T>::remove(Node<T>& node) {
    Node<T>* ref = this->next;

    for ( ; ref ; ref = ref->next) {
        if (ref->next && ref->next == &node) {
            ref->next = ref->next->next;
            break;
        }
    }
}
#endif // LINKED_H
