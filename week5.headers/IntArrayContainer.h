
#pragma once
class IntArrayContainer {
    int* array;
    int size;
    int capacity;
    void resize();
    void copy(const IntArrayContainer&);
    void destroy();
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
};
