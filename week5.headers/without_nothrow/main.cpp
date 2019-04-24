#include "IntArrayContainer.h"
#include<iostream>

 int main() {
    IntArrayContainer a; // a -> 4 el
    IntArrayContainer b(20); // b -> 20 el

     for(int i=0;i<10;i++) {
        a.add(i);
    }

     std::cout<<a.count()<<std::endl;
    a.print();
} 