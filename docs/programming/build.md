# Build systems

## Make

 - [Makefile implicit variables](https://www.gnu.org/software/make/manual/html_node/Implicit-Variables.html)

### Targets

From the documentation are indicated some [standard targets](https://www.gnu.org/software/make/manual/html_node/Standard-Targets.html)
like ``all``, ``install``, ``clean`` etc...

The default target (when one is not indicated) is the first defined in the
``Makefile`` if ``.DEFAULT_GOAL`` is not set.

A particular type of target is a [phony target](https://www.gnu.org/software/make/manual/html_node/Phony-Targets.html),
i.e. a target that doesn't reflect an actual file on the filesystem.

The syntax of a target is the following

```
<targets>: <normal-prerequisites> | <order-only-prerequisites>
```

### Variables

Exists **substitution references** (see
[doc](https://www.gnu.org/software/make/manual/html_node/Substitution-Refs.html))in
the form of ``$(var:a=b)`` where the value of the variable ``var`` has the
occurrence of the ``a`` at the end of it replaced with ``b``; for example
``$(SOURCE:%.c=%.o)`` is the quick way to obtain the corresponding derived object
filename from source files.

#### Automatic variables

See [doc](https://www.gnu.org/software/make/manual/html_node/Automatic-Variables.html):

 - ``$@``: target
 - ``$<``: first prerequisite
 - ``$?``: all prerequisites newer than the target
 - ``$^``: all the prerequisites (listed only one each)
 - ``$+``: all the prerequisites (listed multiple time if it's the case)
 - ``$|``: all the order-only prerequisites
 - ``$*``: the stem with which an implicit rule matches

#### Predefined variables

There are a certain number of variables that you can use into predefined target
rules, like compiling ``C`` code and so on.

 - ``LDFLAGS``: Extra flags to give to compilers when they are supposed to invoke the
linker, ld, such as -L. Libraries (-lfoo) should be added to the LDLIBS
variable instead.

 - ``LDLIBS``: Library flags or names given to compilers when they are supposed to
invoke the linker, ld. LOADLIBES is a deprecated (but still supported)
alternative to LDLIBS. Non-library linker flags, such as -L, should go in the
LDFLAGS variable.

```Makefile
# http://www.cmcrossroads.com/article/self-documenting-makefiles
help:
	@echo $(if $(need-help),,Type \'$(MAKE)$(dash-f) help\' to get help)
.DEFAULT_GOAL=help

need-help := $(filter help,$(MAKECMDGOALS))

define print-help
$(if $(need-help),$(warning $1 -- $2))
endef

define last-element
$(word $(words $1),$1)
endef

this-makefile := $(call last-element,$(MAKEFILE_LIST))
other-makefiles := $(filter-out $(this-makefile),$(MAKEFILE_LIST))
parent-makefile := $(if other-makefiles,,$(call last-element,$(other-makefiles)))

dash-f := $(if $(filter-out Makefile makefile GNUmakefile,$(parent-makefile)), -f $(parent-makefile))
```

## CMake

```
$ CC=gcc CXX=g++ cmake ..
```

It's possible to indicate variable like the following

```
$ cmake -DUSE_QT5=1 -DCMAKE_BUILD_TYPE=Debug ..
```

If you want a verbose output for the Makefile generated, you can use
``make VERBOSE=1``
