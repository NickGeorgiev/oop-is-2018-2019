#include "IntArrayContainer.h"
#include <iostream>

IntArrayContainer::IntArrayContainer() {
    this->capacity = 4;
    this->size = 0;
    this->array = new int [this->capacity];
}

IntArrayContainer::~IntArrayContainer() {
    destroy();
}

void IntArrayContainer::destroy() {
    delete [] array;
}
IntArrayContainer::IntArrayContainer(const IntArrayContainer& other) {
    copy(other);
}

void IntArrayContainer::copy(const IntArrayContainer& other) {
    this->capacity = other.capacity;
    this->size = other.size;
    this->array = new int [this->capacity];
    for(int indx = 0; indx <this->size; indx++) {
        this->array[indx] = other.array[indx];
    }
}

IntArrayContainer::IntArrayContainer(const int& capacity) {
    this->size = 0;
    this->capacity = capacity;
    this->array = new int [this->capacity];
}

void IntArrayContainer::resize() {
    this->capacity *= 2;
    int* tempContainer = this->array;
    this->array = new int[this->capacity];
    for(int indx = 0; indx <this->size; indx++) {
        this->array[indx] = tempContainer[indx];
    }
    delete [] tempContainer;
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

void IntArrayContainer::remove(const int& elem) {
    if (empty()) {
        return;
    }
    int i=0;
    for(;i<this->size && this->array[i] != elem;i++) { }
    std::swap(this->array[i], this->array[size-1]);
    pop();
}

void IntArrayContainer::print() const {
    for(int i=0;i< this->size; i++) {
        std::cout<<this->array[i] << " ";
    }
}
