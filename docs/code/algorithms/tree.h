/**
 * Implementation of a Binary Tree.
 *
 * The base class is the TreeNode (indicated with a X) that has a structure like the following:
 *
 *                       <P> parent
 *                        |
 *                       <X>
 *                      /   \
 *               left <L>   <R> right
 *
 * This class encapsulate the data T that we want to sort (so the type T needs to
 * be sortable of course).
 *
 * The structure of a BT has the following properties: given a node N
 *
 *  - the smallest element in the right subtree is the next in order
 *  - the greatest element in the left subtree is the previous in order
 *
 * TODO: probably we need to pass pointer/reference instead of instance of T to avoid copying
 *       around stuff.
 *
 */
#ifndef TREE_H
#define TREE_H
#include <iterator>


template<typename T>
class TreeNode {
public:
    T& data; /* in this way you have to externally manage the allocation of the instance */
    TreeNode<T>(T& d) : data(d) {};/* use reference to avoid copy constructor */
    TreeNode<T>* find(T x);
    TreeNode<T>* insert(T& x);
    TreeNode<T>* remove(T x);
    TreeNode<T>* smallest();
    TreeNode<T>* greatest();
    TreeNode<T>(const TreeNode<T>&) = delete;
private:
    TreeNode* parent = nullptr;
    TreeNode* left = nullptr;
    TreeNode* right = nullptr;

    /*
     * utility class for internal search.
     *
     * TODO: probably is better to use a struct.
     */
    class _Search {
        friend TreeNode;
    public:

        /* the order between Result and _Search is important */
        enum Result {
            FOUND,
            PARENT_LEFT,
            PARENT_RIGHT
        };
        _Search(TreeNode<T>* n, Result r) : result(r), node(n) {};
    private:
        TreeNode<T>* node;
        Result result;
    };

    _Search* _find(T x);

    /*
     * This is the iterator to obtain the elements of the tree following
     * a certain criteria.
     */
    class iterator: public std::iterator<std::forward_iterator_tag,   // iterator_category
            T,                      // value_type
            long,                      // difference_type
            const long*,               // pointer
            long                       // reference
    >{
    public:
        explicit iterator(const TreeNode<T>* tree) : node(tree) {};
        iterator& operator++() {
            /* we just entered the node from above */
            if (node->left != nullptr && prev == node->parent) {
                prev = node;
                node = node->left;
            /* we are going right after we reached the most left */
            } else if (node->right != nullptr && prev == node->left) {
                prev = node;
                node = node->right;
            /* we are coming from a parent that hasn't a left child */
            } else if (node->right != nullptr && prev == node->parent) {
                prev = node;
                node = node->right;
            /* we have reached a leaf */
            } else if (node->left == nullptr && node->right == nullptr) {
                prev = node;
                node = node->parent;
            } else if (prev == node->left || prev == node->right) {
                prev = node;
                node = node->parent;
            }

            return *this;
        }
        // iterator operator++(int) {}
        bool operator==(iterator other) const { return (node->data == other.node->data) && (prev == other.prev); }
        bool operator!=(iterator other) const { return !(this->operator==(other)); }
        T& operator*() const { return node->data; }
        iterator(TreeNode<T>* n, TreeNode<T>* p) : node(n), prev(p) {};
    private:
        const TreeNode<T>* node;
        const TreeNode<T>* prev = nullptr;
    };
public:
    iterator begin() { return iterator(this); };
    iterator end() {
        /* here we try to recreate the microstate of the final iterator */
        TreeNode<T>* prev = nullptr;
        if (this->right == nullptr && this->left != nullptr) {
            prev = this->left;
        } else {
            prev = this->right;
        }
        return iterator(this, prev);};
};

/**
 * This is the core of the binary tree: given a node N with
 * some data x, we have the nodes with values less than x to
 * the left and nodes with values greater then x to the right.
 *
 * This private method tries to generalize this approach and
 * tries to find an element T or to return the parent on failure.
 */
template<typename T>
typename TreeNode<T>::_Search* TreeNode<T>::_find(T x) {
    if (x == this->data) { /* this always exists */
        return new _Search(this, _Search::FOUND);
    } else if (x < this->data) {
        if (!this->left) {
            return new _Search(this, _Search::PARENT_LEFT);
        }
        return this->left->_find(x);
    } else if (x > this->data) {
        if (!this->right) {
            return new _Search(this, _Search::PARENT_RIGHT);
        }
        return this->right->_find(x);
    }

    //return nullptr;
}

template<typename T>
TreeNode<T>* TreeNode<T>::find(T x) {
    _Search* search = this->_find(x);

    if (search->result == _Search::FOUND) {
        return search->node;
    }

    return nullptr;
}

template <typename T>
TreeNode<T>* TreeNode<T>::insert(T& data) {
    _Search* search = this->_find(data);

    TreeNode<T>* returnValue = nullptr;

    switch (search->result) {
        case _Search::FOUND:
            // TODO: throw?
            break;
        case _Search::PARENT_LEFT:
            returnValue = new TreeNode<T>(data);
            search->node->left = returnValue;
            returnValue->parent = search->node;
            break;
        case _Search::PARENT_RIGHT:
            returnValue = new TreeNode<T>(data);
            search->node->right = returnValue;
            returnValue->parent = search->node;
            break;
        //default:
            // TODO: throw?
    }

    delete search;

    return returnValue;
}

/**
 * The remove algorithm is a little tricky since we want
 * to remove a node but also we want to maintain the children
 * of it; You can substitute the node removed with the smallest element
 * in its right subtree.
 */
template<typename T>
TreeNode<T>* TreeNode<T>::remove(T data) {
    _Search* search = this->_find(data);

    TreeNode<T>* node = search->node;

    /* special cases: leaf, root */
    switch (search->result) {
        case _Search::FOUND: {
            /* the substitute is the smallest of its subtree */
            TreeNode<T>* substitute = node->smallest();
            /* we need to detach it from its parent */
            substitute->parent->left = nullptr;
            /* then left, right and parent accordingly */
            substitute->parent = node->parent;
            substitute->left = node->left;
            substitute->right = node->right;
            break;
        }
        default:
            node = nullptr;
    }

    delete search;

    return node;
}

template<typename T>
TreeNode<T>* TreeNode<T>::smallest() {
    TreeNode<T>* node = this;
    while (node->left) {
        node = node->left;
    }

    return node;
}

#endif // TREE_H
