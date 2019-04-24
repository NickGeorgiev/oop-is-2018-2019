#include<iostream>
#include "ArrayContainer.h"


void logMessage(const char* message) {
    std::cout << message <<std::endl;
}

bool isOdd(const int& elem) {
    return elem %2 != 0;
}

template<typename T>
void containerTests() {
    {
        logMessage("Calling default constructor and print data: ");
        ArrayContainer<T> initialObject;
        initialObject.print();
        logMessage("\n");
    }

    {
        logMessage("Calling copy constructor and print data: ");
        ArrayContainer<T> initialObject;
        ArrayContainer<T> copyObject(initialObject);
        copyObject.print();
        logMessage("\n");
    }

    {
        logMessage("Calling params constructor and print data: ");
        ArrayContainer<T> paramObject(10);
        paramObject.print();
        logMessage("\n");
    }

    {
        logMessage("Calling assignment operator and print data: ");
        ArrayContainer<T> initialObject;
        ArrayContainer<T> assignedObject(10);
        assignedObject = initialObject;
        assignedObject.print();
        logMessage("\n");
    }

    {
        logMessage("Calling empty method: ");
        ArrayContainer<T> initialObject;
        std::cout << initialObject.empty();
        logMessage("\n");
    }

    {
        logMessage("Calling full method: ");
        ArrayContainer<T> initialObject;
        std::cout << initialObject.full();
        logMessage("\n");
    }

    {
        logMessage("Calling add method: ");
        ArrayContainer<T> initialObject;
        initialObject.add(1);
        initialObject.print();
        logMessage("\n");
    }

    {
        logMessage("Calling pop method: ");
        ArrayContainer<T> initialObject;
        initialObject.add(1);
        initialObject.add(2);
        initialObject.print();
        initialObject.pop();
        initialObject.print();
        logMessage("\n");
    }

    {
        logMessage("Calling count method: ");
        ArrayContainer<T> initialObject;
        initialObject.add(1);
        initialObject.add(2);
        std::cout << initialObject.count();
        logMessage("\n");
    }

    {
        logMessage("Calling remove method: ");
        ArrayContainer<T> initialObject;
        initialObject.add(2);
        initialObject.add(3);
        initialObject.print();
        initialObject.remove(2);
        initialObject.print();
        logMessage("\n");
    }

    {
        logMessage("Calling member method: ");
        ArrayContainer<T> initialObject;
        initialObject.add(3);
        std::cout << initialObject.member(2);
        logMessage("\n");
    }

    {
        logMessage("Calling find method: ");
        ArrayContainer<T> initialObject;
        initialObject.add(3);
        initialObject.print();
        std::cout << initialObject.find(&isOdd);
        logMessage("\n");
    }

    {
        logMessage("Calling filter method: ");
        ArrayContainer<T> initialObject;
        initialObject.add(2);
        initialObject.add(3);
        initialObject.add(4);
        initialObject.print();
        ArrayContainer<T> filteredData = initialObject.filter(&isOdd);
        filteredData.print();
        logMessage("\n");

    }

    {
        logMessage("Calling map method: ");
        ArrayContainer<T> initialObject;
        initialObject.add(2);
        initialObject.add(3);
        initialObject.add(4);
        initialObject.print();
        initialObject.map([] (int& elem)->void {elem += 1;});
        initialObject.print();
        logMessage("\n");

    }

    {
        logMessage("Calling intersection method: ");
        ArrayContainer<T> initialObject;
        initialObject.add(1);
        initialObject.add(2);
        initialObject.add(20);
        initialObject.print();
        ArrayContainer<T> second;
        second.add(20);
        second.add(22);
        second.print();

        ArrayContainer<T> intersected = initialObject.intersection(second);
        intersected.print();
        logMessage("\n");
    }

    {
        logMessage("Calling complement method: ");
        ArrayContainer<T> initialObject;
        initialObject.add(1);
        initialObject.add(2);
        initialObject.add(22);
        initialObject.print();
        ArrayContainer<T> second;
        second.add(20);
        second.add(22);
        second.print();

        ArrayContainer<T> complemented = initialObject.complement(second);
        complemented.print();
        logMessage("\n");
    }

    {
        logMessage("Calling unionWith method: ");
        ArrayContainer<T> initialObject;
        initialObject.add(22);
        initialObject.print();
        ArrayContainer<T> second;
        second.add(20);
        second.add(22);
        second.print();

        ArrayContainer<T> united = initialObject.unionWith(second);
        united.print();
        logMessage("\n");
    }

    {
        logMessage("Calling bool operator: ");
        ArrayContainer<T> emptyContainer;
        if (!emptyContainer) {
            std::cout<< "emptyContainer is empty!\n";
        } else {
            std::cout<< "emptyContainer is not empty!\n";
        }

        ArrayContainer<T> notEmptyContainer;
        notEmptyContainer.add(2);
        if (!notEmptyContainer) {
            std::cout << "notEmptyContainer is empty!\n";
        } else {
            std::cout << "notEmptyContainer is not empty!\n";
        }
        logMessage("\n");  
    }
}
int main() {
    // containerTests<int>(); // -> right now tests will run only for int type, because we have hardcoded data that is inserted to the container
    ArrayContainer<int> test;
    test.add(1);
    test.add(2);
    test.add(3);
    test.add(4);
    for( auto it = test.begin(); it != test.end(); it++) {
       std::cout << *it; 
    }

    for( auto it = test.begin(); it != test.end(); it++) {
       std::cout << *it; 
    }
}