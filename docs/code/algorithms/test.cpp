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
    bool operator==(Integer& other) { return value == other.value; };
    bool operator<(Integer& other) { return value < other.value; };
    bool operator>(Integer& other) { return value > other.value; };
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




int main(int argc, char* argv[]) {
    (void)argc;
    (void)argv;

    test_arraylist();
    test_string_builder();

    return 0;
}
