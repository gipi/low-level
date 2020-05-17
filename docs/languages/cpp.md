# C++

 - [cppreference.com](https://en.cppreference.com/)
 - https://isocpp.org/wiki/faq
 - http://yosefk.com/c++fqa
 - [C++ tutorial for C users](http://www.ericbrasseur.org/cppcen.html)
 - [Writing C++17 for 16-bit x86](https://dev.krzaq.cc/post/writing-cpp17-for-16bit-x86/)

## Constructor

There are two differente ways to create an object

```
Time t (12, 0, 0);
Time* t = new Time(12, 0, 0);
```

the first allocates the object on the stack, the latter on the heap ([src](http://stackoverflow.com/questions/3673998/what-is-difference-between-instantiating-an-object-using-new-vs-without)).

Take in mind that if you want to use the default constructor, you cannot write

```
Time t();
```

because would pass as a function declaration, you have to use

```
Time t;
```

See [this answer](https://stackoverflow.com/questions/49802012/different-ways-of-initializing-an-object-in-c) from stackoverflow.

Also, when you use a statement like

```c++
Time t = Time(12, 0, 0);
```

in reality, under the hood, the constructor is called of T for the right hand side
and then the copy constructor for the assignment to the left hand side.

### Default constructor

A default constructor is a constructor that either has no parameters, or if it
has parameters, all the parameters have default values.

### Copy constructor

It's in the form ``Class(const Class&)``.

## Inheritance

It's possible to have multiple parent classes.

## virtual

 - https://stackoverflow.com/questions/2391679/why-do-we-need-virtual-functions-in-c
 - https://en.cppreference.com/w/cpp/language/virtual

## Visibility

They exist three keyword

 - ``public``: anyone can access
 - ``protected``: only class and subclasses can access
 - ``private``: only the class in which is defined can access

but also exists

 - ``friend``: allows to specify methods or attributes that can access private properties

## Copying, constant and references

By default, when you pass a class as an argument of a function, the copy constructor
is called for that class; to avoid that overhead you can use a ``const`` reference.

 - [Thinking in C++, 2nd ed. Volume 1/References & the Copy-Constructor](http://www.cs.ust.hk/~dekai/library/ECKEL_Bruce/TICPP-2nd-ed-Vol-one/TICPP-2nd-ed-Vol-one-html/Chapter11.html)

## Operators overloading

 - [C++ Operator Overloading Guidelines](http://courses.cms.caltech.edu/cs11/material/cpp/donnie/cpp-ops.html)

## Templates

 - [Why templates can only be implemented in the header file](http://stackoverflow.com/questions/495021/why-can-templates-only-be-implemented-in-the-header-file)
 - https://stackoverflow.com/questions/43268146/why-is-stditerator-deprecated
 - https://softwareengineering.stackexchange.com/questions/386614/c-iterator-why-is-there-no-iterator-base-class-all-iterators-inherit-from

## Iterators

 - [C++ Iterators](https://users.cs.northwestern.edu/~riesbeck/programming/c++/stl-iterators.html)
 - [Defining C++ Iterators](https://users.cs.northwestern.edu/~riesbeck/programming/c++/stl-iterator-define.html)
 - [Implementing Iterator pattern of a single Linked List](https://www.geeksforgeeks.org/implementing-iterator-pattern-of-a-single-linked-list/)

## Mutables

## Interfaces

Pratically a class with only virtual functions.

```c++
class Entity {
public:
    virtual std::string getName() = 0;
};
```

## Strings

C++ has the C well known ``char*`` with the same behaviour; the "standard" way of using strings in C++ is
by the ``std::string`` class. Obviously you usually do something like this when coding

```c++
void some_function(std::string);

int main() {
    ...
    some_function("foobar");
    ...
}
```

take in mind that ``"foobar"`` is in a readonly memory, under the hood it's converted to ``std::string``
copying its content.

 - [std::string copy constructor NOT deep in GCC 4.1.2?](https://stackoverflow.com/questions/16604925/stdstring-copy-constructor-not-deep-in-gcc-4-1-2)
 - [Is std::string refcounted in GCC 4.x / C++11?](https://stackoverflow.com/questions/12520192/is-stdstring-refcounted-in-gcc-4-x-c11)

## Exceptions

```c++
#include <stdexcept>

class DivideDyZero : public runtime_error {
    public:
        DivideDyZero() :
         runtime_error("divide by zero exception") {}
};

void whatever() {
    ...
    try{
        ...
    } catch (DivideDyZero & err) {
        std::cerr << err.what() << std::endl;
    } catch (...) {
        std::cerr << "Catch all" << std::endl;
    }
    ...
}
```

## PIMPL

Idiom to break compilation dependencies.

 - https://www.bfilipek.com/2018/01/pimpl.html
 - https://en.cppreference.com/w/cpp/language/pimpl
