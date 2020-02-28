#include <iostream>

#include "stack.h"


class Integer {
public:
    Integer(int v) : value(v) {};
    ~Integer() {};
    int value;
    bool operator==(Integer& other) { return value == other.value; };
    bool operator<(Integer& other) { return value < other.value; };
    bool operator>(Integer& other) { return value > other.value; };
};

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

    for (Integer& i : stack) {
        std::cout << i.value << std::endl;
    }
}

int main() {
    test_stack();
}
