# C&C++

 - [Beej's Guide to C Programming](https://beej.us/guide/bgc/)
 - [Polymorphism in C](https://itnext.io/polymorphism-in-c-tutorial-bd95197ddbf9)
 - [cppreference.com](https://en.cppreference.com/)
 - [LEARN C++](https://www.learncpp.com/)
 - [cppiceberg](https://fouronnes.github.io/cppiceberg/)
 - [C xor C++ Programming](https://docs.google.com/document/d/16B36r0HksR0LqQAGLA1syYCtZvYaVC0hEF2D00ZAd0o/edit)
 - https://isocpp.org/wiki/faq
 - http://yosefk.com/c++fqa
 - [C++ tutorial for C users](http://www.ericbrasseur.org/cppcen.html)
 - [Writing C++17 for 16-bit x86](https://dev.krzaq.cc/post/writing-cpp17-for-16bit-x86/)
 - [Modern C](http://icube-icps.unistra.fr/img_auth.php/d/db/ModernC.pdf)
 - [C Primer Plus, Fifth Edition](http://faculty.euc.ac.cy/scharalambous/csc131/books/C%20book%201.pdf)
 - [JPL Institutional Coding Standard for the C Programming Language ](http://lars-lab.jpl.nasa.gov/JPL_Coding_Standard_C.pdf)
 - [How to C 2016](https://matt.sh/howto-c)
 - [Some notes C in 2016](http://blog.erratasec.com/2016/01/some-notes-c-in-2016.html)
 - [negating an unsigned number is well defined in C.](http://stackoverflow.com/questions/1269019/what-should-happen-to-the-negation-of-a-size-t-i-e-sizeofstruct-foo/1269049#1269049)
 - http://rus.har.mn/blog/2014-05-19/strtol-error-checking/
 - http://www.catb.org/esr/structure-packing/
 - [Why does calloc exist?](https://vorpus.org/blog/why-does-calloc-exist/)
 - [mem­cpy (and friends) with NULL pointers](https://www.imperialviolet.org/2016/06/26/nonnull.html)
 - [How to Write Portable C Without Complicating Your Build](http://nullprogram.com/blog/2017/03/30/)
 - [C is not your friend: sizeof and side-effects](http://blog.tjd.phlegethon.org/post/159564806182/c-is-not-your-friend-sizeof-and-side-effects)
 - [Inside the C Standard Library](https://begriffs.com/posts/2019-01-19-inside-c-standard-lib.html)
 - [Unwinding the Stack](https://github.com/CppCon/CppCon2018/blob/master/Presentations/unwinding_the_stack_exploring_how_cpp_exceptions_work_on_windows/unwinding_the_stack_exploring_how_cpp_exceptions_work_on_windows__james_mcnellis__cppcon_2018.pdf) Exploring how C++ Exceptions work on Windows
 - [Unit Testing Embedded C](https://colinholzman.xyz/2020/08/22/unit-testing-embedded-c)
 - [A beginners' guide away from scanf()](http://sekrit.de/webdocs/c/beginners-guide-away-from-scanf.html)
 - [Coroutine in C Language](http://www.vishalchovatiya.com/coroutine-in-c-language/)
 - [Why I still like C and strongly dislike C++](https://codecs.multimedia.cx/2021/05/why-i-still-like-c-and-strongly-dislike-cpp/)
 - [Generic data structures in C](https://www.andreinc.net/2010/09/30/generic-data-structures-in-c)
 - [Practical Guide to Bare Metal C++](https://arobenko.github.io/bare_metal_cpp/)
 - [C++ Explained: Object initialization and assignment, lvalues and rvalues, copy and move semantics and the copy-and-swap idiom](https://katyscode.wordpress.com/2013/02/27/c-explained-object-initialization-and-assignment-lvalues-and-rvalues-copy-and-move-semantics-and-the-copy-and-swap-idiom/)
 - [C23 implications for C libraries](https://gustedt.gitlabpages.inria.fr/c23-library/)
 - [Let's write a setjmp](https://nullprogram.com/blog/2023/02/12/)
 - [The joys and perils of C and C++ aliasing, Part 1](https://developers.redhat.com/blog/2020/06/02/the-joys-and-perils-of-c-and-c-aliasing-part-1)
 - [Bounded Flexible Arrays in C](https://people.kernel.org/kees/bounded-flexible-arrays-in-c)

## Undefined behaviour

 - [Undefined behavior, and the Sledgehammer Principle](https://thephd.dev/c-undefined-behavior-and-the-sledgehammer-guideline)


## Syntax

**declarations** specify identifiers, whereas **definitions** specify objects.
An object is defined at the same time it is initialized.

 - [right-left rule](https://cseweb.ucsd.edu/~ricko/rt_lt.rule.html)
 - [Clockwise/Spiral Rule](http://c-faq.com/decl/spiral.anderson.html)

An rvalue is a temporary that does not persist beyond the expression that defines it, such as an intermediate function result which is never stored in a variable.

## Data types

There are four classes of integers, the specification 

| Name          | Minimal bits | Description |
|---------------|---------------|-------------|
| ``char``      | | Smallest addressable unit of the machine. It contains ``CHAR_BIT`` bits |
| ``short``     | 16 | |
| ``int``       | 16 | |
| ``long``      | 32 | |
| ``long long`` | 64 | |

## Control flow

The following are able to change the control flow of a program

 - ``if``/``else``
 - ``while``, ``for`` and ``do{} while ()`` i.e. loops
 - function calls
 - ``goto`` i.e. short jumps
 - ``setjmp()``/``longjmp()``/``getcontext()``/``setcontext()`` i.e. long jumps
 - interrupts and signals
 - threads

## Structs

 - [The Lost Art of Structure Packing](http://www.catb.org/esr/structure-packing/)
 - [C Structure Padding Initialization](https://interrupt.memfault.com/blog/c-struct-padding-initialization)


## Formatting

| modifier | Type     | Conversion |
|----------|----------|------------|
| "hh"     | ``char`` | integer    |
| "h"      | ``short`` | integer   |
| ""       | ``signed``,``unsigned`` | integer |
| "l"      | ``long`` | integer |
| "ll"     | ``long long`` | integer |
| "j"      | ``intmax_t``, ``uintmax_t | integer |
| "z"      | ``size_t`` | integer |
| "t"      | ``ptrdiff_t`` | integer |
| "L"      | ``long double`` | floating point |

| flag | meaning | conversion |
|------|---------|------------|
| "#"  | alternate form | "aAeEfFgGoxX" |
| "0"  | zero padding | numeric |
| "-"  | left adjustment | any |
| " "  | space for positive number | signed |
| "+"  | explicit sign for positive number | signed |

## Preprocessor

 - [C Pre-Processor Magic](http://jhnet.co.uk/articles/cpp_magic)
 - [C Preprocessor tricks, tips, and idioms](https://github.com/pfultz2/Cloak/wiki/C-Preprocessor-tricks,-tips,-and-idioms)

## Value categories

 - [value categories on cppreference.com](https://en.cppreference.com/w/cpp/language/value_category)

## Constructor

[CPP reference](https://en.cppreference.com/w/cpp/language/constructor)

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

A [default constructor](https://en.cppreference.com/w/cpp/language/default_constructor) is a constructor that either has no parameters, or if it
has parameters, all the parameters have default values.

If no user-declared constructors of any kind are provided for a class type
(struct, class, or union), the compiler will always declare a default
constructor as an inline public member of its class.

### Copy constructor

It's in the form ``Class(const Class&)``.

## Inheritance

It's possible to have multiple parent classes.

## Virtual functions

The importance of ``virtual`` keyword is that allows for **runtime polymorphism**, i.e.,
it tells the compiler to resolve the function call at runtime.

From [here](https://en.cppreference.com/w/cpp/language/virtual)

    The virtual specifier specifies that a non-static member function is virtual and
    supports dynamic dispatch. It may only appear in the decl-specifier-seq of the
    initial declaration of a non-static member function (i.e., when it is declared
    in the class definition).

    If some member function vf is declared as virtual in a class Base, and some
    class Derived, which is derived, directly or indirectly, from Base, has a
    declaration for member function with the same

    name
    parameter type list (but not the return type)
    cv-qualifiers
    ref-qualifiers

    Then this function in the class Derived is also virtual (whether or not the
    keyword virtual is used in its declaration) and overrides Base::vf (whether or
    not the word override is used in its declaration).

    Base::vf does not need to be accessible or visible to be overridden. (Base::vf
    can be declared private, or Base can be inherited using private inheritance. Any
    members with the same name in a base class of Derived which inherits Base do not
    matter for override determination, even if they would hide Base::vf during name
    lookup.)



To be noted that this specifier has to be applied to the base class, it's the
derived class that is affected though.

 - https://stackoverflow.com/questions/2391679/why-do-we-need-virtual-functions-in-c

## Virtual base class

It's possible to indicate ``virtual`` for the parent class during the declaration of a subclass.
This means [that](https://en.cppreference.com/w/cpp/language/derived_class)

    For each distinct base class that is specified virtual, the most derived object
    contains only one base class subobject of that type, even if the class appears
    many times in the inheritance hierarchy (as long as it is inherited virtual
    every time).

## Visibility

They exist three keyword

 - ``public``: anyone can access
 - ``protected``: only class and subclasses can access
 - ``private``: only the class in which is defined can access

but also exists

 - ``friend``: allows to specify methods or attributes that can access private properties

## Copying, moving, constant and references

By default, when you pass a class as an argument of a function, the copy constructor
is called for that class; to avoid that overhead you can use a ``const`` reference.

 - [Thinking in C++, 2nd ed. Volume 1/References & the Copy-Constructor](http://www.cs.ust.hk/~dekai/library/ECKEL_Bruce/TICPP-2nd-ed-Vol-one/TICPP-2nd-ed-Vol-one-html/Chapter11.html)
 - [CppCon 2019: Klaus Iglberger “Back to Basics: Move Semantics (part 2 of 2)”](https://www.youtube.com/watch?v=pIzaZbKUw2s)

An rvalue is a temporary that does not persist beyond the expression that defines it, such as an intermediate function result which is never stored in a variable.

## Operators overloading

 - [C++ Operator Overloading Guidelines](http://courses.cms.caltech.edu/cs11/material/cpp/donnie/cpp-ops.html)

## Templates

```c++
template<typename T>
class Node {
public:
 ...
}
```

The special expression ``template<>`` is called **template specialization** and allows customizing the template code for a given set of template arguments.

 - [Why templates can only be implemented in the header file](http://stackoverflow.com/questions/495021/why-can-templates-only-be-implemented-in-the-header-file)
 - https://stackoverflow.com/questions/43268146/why-is-stditerator-deprecated
 - https://softwareengineering.stackexchange.com/questions/386614/c-iterator-why-is-there-no-iterator-base-class-all-iterators-inherit-from
 - [Recursive template metaprogramming (Part I)](https://eopxd.com/2021/05/05/recursive-template-metaprogramming-part-i/)
 - [TEMPLATE METAPROGRAMMING](https://accu.org/journals/overload/9/46/walker_424/)

## Pointers-to-members

These allow to refer to non-static members of class objects (including functions).

```c++
#include <iostream>
using namespace std;

class X {
public:
  int a;
  void f(int b) {
    cout << "The value of b is "<< b << endl;
  }
};

int main() {

  // declare pointer to data member
  int X::*ptiptr = &X::a;

  // declare a pointer to member function
  void (X::* ptfptr) (int) = &X::f;

  // create an object of class type X
  X xobject;

  // initialize data member
  xobject.*ptiptr = 10;

  cout << "The value of a is " << xobject.*ptiptr << endl;

  // call member function
  (xobject.*ptfptr) (20);
}
```

The pointer to member operators ``.*`` and ``->*`` are used to bind a pointer to a
member of a specific class object. Because the precedence of ``()`` (function call
operator) is higher than ``.*`` and ``->*``, you must use parentheses to call the
function pointed to by ``ptf``.

 - [post by IBM](https://www.ibm.com/docs/en/i/7.4?topic=only-pointers-members-c)

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

### Find substring

It exists a special value ``std::string::npos``, from the [documentation](https://en.cppreference.com/w/cpp/string/basic_string/npos)

> This is a special value equal to the maximum value representable by the type
> size_type. The exact meaning depends on context, but it is generally used
> either as end of string indicator by the functions that expect a string index
> or as the error indicator by the functions that return a string index.

```c++
std::string::size_type indexU = mOpcode.find('u');

bool isUpper = (indexU != std::string::npos);
```

### Print integers using hexadecimal representation

```c++
int value = 0xbad1d34;
std::cout << std::setfill('0') <<  std::setw(8) << std::hex << value << std::endl;
```

### Links

 - [std::string copy constructor NOT deep in GCC 4.1.2?](https://stackoverflow.com/questions/16604925/stdstring-copy-constructor-not-deep-in-gcc-4-1-2)
 - [Is std::string refcounted in GCC 4.x / C++11?](https://stackoverflow.com/questions/12520192/is-stdstring-refcounted-in-gcc-4-x-c11)

## IO

```c++
#include <ifstream>

std::ifstream source("file.auaua", std::ios::in);

while (true) {
    char line[21];

    source.getline(line, 20);

    if (source.fail()) {
        break;
    }
    ...
}
```

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

## Logging

A easy way to add logging in a ``C++`` project is to use [plog](https://github.com/SergiusTheBest/plog/),
you can easily add it as a submodule

```c++
#include <plog/Log.h> /* this for all the code that needs the PLOG_* stuff */
#include <plog/Init.h> /* this only for the initialization */
#include <plog/Formatters/TxtFormatter.h>
#include <plog/Appenders/ColorConsoleAppender.h>

int main() {

    /* initialization */
    static plog::ColorConsoleAppender<plog::TxtFormatter> consoleAppender(plog::streamStdErr);
    plog::init(plog::verbose, &consoleAppender);

    /* code */

    PLOG_INFO << "reading source file '" << argv[1] << "'";
    /* code after */
}
```
