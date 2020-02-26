#ifndef ARRAYLIST_H
#define ARRAYLIST_H
#include <cstdio>
#include <cstring>

#define ARRAYLIST_MIN_SIZE 16


template<typename T>
class ArrayList {
public:
    ArrayList() : ArrayList(ARRAYLIST_MIN_SIZE) {};
    ArrayList(size_t initial_size);
    ArrayList(T[], size_t size);
    ~ArrayList();
    void append(const T&);
protected:
    T* items;
    size_t size;
    size_t max_size;
private:
    void resize();
};


template<typename T>
ArrayList<T>::ArrayList(size_t initial_size) {
    this->size = 0;
    this->max_size = initial_size;
    this->items = new T [this->max_size];
}

template<typename T>
ArrayList<T>::ArrayList(T items[], size_t size) {
    this->size = size;
    this->max_size = size;
    this->items = new T [size];
    memcpy(this->items, items, sizeof(T) * size);
}

template<typename T>
ArrayList<T>::~ArrayList() {
    delete [] items;
}

template<typename T>
void ArrayList<T>::append(const T& element) {
    if (this->size == this->max_size) {
        resize();
    }
    items[size++] = element;
}

template<typename T>
void ArrayList<T>::resize() {
    this->max_size *= 2;
    this->items = (T*)realloc(this->items, sizeof(T) * this->max_size);
}

#endif // ARRAYLIST_H
