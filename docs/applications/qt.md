# Qt

## main()

```
int main(int argc, char* argv[]) {
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
```

## GUI

## Graphics

## Custom widget

The default size for a ``QWidget`` is 640x480, ``sizeHint()`` and
``minimumSizeHint()`` return a ``QSize``, a "recommended" size for it.

It exists also a **size policy** that indicates the horizontal/vertical size
for the widget; ``QWidget``, ``QDialog``, ``QMainWindow`` have a
``QSizePolicy::Preferred`` policy, which means the instance can be expanded
or shrunk freely in a layout.

## Links

 - [Writing Unit Tests](https://wiki.qt.io/Writing_Unit_Tests)
 - Qt test framework [slide](https://www.slideshare.net/ICSinc/qt-test-framework)
 - [qmake Project Files](https://doc.qt.io/archives/qt-4.8/qmake-project-files.html)
 - [qmake Language](https://doc.qt.io/qt-5/qmake-language.html)
