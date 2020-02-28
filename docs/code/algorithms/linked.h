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
#include <iterator>


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
    void insert(T& t);
    void remove(T& t);
protected:
    Node<T>* next = nullptr;

public:
    class iterator: public std::iterator<std::forward_iterator_tag,   // iterator_category
            T,                      // value_type
            long,                      // difference_type
            const long*,               // pointer
            long                       // reference
    >{
    public:
        explicit iterator(const Node<T>* n) : node(n) {};
    T& operator* () { return this->node->value; };
    iterator& operator++() {
        this->node = this->node->next;
        return *this;
    };
    bool operator==(const iterator& other) { return this->node == other.node; };
    bool operator!=(const iterator& other) { return !this->operator==(other); };

private:
        const Node<T>* node;
    };
    iterator begin() { return iterator(this->next); };
    iterator end() {return iterator(nullptr); };
};


template <typename T>
void Head<T>::insert(T& value) {
    Node<T>* node = new Node<T>(value);
    Node<T>* next = this->next;

    this->next = node;
    node->next = next;
}

template<typename T>
void Head<T>::remove(T& value) {
    Node<T>* ref = this->next;
    Node<T>* prev = nullptr;

    for ( ; ref ; ref = ref->next) {
        if (ref->value == value && prev) {
            prev->next = ref->next;
            break;
        } else if (ref->value == value && !prev) {
            /* TODO: it's a little hacky! */
            this->next = ref->next;
            break;
        }
        prev = ref;
    }
}
#endif // LINKED_H
