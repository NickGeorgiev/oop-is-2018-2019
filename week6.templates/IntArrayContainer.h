#pragma once
template<typename T>
using predicate = bool (*)(const T&);

template<typename T>
using mapper = void (*)(T&);

template<typename T>
class ArrayContainer {
    T* array;
    int size;
    int capacity;
    void resize();
    void copy(const ArrayContainer&);
    void destroy();
    bool allocateMemory(const int&);
    int locate(const T&) const;
    public:
    ArrayContainer();
    ArrayContainer(const int& capacity);
    ArrayContainer(const ArrayContainer<T>&);
    ArrayContainer<T>& operator =(const ArrayContainer<T>&);
    ~ArrayContainer();
    bool empty() const;
    bool full() const;
    void add(const T&);
    void pop();
    int count() const;
    void remove(const T&);
    void print() const;
    bool member(const T&) const;
    T find(predicate) const;
    ArrayContainer<T> filter(predicate) const;
    void map(mapper);
    ArrayContainer<T> intersection(const ArrayContainer<T>&) const;
    ArrayContainer<T> complement(const ArrayContainer<T>&) const;
    ArrayContainer<T> unionWith(const ArrayContainer<T>&) const;
    ArrayContainer<T> operator+(const T&) const;
    void operator+=(const T&);
    ArrayContainer<T> operator+(const ArrayContainer<T>&) const;
    void operator --(int);
    operator bool() const;
};
