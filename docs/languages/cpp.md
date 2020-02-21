# C++

 - [cppreference.com](https://en.cppreference.com/)

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

## Inheritance

It's possible to have multiple parent classes.

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

## Mutables

## Interfaces

Pratically a class with only virtual functions.

```c++
class Entity {
public:
    virtual std::string getName() = 0;
};
```
