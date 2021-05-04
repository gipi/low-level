# C&C++

 - [cppreference.com](https://en.cppreference.com/)
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

A default constructor is a constructor that either has no parameters, or if it
has parameters, all the parameters have default values.

### Copy constructor

It's in the form ``Class(const Class&)``.

## Inheritance

It's possible to have multiple parent classes.

## virtual

 - https://stackoverflow.com/questions/2391679/why-do-we-need-virtual-functions-in-c
 - https://en.cppreference.com/w/cpp/language/virtual
 - 

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
