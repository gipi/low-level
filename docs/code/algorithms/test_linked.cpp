#include <iostream>

#include "linked.h"

class Integer {
public:
    Integer(int v) : value(v) {};
    ~Integer() {};
    int value;
    bool operator==(Integer& other) { return value == other.value; };
    bool operator<(Integer& other) { return value < other.value; };
    bool operator>(Integer& other) { return value > other.value; };
};

void test_linked() {
    Integer v0(0);
    Integer v1(1);
    Integer v2(2);
    Integer v3(3);
    Integer v4(4);
    Integer v5(5);

    Head<Integer> head;
    head.insert(v0);
    head.insert(v1);
    head.insert(v2);
    head.insert(v3);
    head.insert(v4);
    head.insert(v5);

    for (Integer& value : head) {
        std::cout << value.value << std::endl;
    }
}

int main() {
    std::cout << "running test for linked lists" << std::endl;
    test_linked();
}
