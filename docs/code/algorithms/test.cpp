#include "linked.h"

int main(int argc, char* argv[]) {
    Node<int> n1 = Node<int>(0x01);

    Node<int>* n2 = new Node<int>(0x02);

    Head<int>* head = new Head<int>();

    head->insert(n1);
    head->insert(*n2);

    head->remove(n1);
    head->remove(*n2);
#if 0
    Node<int>& n;

    ll_for_each(head, n) {
        printf("%x\n", n->value);
    }

    ll_insert(head, &n1);

    ll_for_each(head, n) {
        printf("%x\n", n->value);
    }

    ll_insert(head, &n2);
    ll_for_each(head, n) {
        printf("%x\n", n->value);
    }


    ll_remove(head, &n2);
    ll_for_each(head, n) {
        printf("%x\n", n->value);
    }

    ll_remove(head, &n1);
    ll_for_each(head, n) {
        printf("%x\n", n->value);
    }

#endif
    return 0;
}
