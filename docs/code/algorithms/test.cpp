#include "linked.h"
#include "tree.h"
#include <iostream>
#include <string>

int main(int argc, char* argv[]) {
    Node<int> n1 = Node<int>(0x01);

    Node<int>* n2 = new Node<int>(0x02);

    Head<int>* head = new Head<int>();

    head->insert(n1);
    head->insert(*n2);

    head->remove(n1);
    head->remove(*n2);

    /*
    int first = 0;
    TreeNode<int> tn = TreeNode<int>(first);

    tn.insert(100);
    tn.insert(-100);

    tn.find(100);
    tn.remove(100);
*/
    /* look ma! I can create a Tree with strings!!! */
    std::string miao = std::string("miao");
    TreeNode<std::string>* strtn = new TreeNode<std::string>(miao);
    std::string tmp = std::string("bau");
    strtn->insert(tmp);
    auto kebab = std::string("kebab");
    strtn->insert(kebab);

    for (std::string name : *strtn) {
        std::cout << name << std::endl;
    }
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
