#include "IntArrayContainer.h"
#include <iostream>

bool IntArrayContainer::allocateMemory(const int& capacity) {
    this->array = new(std::nothrow) int[capacity];
    this->capacity = !this->array ? 0 : capacity;
    return this->array != nullptr;
}

IntArrayContainer::IntArrayContainer() {
    this->size = 0;
    this->allocateMemory(4);
}


IntArrayContainer::IntArrayContainer(const int& capacity) {
    this->size = 0;
    this->allocateMemory(capacity);
}


IntArrayContainer::IntArrayContainer(const IntArrayContainer& other) {
    copy(other);
}

IntArrayContainer& IntArrayContainer::operator=(const IntArrayContainer& other) {
    if (this != &other) {
        destroy();
        copy(other);
    }
    return *this;
}

IntArrayContainer::~IntArrayContainer() {
    destroy();
}

void IntArrayContainer::destroy() {
    delete [] array;
    this->array = nullptr;
    this->capacity = 0;
    this->size = 0;
}

void IntArrayContainer::copy(const IntArrayContainer& other) {
    this->size = 0;
    if (this->allocateMemory(other.capacity)) {
        this->size = other.size;
        for(int indx = 0; indx <this->size; indx++) {
            this->array[indx] = other.array[indx];
        }
    }
}

void IntArrayContainer::resize() {
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

bool IntArrayContainer::empty() const {
    return this->size == 0;
}

bool IntArrayContainer::full() const {
    return this->size == this->capacity;
}

void IntArrayContainer::add(const int& elem) {
    if (full()) {
        resize();
    }
    this->array[size++] = elem;
}

int IntArrayContainer::count() const {
    return this->size;
}

void IntArrayContainer::pop() {
    if (!empty()) {
        this->size--;
    }
}

int IntArrayContainer::locate(const int& elem) const {
    if (empty()) {
        return -1;
    }

    int i = 0;
    for(;i<this->size && this->array[i] != elem;i++) { }

    return i < this->size ? i : -1;
}

void IntArrayContainer::remove(const int& elem) {
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

void IntArrayContainer::print() const {
    for(int i=0; i< this->size; i++) {
        std::cout<<this->array[i] << " ";
    }
    std::cout<< std::endl;
}

bool IntArrayContainer::member(const int& elem) const {
    const int elementIndex = this->locate(elem);
    return elementIndex != -1;
}

//not the best solution at all
int IntArrayContainer::find(predicate p) const {
    int dummy;

    if (this->empty()) {
        return dummy;
    }

    int elemIndex = 0;
    for(;elemIndex < this->size && !p(this->array[elemIndex]); elemIndex++) {}

    int foundElement = elemIndex < this->size ? this->array[elemIndex] : dummy;
    return foundElement;
}

IntArrayContainer IntArrayContainer::filter(predicate p) const {
    IntArrayContainer result;

    for(int i=0;i<this->size; i++) {
        if (p(this->array[i])) {
            result.add(this->array[i]);
        }
    }

    return result;
}

void IntArrayContainer::map(mapper m) {
    for(int i=0; i<this->size; i++) {
        m(this->array[i]);
    }
}

IntArrayContainer IntArrayContainer::intersection(const IntArrayContainer& other) const {
    IntArrayContainer result;

    for(int i=0; i<this->size; i++) {
        if(other.member(this->array[i]) && !result.member(this->array[i])) {
            result.add(this->array[i]);
        }
    }

    return result;
}

IntArrayContainer IntArrayContainer::complement(const IntArrayContainer& other) const {
    IntArrayContainer result;

    for(int i=0; i<this->size; i++) {
        if(!other.member(this->array[i]) && !result.member(this->array[i])) {
            result.add(this->array[i]);
        }
    }

    return result;
}

IntArrayContainer IntArrayContainer::unionWith(const IntArrayContainer& other) const {
    IntArrayContainer result;

    for(int i=0; i<this->size; i++) {
        result.add(this->array[i]);
    }

    for(int i=0; i<other.size; i++) {
        result.add(other.array[i]);
    }
    return result;
}

IntArrayContainer IntArrayContainer::operator+(const int& elem) const {
    IntArrayContainer result(*this);
    result.add(elem);
    return result;
}

void IntArrayContainer::operator+=(const int& elem) {
    this->add(elem);
}

IntArrayContainer IntArrayContainer::operator+(const IntArrayContainer& other) const {
    return this->unionWith(other);
}

void IntArrayContainer::operator --(int) {
    this->pop();
}

IntArrayContainer::operator bool() const {
    return !this->empty();
}