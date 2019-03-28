#include<iostream>
#include "IntArrayContainer.h"


struct student {
    int fn;
    friend std::ostream& operator <<(std::ostream& os, student& st) {
        os<<st.fn;
    }
};

// void print(int a) {
//     std::cout << a;
// }

// void print(double a) {
//     std::cout << a;
// }

// void print(student a) {
//     std::cout << a;
// }

template<typename T>
void print(T a) {
    T b;
    std::cout << b;
    std::cout << a;
}

void print(student st) {
    std::cout<<"asdf";
}

template<typename T>
T sum(T a, T b) {
    return a+b;
}

template<typename T, int K>
struct dummy {
    T a[K];
    void print(){std::cout << a;}
};

int main() {
    print<int>(3);
    print(2.14);
    student st;
    st.fn = 71004;
    print(st);
    dummy<int,10> d;
    ArrayContainer<int> c;
    // sum(st,st);
    // dummy<int, double> d;
    // dummy<double> d;
}