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
 *             .-------'
 *             |
 *            \ /
 *             '
 *             .
 *             .
 *             .
 *             |
 *            \ /
 *             '
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
    ~Head() { this->empty(); };
    void insert(T& t);
    void remove(T& t);
    T& removeFirst();
    bool isEmpty();
    void empty();
protected:
    Node<T>* next = nullptr;

public:
    /*
     * Iterator for the linked list: as a simple design, we use the node
     * itself as a representation of the iterator.
     *
     * So end() returns simply the NULL pointer.
     */
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

/* this function allows to remove node also
 * in case T doesn't have comparison
 * operators defined
 */
template<typename T>
T& Head<T>::removeFirst() {
    if (this->next == nullptr) {
        throw std::string("I could not remove an element from an empty list");
    }

    Node<T>* victim = this->next;

    this->next = victim->next;

    T& result = victim->value;

    delete victim;

    return result;
}

template<typename T>
void Head<T>::remove(T& value) {
    Node<T>* ref = this->next;
    Node<T>* prev = nullptr;

    bool found = false;

    for ( ; ref ; ref = ref->next) {
        /* here the case for all but the first node */
        if (ref->value == value && prev) {
            prev->next = ref->next;
            found = true;
            break;
        /* here the case for the first node (we have to update the Head itself) */
        } else if (ref->value == value && !prev) {
            /* TODO: it's a little hacky! */
            this->next = ref->next;
            found = true;
            break;
        }
        prev = ref;
    }

    if (found) {
        delete ref;
    } else {
        throw std::string("element not found");
    }
}

template<typename T>
bool Head<T>::isEmpty() {
    return this->next == nullptr;
}

template<typename T>
void Head<T>::empty() {
    while (!this->isEmpty()) {
        this->removeFirst();
    }
}
#endif // LINKED_H
