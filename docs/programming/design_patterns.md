# Design patterns

From [Basics of the Unix Philosophy](http://catb.org/~esr/writings/taoup/html/ch01s06.html)

    The only way to write complex software that won't fall on its face is to hold
    its global complexity down — to build it out of simple parts connected by
    well-defined interfaces, so that most problems are local and you can have some
    hope of upgrading a part without breaking the whole.

 - [Design patterns by refactoring guru](https://refactoring.guru/design-patterns/)
 - [The caching antipattern](https://www.hidefsoftware.co.uk/2016/12/25/the-caching-antipattern/)
 - [Inversion of Control Containers and the Dependency Injection pattern](http://martinfowler.com/articles/injection.html)
 - Principle of last astonishment and python by [Armin Ronacher](http://lucumr.pocoo.org/2011/7/9/python-and-pola/)
 - http://en.wikipedia.org/wiki/Convention_over_configuration
 - Single responsability principle [pdf](http://www.objectmentor.com/resources/articles/srp.pdf): THERE SHOULD NEVER BE MORE THAN ONE REASON FOR A CLASS TO CHANGE.
 - http://12factor.net/
 - http://me.veekun.com/blog/2013/03/03/the-controller-pattern-is-awful-and-other-oo-heresy/
 - http://en.wikipedia.org/wiki/Magic_(programming)

 - https://www.ida.liu.se/~chrke55/courses/SWE/intro-uml-designpatterns.pdf

 inheritance vs object composition

 - **Aggregation:** object A contains objects B; B can live without A.
 - **Composition:** object A consists of objects B; A manages life cycle of B; B can’t live without A.

## Creational

How objects can be created.

### Abstract factory

### Builder

In this pattern you build an object step by step.  Its primary scope
it's to avoid gigantic constructors (with a lot of arguments).

### Factory method

Factory Method is a creational design pattern that provides an interface for
creating objects in a superclass, but allows subclasses to alter the type of
objects that will be created.

### Prototype

It creates objects via cloning.

### Singleton

It creates, enforces and provides the existence of a single instance of a specific class

## Structural

How to form larger structures.

### Adapter

This is a structural design pattern that allows objects with incompatible interfaces to collaborate.

### Bridge

Decouples an abstraction from its implementation so that the two can vary
indipendently. At first look could appear that is equal to **dependency injection**
but [you could consider it a Software Architecture Pattern (but still not a
design one), in the sense that it's a common way of addressing a series of
Architectural concerns (testability, configurability, modularity,
etc).](https://stackoverflow.com/questions/18540645/bridge-pattern-vs-dependency-injection)

Bridge also allows both sides on the bridge to evolve and change independently
without affecting the other. This is because the Bridge isolates both sides
from each other. A particular case could be the [PIMPL
idiom](https://www.bfilipek.com/2018/01/pimpl.html) [a way of hiding the
implementation, primarily to break compilation
dependencies](https://stackoverflow.com/questions/2346163/pimpl-idiom-vs-bridge-design-pattern)

### Composite

In a model with a tree-like structure you can use this pattern where you compose
the single components together.

### Decorator

Wraps the object with new behaviours. In practice you are adding a layer
in front of the original object.

### Facade

It simplifies the interface used to interact with a set of models.

### Flyweight

Factorizes repeated instances.

Similar to composition but here the sharing is the principal point of the pattern.
Like singleton but the flyweight is unmutable.

### Proxy

It is a design pattern that lets you provide a substitute or
placeholder for another object. A proxy controls access to the original object,
allowing you to perform something either before or after the request gets
through to the original object.


## Behavioural

How responsabilities can be assigned to objects.

### Chain-of-responsabilities

It lets you pass requests along a chain of handlers. Upon receiving a request,
each handler decides either to process the request or to pass it to the next
handler in the chain.
