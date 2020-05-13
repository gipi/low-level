# Build systems

## Make

 - [Makefile implicit variables](https://www.gnu.org/software/make/manual/html_node/Implicit-Variables.html)

### Variables

 - ``LDFLAGS``: Extra flags to give to compilers when they are supposed to invoke the
linker, ld, such as -L. Libraries (-lfoo) should be added to the LDLIBS
variable instead.

 - ``LDLIBS``: Library flags or names given to compilers when they are supposed to
invoke the linker, ld. LOADLIBES is a deprecated (but still supported)
alternative to LDLIBS. Non-library linker flags, such as -L, should go in the
LDFLAGS variable.

## CMake

```
$ CC=gcc CXX=g++ cmake ..
```
