#ifndef ARRAYLIST_H
#define ARRAYLIST_H
#include <cstdio>

#define ARRAYLIST_MIN_SIZE 16


template<typename T>
class ArrayList {
public:
    ArrayList() : ArrayList(ARRAYLIST_MIN_SIZE) {};
    ArrayList(size_t initial_size);
    ArrayList(T[], size_t size);
    T& append(T&);
private:
    T* items;
    size_t size;
    void resize();
};


template<typename T>
ArrayList<T>::ArrayList(size_t initial_size) {
    this->size = initial_size;
    this->items = new T [size];
}

template<typename T>
ArrayList<T>::ArrayList(T items[], size_t size) {
    this->size = size;
    this->items = items;
}

template<typename T>
void ArrayList<T>::resize() {
    this->size *= 2;
    this->items = realloc(this->items, sizeof(T) * this->size);
}

#endif // ARRAYLIST_H
