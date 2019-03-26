#pragma once
using predicate = bool (*)(const int&);
using mapper = void (*)(int&);

class IntArrayContainer {
    int* array;
    int size;
    int capacity;
    void resize();
    void copy(const IntArrayContainer&);
    void destroy();
    bool allocateMemory(const int&);
    int locate(const int&) const;
    public:
    IntArrayContainer();
    IntArrayContainer(const int& capacity);
    IntArrayContainer(const IntArrayContainer&);
    IntArrayContainer& operator =(const IntArrayContainer&);
    ~IntArrayContainer();
    bool empty() const;
    bool full() const;
    void add(const int&);
    void pop();
    int count() const;
    void remove(const int&);
    void print() const;
    bool member(const int&) const;
    int find(predicate) const;
    IntArrayContainer filter(predicate) const;
    void map(mapper);
    IntArrayContainer intersection(const IntArrayContainer&) const;
    IntArrayContainer complement(const IntArrayContainer&) const;
    IntArrayContainer unionWith(const IntArrayContainer&) const;
    IntArrayContainer operator+(const int&) const;
    void operator+=(const int&);
    IntArrayContainer operator+(const IntArrayContainer&) const;
    void operator --(int);
    operator bool() const;
};
