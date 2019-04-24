#pragma once
#include<iostream>

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
    T find(predicate<T>) const;
    ArrayContainer<T> filter(predicate<T>) const;
    void map(mapper<T>);
    ArrayContainer<T> intersection(const ArrayContainer<T>&) const;
    ArrayContainer<T> complement(const ArrayContainer<T>&) const;
    ArrayContainer<T> unionWith(const ArrayContainer<T>&) const;
    ArrayContainer<T> operator+(const T&) const;
    void operator+=(const T&);
    ArrayContainer<T> operator+(const ArrayContainer<T>&) const;
    void operator --(int);
    operator bool() const;
};

template<typename T>
bool ArrayContainer<T>::allocateMemory(const int& capacity) {
    this->array = new(std::nothrow) int[capacity];
    this->capacity = !this->array ? 0 : capacity;
    return this->array != nullptr;
}

template<typename T>
ArrayContainer<T>::ArrayContainer() {
    this->size = 0;
    this->allocateMemory(4);
}

template<typename T>
ArrayContainer<T>::ArrayContainer(const int& capacity) {
    this->size = 0;
    this->allocateMemory(capacity);
}

template<typename T>
ArrayContainer<T>::ArrayContainer(const ArrayContainer& other) {
    copy(other);
}

template<typename T>
ArrayContainer<T>& ArrayContainer<T>::operator=(const ArrayContainer& other) {
    if (this != &other) {
        destroy();
        copy(other);
    }
    return *this;
}
template<typename T>
ArrayContainer<T>::~ArrayContainer() {
    destroy();
}
template<typename T>
void ArrayContainer<T>::destroy() {
    delete [] array;
    this->array = nullptr;
    this->capacity = 0;
    this->size = 0;
}

template<typename T>
void ArrayContainer<T>::copy(const ArrayContainer& other) {
    this->size = 0;
    if (this->allocateMemory(other.capacity)) {
        this->size = other.size;
        for(int indx = 0; indx <this->size; indx++) {
            this->array[indx] = other.array[indx];
        }
    }
}

template<typename T>
void ArrayContainer<T>::resize() {
    int* tempContainer = this->array;
    int oldCapacity = this->capacity;

    if (this->allocateMemory(this->capacity*2)) {
        for(int indx = 0; indx <this->size; indx++) {
            this->array[indx] = tempContainer[indx];
        }
        delete [] tempContainer;
    } else {
        // in case we cannot allocate memory - we need to fallback to the old container and dimensions
        this->array = tempContainer;
        this->capacity = oldCapacity;
    }

}

template<typename T>
bool ArrayContainer<T>::empty() const {
    return this->size == 0;
}

template<typename T>
bool ArrayContainer<T>::full() const {
    return this->size == this->capacity;
}

template<typename T>
void ArrayContainer<T>::add(const T& elem) {
    if (full()) {
        resize();
    }
    this->array[size++] = elem;
}

template<typename T>
int ArrayContainer<T>::count() const {
    return this->size;
}

template<typename T>
void ArrayContainer<T>::pop() {
    if (!empty()) {
        this->size--;
    }
}

template<typename T>
int ArrayContainer<T>::locate(const T& elem) const {
    if (empty()) {
        return -1;
    }

    int i = 0;
    for(;i<this->size && this->array[i] != elem;i++) { }

    return i < this->size ? i : -1;
}

template<typename T>
void ArrayContainer<T>::remove(const T& elem) {
    if (this->empty()) {
        return;
    }

    int i=0;
    const int elemIndex = this->locate(elem);

    if (elemIndex != -1) {
        std::swap(this->array[i], this->array[size-1]);
        pop();
    }
}

template<typename T>
void ArrayContainer<T>::print() const {
    for(int i=0; i< this->size; i++) {
        std::cout<<this->array[i] << " ";
    }
    std::cout<< std::endl;
}

template<typename T>
bool ArrayContainer<T>::member(const T& elem) const {
    const int elementIndex = this->locate(elem);
    return elementIndex != -1;
}

//not the best solution at all
template<typename T>
T ArrayContainer<T>::find(predicate<T> p) const {
    int dummy;

    if (this->empty()) {
        return dummy;
    }

    int elemIndex = 0;
    for(;elemIndex < this->size && !p(this->array[elemIndex]); elemIndex++) {}

    // assert(elemIndex < this->size);
    int foundElement = elemIndex < this->size ? this->array[elemIndex] : dummy;
    return foundElement;
}

template<typename T>
ArrayContainer<T> ArrayContainer<T>::filter(predicate<T> p) const {
    ArrayContainer result;

    for(int i=0;i<this->size; i++) {
        if (p(this->array[i])) {
            result.add(this->array[i]);
        }
    }

    return result;
}

template<typename T>
void ArrayContainer<T>::map(mapper<T> m) {
    for(int i=0; i<this->size; i++) {
        m(this->array[i]);
    }
}

template<typename T>
ArrayContainer<T> ArrayContainer<T>::intersection(const ArrayContainer<T>& other) const {
    ArrayContainer result;

    for(int i=0; i<this->size; i++) {
        if(other.member(this->array[i]) && !result.member(this->array[i])) {
            result.add(this->array[i]);
        }
    }

    return result;
}

template<typename T>
ArrayContainer<T> ArrayContainer<T>::complement(const ArrayContainer<T>& other) const {
    ArrayContainer result;

    for(int i=0; i<this->size; i++) {
        if(!other.member(this->array[i]) && !result.member(this->array[i])) {
            result.add(this->array[i]);
        }
    }

    return result;
}

template<typename T>
ArrayContainer<T> ArrayContainer<T>::unionWith(const ArrayContainer<T>& other) const {
    ArrayContainer result;

    for(int i=0; i<this->size; i++) {
        result.add(this->array[i]);
    }

    for(int i=0; i<other.size; i++) {
        result.add(other.array[i]);
    }
    return result;
}

template<typename T>
ArrayContainer<T> ArrayContainer<T>::operator+(const T& elem) const {
    ArrayContainer result(*this);
    result.add(elem);
    return result;
}

template<typename T>
void ArrayContainer<T>::operator+=(const T& elem) {
    this->add(elem);
}

template<typename T>
ArrayContainer<T> ArrayContainer<T>::operator+(const ArrayContainer<T>& other) const {
    return this->unionWith(other);
}

template<typename T>
void ArrayContainer<T>::operator --(int) {
    this->pop();
}

template<typename T>
ArrayContainer<T>::operator bool() const {
    return !this->empty();
}