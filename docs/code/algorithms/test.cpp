#include "linked.h"
#include "tree.h"
#include "arraylist.h"
#include "strbuilder.h"
#include "stack.h"
#include <iostream>
#include <string>

class Integer {
public:
    Integer(int v) : value(v) {};
    ~Integer() {};
    int value;
};

std::string* get_favorite_food() {
    StringBuilder builder("bau");
    builder.append("kebab");
    builder.append("onion");

    return builder.build(", ");
}

void test_string_builder() {
    std::string* result = get_favorite_food();
    std::cout << *result << std::endl;

    delete result;
}

void test_arraylist() {
    ArrayList<int> a_empty;
    int a_static[] = {1, 2, 3, 4, 5};
    ArrayList<int>A(a_static, 5);
}

void test_stack() {
    Integer v1(1);
    Integer v2(2);
    Integer v3(3);
    Integer v4(4);

    Stack<Integer> stack;
    stack.push(v1);
    stack.push(v2);

    stack.pop();

    stack.push(v3);
    stack.push(v4);

    stack.pop();
}

int main(int argc, char* argv[]) {
    (void)argc;
    (void)argv;

    test_arraylist();
    test_string_builder();

    test_stack();

    return 0;
}
