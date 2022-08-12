# Python

``python`` is an interpreted language, that looks a lot like pseudocode.

## Data Types

The [standard type hierarchy](https://docs.python.org/3/reference/datamodel.html#the-standard-type-hierarchy)

| Name | Description |
|------|-------------|
| ``None`` | particular type used as a null that is only representative of its type |
| ``numbers.Number`` | representation of numerical entities |



https://docs.python.org/3/library/stdtypes.html?


**container** here means that it's not limited to a single data type but can
have mixed types together. The opposite of container is **flat**.

**hashable**: object that has a hash value which never changes during its lifetime

| Name     | Description | Mutable | Container |
|----------|-------------|---------|-----------|
| ``int``, ``float`` and ``complex`` | unlimited precision numerical types | ✅ | ❌ |
| ``range`` | sequence of numbers | ❌ | ❌ |
| ``tuple``| built-in sequence | ❌ | ✅ |
| ``list`` | built-in sequence | ✅ | ✅ |
| ``str``  | text sequence | ❌ | ❌ |
| ``bytes`` | bytes sequence | ❌ | ❌ |
| ``bytearray`` | bytes sequence | ✅ | ❌ |
| ``set``  | unordered collection of hashable objects | ✅ | ✅ |
| ``frozenset``  | unordered collection of hashable objects that is hashable | ❌ | ✅ |
| ``dict`` | mapping from hashable objects to an arbitrary object | ✅ | ✅ |
| ``memoryview`` | view to internal data of objects | ❓ | ❌ |

Sequences/containers can implement a particular sub-type that is the
**iterator**: in practice you tell the external world that your object supports
iteration via the ``__iter__()`` method that returns the actual iterator.

The iterator must implement the ``__next__()`` method that returns the next
element in the sequence. When the sequence has not more element, this method
must raise ``StopIteration``.

Related to this exists the **generator** type, roughly speaking a function that
using the ``yield`` keyword allows to build an iterator. Take in mind that has
other methods other the ones from the iterator protocols, like ``send()``,
``throw()`` and ``close()``.

For example, directly from the [documentation](https://docs.python.org/3.8/reference/expressions.html#examples)

```python
>>> def echo(value=None):
...     print("Execution starts when 'next()' is called for the first time.")
...     try:
...         while True:
...             try:
...                 value = (yield value)
...             except Exception as e:
...                 value = e
...     finally:
...         print("Don't forget to clean up when 'close()' is called.")
...
>>> generator = echo(1)
>>> print(next(generator))
Execution starts when 'next()' is called for the first time.
1
>>> print(next(generator))
None
>>> print(generator.send(2))
2
>>> generator.throw(TypeError, "spam")
TypeError('spam',)
>>> generator.close()
Don't forget to clean up when 'close()' is called.

```

It exists also a **generator expression**

```python
>>> sum(i*i for i in range(10))         # sum of squares 0, 1, 4, ... 81
285
```




## Links

 - http://mirnazim.org/writings/python-ecosystem-introduction/
 - [WTF Python](https://github.com/satwikkansal/wtfpython/blob/master/README.md) Exploring and understanding Python through surprising snippets
 - [Code Like a Pythonista: Idiomatic Python](http://python.net/~goodger/projects/pycon/2007/idiomatic/handout.html)
 - http://effbot.org/zone/python-with-statement.htm
 - http://www.python.org/dev/peps/
 - http://www.mindviewinc.com/Books/Python3Patterns/Index.php
 - http://stackoverflow.com/questions/986006/python-how-do-i-pass-a-variable-by-reference
 - http://agiliq.com/blog/2012/06/understanding-args-and-kwargs/
 - http://pythonbooks.revolunet.com/
 - http://farmdev.com/talks/unicode/ ``# -*- coding: utf-8 -*-``
 - What's [__main__.py](http://stackoverflow.com/questions/4042905/what-is-main-py)
 - http://blog.amir.rachum.com/post/39501813266/python-the-dictionary-playbook
 - https://developers.google.com/edu/python/
 - Vulnerability in session cookie http://vudang.com/2013/01/python-web-framework-from-lfr-to-rce/
 - http://blog.amir.rachum.com/post/54770419679/python-common-newbie-mistakes-part-1
 - http://blog.amir.rachum.com/post/55024295793/python-common-newbie-mistakes-part-2
 - http://pypix.com/tools-and-tips/advanced-regular-expression-tips-techniques/
 - http://sebastianraschka.com/Articles/2014_python_performance_tweaks.html
 - [Parallelism in one line](https://medium.com/p/40e9b2b36148)
 - http://www.fullstackpython.com/
 - [Writing Python 2-3 compatible code](http://python-future.org/compatible_idioms.html)
 - https://github.com/faif/python-patterns
 - [Decorator cheat sheet](http://www.pydanny.com/python-decorator-cheatsheet.html)
 - https://wiki.python.org/moin/TimeComplexity
 - [Writing sustainable Python scripts](https://vincent.bernat.ch/en/blog/2019-sustainable-python-script)
 - [Why print became a function in python3](https://snarky.ca/why-print-became-a-function-in-python-3/)
 - [Python 101: iterators, generators, coroutines](https://www.integralist.co.uk/posts/python-generators/)
 - [How to Bootstrap a Python Project](https://blog.emacsos.com/bootstrap-a-python-project.html)
 - [A Practical Guide to Using Setup.py](https://godatadriven.com/blog/a-practical-guide-to-using-setup-py/)
 - [Massive memory overhead: Numbers in Python and how NumPy helps](https://pythonspeed.com/articles/python-integers-memory/)
 - [Reproducible Python Bytecode](https://vulns.xyz/2021/08/reproducible-python-bytecode/)
 - [pythontutor](https://pythontutor.com/)
 - [Less copies in Python with the buffer protocol and memoryviews]( https://eli.thegreenplace.net/2011/11/28/less-copies-in-python-with-the-buffer-protocol-and-memoryviews)

## Packaging

 - [python-packaging.readthedocs.io](https://python-packaging.readthedocs.io/)
 - http://www.scotttorborg.com/python-packaging/index.html
 - http://nvie.com/posts/pin-your-packages/
 - http://tech.marksblogg.com/better-python-package-management.html
 - [Value error](http://stackoverflow.com/questions/11536764/attempted-relative-import-in-non-package-even-with-init-py) Attempted relative import in non-package

## Typing



For python3.7+, you can indicate that the function returns an istance of the
enclosing class

```python
from __future__ import annotations

class Position:
    def __add__(self, other: Position) -> Position:
            ...
```

 - [typing documentation](https://docs.python.org/3/library/typing.html)
 - [PEP 483 - The Theory of Type Hints](https://www.python.org/dev/peps/pep-0483/)
 - [mypy](http://www.mypy-lang.org/) is an optional static type checker for Python that aims to combine the benefits of dynamic (or "duck") typing and static typin
 - [python/mypy](https://github.com/python/mypy) Optional static typing for Python 3 and 2 (PEP 484)
 - [Python: better typed than you think](https://beepb00p.xyz/mypy-error-handling.html) mypy assisted error handling, exception mechanisms in other languages, fun with pattern matching and type variance
 - [Python Typing: Resisting the Any type](https://jaredkhan.com/blog/resist-the-any-type)

## Internals

 - http://www.jeffknupp.com/blog/2013/02/14/drastically-improve-your-python-understanding-pythons-execution-model/
 - Escaping a sandbox using [magic](http://blog.delroth.net/2013/03/escaping-a-python-sandbox-ndh-2013-quals-writeup/) of python
 - http://stackoverflow.com/questions/878943/why-return-notimplmented-instead-of-raising-notimplementederror
 - Using [Cython](http://blog.perrygeo.net/2008/04/19/a-quick-cython-introduction/) to speed up
 - http://late.am/post/2012/03/26/exploring-python-code-objects
 - [We are all consenting adult here](https://mail.python.org/pipermail/tutor/2003-October/025932.html)
 - [Understanding internals of Python classes](https://rushter.com/blog/python-class-internals/)
 - [Python Descriptors Demystified](https://nbviewer.jupyter.org/urls/gist.github.com/ChrisBeaumont/5758381/raw/descriptor_writeup.ipynb)
 - [Python Attribute Access and the Descriptor Protocol](https://amir.rachum.com/blog/2019/10/16/descriptors/)
 - [How python implements long integers?](https://arpitbhayani.me/blogs/super-long-integers)
 - [open and CPython](http://hondu.co/blog/open-and-python)
 - [Python behind the scenes #7: how Python attributes work](https://tenthousandmeters.com/blog/python-behind-the-scenes-7-how-python-attributes-work/)

## Metaclass

 - What's a metaclasse by [stackoverflow](http://stackoverflow.com/questions/100003/what-is-a-metaclass-in-python)
 - http://www.slideshare.net/hychen/what-can-meta-class-do-for-you-pycon-taiwan-2012
 - http://www.slideshare.net/gwiener/metaclasses-in-python

## TESTS

 - [My Python testing style guide](https://blog.thea.codes/my-python-testing-style-guide/)
 - https://www.youtube.com/watch?v=wWu_iRuBjKs
 - https://www.integralist.co.uk/posts/toxini/
 - [moto](https://github.com/spulec/moto), a library that allows you to easily mock out tests based on AWS infrastructure.
 - [Testing Python Applications with Pytest](https://stribny.name/blog/pytest/)

### pytest

```python
@pytest.mark.parametrize('count', [
    0, 1, 6, 17,
])
def test_tree42(count):
    values = list(range(count))

    bt = XBinarySearchTree.from_array(values)

    assert list(bt.inorder_traversal()) == values
```

## BEST PRACTICES

 - [PEP8](http://www.python.org/dev/peps/pep-0008/): Style Guide for Python Code
 - [Design pattern](http://ginstrom.com/scribbles/2007/10/08/design-patterns-python-style/) in python
 - ``dict()`` [vs](http://www.doughellmann.com/articles/misc/dict-performance/index.html) ``{}`` (hint: ``{}`` is better)
 - http://excess.org/article/2011/12/unfortunate-python/
 - http://www.canonical.org/~kragen/isinstance/
 - http://www.artima.com/weblogs/viewpost.jsp?thread=236278
 - http://satyajit.ranjeev.in/2012/05/17/python-a-few-things-to-remember.html
 - http://net.tutsplus.com/tutorials/python-tutorials/behavior-driven-development-in-python/
 - [Things you didn't know about Python](https://speakerdeck.com/u/mitsuhiko/p/didntknow): interesting presentation about Python internal and stuff.
 - [Copying list, the right way](http://henry.precheur.org/python/copy_list)
 - Make [one archive](http://blog.ablepear.com/2012/10/bundling-python-files-into-stand-alone.html) python executable
 - [HOWTO Create Python GUIs using HTML](http://www.aclevername.com/articles/python-webgui/)
 - [Slides](http://ua.pycon.org/static/talks/kachayev/) about functional versus imperative programming
 - MRO: from [official](http://www.python.org/download/releases/2.3/mro/) documentation and a [post](http://nedbatchelder.com/blog/201210/multiple_inheritance_is_hard.html) about **multiple inheritance** (look at also the comments)
 - http://ozkatz.github.com/improving-your-python-productivity.html
 - http://ozkatz.github.com/better-python-apis.html
 - [Lazy](http://fulmicoton.com/posts/lazy/) evaluation
 - https://speakerdeck.com/rwarren/a-brief-intro-to-profiling-in-python
 - http://pyvideo.org/video/1674/getting-started-with-automated-testing
 - http://hynek.me/talks/python-deployments/
 - http://pyrandom.blogspot.nl/2013/04/super-wrong.html
 - [Python’s super() considered super!](https://rhettinger.wordpress.com/2011/05/26/super-considered-super/)
 - http://www.huyng.com/posts/python-performance-analysis/
 - https://tommikaikkonen.github.io/timezones/
 - [format()](https://zerokspot.com/weblog/2015/12/31/new-string-formatting-in-python/)
 - [pyformat.info/](https://pyformat.info/)

## Multithreading&Multiprocessing

 - [Visualize multi-threaded Python programs with an open source tool](https://opensource.com/article/21/3/python-viztracer)

## Exceptions

 - [Exception](http://www.jeffknupp.com/blog/2013/02/06/write-cleaner-python-use-exceptions/) in python make code clearer, see also [this](https://speakerdeck.com/pyconslides/how-to-except-when-youre-excepting-by-esther-nam).
 - https://julien.danjou.info/blog/2015/python-retrying
 - [Reraising exception](http://blog.ionelmc.ro/2014/08/03/the-most-underrated-feature-in-python-3/)


## LIBRARIES

 - https://github.com/kennethreitz/envoy
 - https://github.com/kennethreitz/requests
 - http://www.nicosphere.net/clint-command-line-library-for-python/
 - [Docopts](https://github.com/docopt/docopts) command line arguments parser for Human Beings.
 - [Get started with the Natural Language Toolkit](http://www.ibm.com/developerworks/linux/library/l-cpnltk/index.html)
 - [pdb++](https://github.com/pdbpp/pdbpp) pdb++, a drop-in replacement for pdb (the Python debugger)
 - [napari/napari](https://github.com/napari/napari) a fast, interactive, multi-dimensional image viewer for python
 - [pydantic](https://pydantic-docs.helpmanual.io/) Data validation and settings management using python type annotations.
 - [pySDR](https://pysdr.org/)

## Scientific

 - [NumPy Illustrated: The Visual Guide to NumPy](https://medium.com/better-programming/numpy-illustrated-the-visual-guide-to-numpy-3b1d4976de1d)
 - [Scipy Lecture Notes](http://scipy-lectures.org/)
 - [Panda's Hierarchical Indexing](https://jakevdp.github.io/PythonDataScienceHandbook/03.05-hierarchical-indexing.html)
 - [Panda's Indexing and selecting data](https://pandas.pydata.org/pandas-docs/stable/user_guide/indexing.html)

## Interesting Stuffs

 - https://jordan-wright.github.io/blog/2014/10/06/creating-tor-hidden-services-with-python/

## SANDBOX

 - http://wiki.python.org/moin/Asking%20for%20Help/How%20can%20I%20run%20an%20untrusted%20Python%20script%20safely%20%28i.e.%20Sandbox%29
 - [Example](http://readevalprint.com/blog/python-sandbox-with-pypy-part2.html) of pypy-c-sandbox for launching random scripts
 - http://stackoverflow.com/questions/6655258/using-the-socket-module-in-sandboxed-pypy
 - http://pypy.readthedocs.org/en/latest/sandbox.html
 - http://blog.delroth.net/2013/03/escaping-a-python-sandbox-ndh-2013-quals-writeup/

Instructions for ``pypy-2.1``

```
$ cd pypy/goal
$ python ../../rpython/bin/rpython  -O2 --sandbox targetpypystandalone.py
$ PYTHONPATH=$PYTHONPATH:$PWD/../../ ../..//pypy/sandbox/pypy_interact.py pypy-c
```

## DEBUG&Profiling

 - [Performance analysis](https://www.huyng.com/posts/python-performance-analysis)
 - [CProfile](https://julien.danjou.info/blog/2015/guide-to-python-profiling-cprofile-concrete-case-carbonara)
 - https://stripe.com/blog/exploring-python-using-gdb
 - [scalene](https://github.com/emeryberger/scalene) is a high-performance CPU and memory profiler for Python that does a number of things that other Python profilers do not and cannot do

## IDE

 - http://blog.dispatched.ch/2009/05/24/vim-as-python-ide/


```
$ python -m shlex
kdkd
Token: 'kdkd'
34 5455
Token: '34'
Token: '5455'
$edx=34
Token: '$'
Token: 'edx'
Token: '='
Token: '34'
```
## Time

 - http://www.saltycrane.com/blog/2008/11/python-datetime-time-conversions/
 - http://stackoverflow.com/questions/2775864/python-datetime-to-unix-timestamp

## COOKBOOK

```python
>>> a = [1,4,-1,0,13]
>>> a.sort()
>>> a
[-1, 0, 1, 4, 13]
>>> import operator
>>> x = {1: 2, 3: 4, 4:3, 2:1, 0:0}
>>> sorted_x = sorted(x.iteritems(), key=operator.itemgetter(1))
```

### Two's complement

```python
>>> value = 0xb59395a9
>>> f"{ctypes.c_uint32(value).value:032b}"
'10110101100100111001010110101001'
>>> f"{ctypes.c_uint32(~value).value:032b}"
'01001010011011000110101001010110'

```

### Getopt

```
import getopt, sys

def main():
    try:
        opts, args = getopt.getopt(sys.argv[1:], "ho:v", ["help", "output="])
    except getopt.GetoptError as err:
        # print help information and exit:
        print(err) # will print something like "option -a not recognized"
        usage()
        sys.exit(2)
    output = None
    verbose = False
    for o, a in opts:
        if o == "-v":
            verbose = True
        elif o in ("-h", "--help"):
            usage()
            sys.exit()
        elif o in ("-o", "--output"):
            output = a
        else:
            assert False, "unhandled option"
    # ...

if __name__ == "__main__":
    main()
```

### argparse

```python
def argparse_vendor_product(value):
    vendor, product = tuple(value.split(":"))

    return int(vendor, 16), int(product, 16)


def parse_args():
    args = argparse.ArgumentParser(description='upload and run some code')

    args.add_argument(
        '--device',
        type=argparse_vendor_product,
        required=True,
        help="vendor:product of the device you want to interact with")
    args.add_argument('--binary', required=True)
    args.add_argument('--address', type=functools.partial(int, base=0))

    return args.parse_args()
```

### PySerial

 - [documentation](https://pyserial.readthedocs.io/en/latest/)

```python
import serial
ser = serial.Serial('/dev/ttyUSB0')  # open serial port
print(ser.name)         # check which port was really used
ser.write(b'hello')     # write a string
ser.close()
```

### Decorator

```python
def trace(f):
    def _inner(*args, **kwargs):
        print ' # ', f.func_name
        return f(*args, **kwargs)
    return _inner

def challenge(count):
    def _challenge(x):
        def _inner(*args, **kwargs):
            print('[+] challenge %d' % count)
            return x(*args, **kwargs)
        return _inner
    return _challenge
```

### DOCTESTS

```python
def decript(cipher, key):
    """
    >>> a = [0, 1, 0, 1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1]
    >>> b = [1, 1, 1, 1, 1, 1, 1]
    >>> decript(a, b) #doctest: +NORMALIZE_WHITESPACE
    [[1, 0, 1, 0, 1, 0, 1],
    [0, 0, 0, 0, 0, 0, 0]]
    """
    r = []
    for i in xrange(0, len(cipher) - len(key) + 1, 7):
        r.append(XOR(cipher[i:i + len(key)], key))

    return r
```

```
$ python -m doctest c1.py
```

### SPHINX

It's possible to write the documentation along with the code.

 http://sphinx.pocoo.org/markup/toctree.html#toctree-directive


- https://wiki.python.org/moin/TimeComplexity

### Maximum float

[Source](http://stackoverflow.com/questions/3477283/maximum-float-in-python):

```python
>>> infinity = float("inf")
>>> infinity
inf
>>> infinity / 10000
inf
```

Print out some docstring for documentation purpose

    python -c 'from macro import matrixify;print(matrixify.__doc__.replace("\n    ", "\n"))' | rst2html

## Logging

 - [Documentation](https://docs.python.org/3.1/library/logging.html)
 - http://victorlin.me/2012/08/good-logging-practice-in-python/
 - http://hynek.me/articles/taking-some-pain-out-of-python-logging/
 - [Multi line formatting](https://fruch.github.io/2014/11/06/taming-the-logging-formatter/)


 - http://victorlin.me/posts/2012/08/26/good-logging-practice-in-python

Remember that ``logger.basicConfig()`` attaches the stream handler by default, if you want
to fine tune the logging you have to set it by yourself.

```python
import logging
import os

logging.basicConfig()
logger = logging.getLogger(__name__)
logger.setLevel(os.getenv("LOG") or "INFO")
```

It's possible to define a custom level
like ``SUBDEBUG`` (http://stackoverflow.com/a/16955098/1935366)

```python
import logging

SUBDEBUG = 5
logging.addLevelName(SUBDEBUG, 'SUBDEBUG')

def subdebug(self, message, *args, **kws):
    self.log(SUBDEBUG, message, *args, **kws) 
logging.Logger.subdebug = subdebug

logging.basicConfig()
l = logging.getLogger()
l.setLevel(SUBDEBUG)
l.subdebug('test')
l.setLevel(logging.DEBUG)
l.subdebug('test')

stream = logging.StreamHandler()
formatter = logging.Formatter('%(levelname)s - %(filename)s:%(lineno)d - %(message)s')

logger = logging.getLogger(__file__)
logger.setLevel(logging.DEBUG)
logger.addHandler(stream)
stream.setFormatter(formatter)
```

If you want that your logging string impact performance when the level is not
used you should let the logger itself doing the formatting: the various logging
functions accept a format string with the ``%`` style and a list of positional
arguments like

```python
logger.debug("this is a string: '%s'", string_to_log)
```

## Flatten list

```python
>>> chain = itertools.chain.from_iterable([[1,2],[3],[5,89],[],[6]])
>>> print(list(chain))
>>> [1, 2, 3, 5, 89, 6]
```

```python
for x in s:
  if x:
      return True
return False

return any(x)
```


## Traceback

```python
    try:
        _manage_object(pk, *args, **kwargs)
    except:
        obj = Object.objects.get(pk=pk)
        # get the exception context to reuse later
        exc_info = sys.exc_info()
        import traceback
        print traceback.print_tb(exc_info[2])

```

## Read/write UTF8 files

Seems like that the builtin ``open()`` in python manage only ``ascii`` files

```python
import codecs

def create_post(filepath, content):
    with codecs.open(filepath, 'w+', encoding='utf-8') as f:
        f.write(content)
```

## Get first item of a nested list

```
>>> from operator import itemgetter
>>> rows = [(1, 2), (3, 4), (5, 6)]
>>> map(itemgetter(1), rows)
[2, 4, 6]
>>>
```

## Extract URL from string

```python
import re

myString = "This is my tweet check it out http://tinyurl.com/blah"

print re.search("(?P<url>https?://[^\s]+)", myString).group("url")
```

## Routing from REGEXs

```
In [1]: import re

In [2]: c = re.compile(r'^w::(?P<type>\w+)::(?P<id>\d*)::')

In [3]: s = 'w::w::1::'

In [5]: m = c.match(s)

In [6]: m.groupdict()
Out[6]: {'id': '1', 'type': 'w'}
```

## Add file into a tarfile from a string

```python
def elaborate_archive(filepath, **kwargs):
    tar_src = tarfile.open(filepath, mode='a')

    version_file = StringIO.StringIO(kwargs['version'])

    version_tarinfo = tarfile.TarInfo('VERSION')
    version_tarinfo.size = len(version_file.buf)
    tar_src.addfile(version_tarinfo, version_file)
    tar_src.close()

```

## ``pandas``

```
$ pip install pandas
```

```python
import pandas as pd
```

You can read data from a ``CSV``

```python
df = pd.read_csv("/path/to/data")
```

or create manually one

```python
df = pd.DataFrame({
    "column 1": [data1, data2, ..., dataN],
    "column 2": [...],
    ...
})
```

To have general information about the ``DataFrame``

```python
df.info()
```

A nice feature is the filtering

```python
df[(df.duration > = 200) & (df.genre == "Drama")]
```

It's possible to plot directly

```python
df.plot(x='GE', y=['TOTALE_19', 'TOTALE_20'], figsize=(20, 10))
```
