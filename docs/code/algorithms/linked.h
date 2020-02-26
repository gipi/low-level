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
    T& value;
    Node(T& v): value(v) {};

    template<typename U>
    friend class Head;
private:
    Node<T>* next = nullptr; /* DO NOT USE REF!!! */
};

template <typename T>
class Head {
public:
    Head() {};
    void insert(Node<T>& n);
    void remove(Node<T>& n);
protected:
    Node<T>* next = nullptr;
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
    Node<T>* prev = nullptr;

    for ( ; ref ; ref = ref->next) {
        if (ref == &node && prev) {
            prev->next = ref->next;
            break;
        } else if (ref == &node && !prev) {
            /* TODO: it's a little hacky! */
            this->next = ref->next;
            break;
        }
        prev = ref;
    }
}
#endif // LINKED_H
