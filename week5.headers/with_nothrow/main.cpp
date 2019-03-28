#include<iostream>
#include "IntArrayContainer.h"


void logMessage(const char* message) {
    std::cout << message <<std::endl;
}

bool isOdd(const int& elem) {
    return elem %2 != 0;
}

void containerTests() {
    {
        logMessage("Calling default constructor and print data: ");
        IntArrayContainer initialObject;
        initialObject.print();
        logMessage("\n");
    }

    {
        logMessage("Calling copy constructor and print data: ");
        IntArrayContainer initialObject;
        IntArrayContainer copyObject(initialObject);
        copyObject.print();
        logMessage("\n");
    }

    {
        logMessage("Calling params constructor and print data: ");
        IntArrayContainer paramObject(10);
        paramObject.print();
        logMessage("\n");
    }

    {
        logMessage("Calling assignment operator and print data: ");
        IntArrayContainer initialObject;
        IntArrayContainer assignedObject(10);
        assignedObject = initialObject;
        assignedObject.print();
        logMessage("\n");
    }

    {
        logMessage("Calling empty method: ");
        IntArrayContainer initialObject;
        std::cout << initialObject.empty();
        logMessage("\n");
    }

    {
        logMessage("Calling full method: ");
        IntArrayContainer initialObject;
        std::cout << initialObject.full();
        logMessage("\n");
    }

    {
        logMessage("Calling add method: ");
        IntArrayContainer initialObject;
        initialObject.add(1);
        initialObject.print();
        logMessage("\n");
    }

    {
        logMessage("Calling pop method: ");
        IntArrayContainer initialObject;
        initialObject.add(1);
        initialObject.add(2);
        initialObject.print();
        initialObject.pop();
        initialObject.print();
        logMessage("\n");
    }

    {
        logMessage("Calling count method: ");
        IntArrayContainer initialObject;
        initialObject.add(1);
        initialObject.add(2);
        std::cout << initialObject.count();
        logMessage("\n");
    }

    {
        logMessage("Calling remove method: ");
        IntArrayContainer initialObject;
        initialObject.add(2);
        initialObject.add(3);
        initialObject.print();
        initialObject.remove(2);
        initialObject.print();
        logMessage("\n");
    }

    {
        logMessage("Calling member method: ");
        IntArrayContainer initialObject;
        initialObject.add(3);
        std::cout << initialObject.member(2);
        logMessage("\n");
    }

    {
        logMessage("Calling find method: ");
        IntArrayContainer initialObject;
        initialObject.add(3);
        initialObject.print();
        std::cout << initialObject.find(&isOdd);
        logMessage("\n");
    }

    {
        logMessage("Calling filter method: ");
        IntArrayContainer initialObject;
        initialObject.add(2);
        initialObject.add(3);
        initialObject.add(4);
        initialObject.print();
        IntArrayContainer filteredData = initialObject.filter(&isOdd);
        filteredData.print();
        logMessage("\n");

    }

    {
        logMessage("Calling map method: ");
        IntArrayContainer initialObject;
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
        IntArrayContainer initialObject;
        initialObject.add(1);
        initialObject.add(2);
        initialObject.add(20);
        initialObject.print();
        IntArrayContainer second;
        second.add(20);
        second.add(22);
        second.print();

        IntArrayContainer intersected = initialObject.intersection(second);
        intersected.print();
        logMessage("\n");
    }

    {
        logMessage("Calling complement method: ");
        IntArrayContainer initialObject;
        initialObject.add(1);
        initialObject.add(2);
        initialObject.add(22);
        initialObject.print();
        IntArrayContainer second;
        second.add(20);
        second.add(22);
        second.print();

        IntArrayContainer complemented = initialObject.complement(second);
        complemented.print();
        logMessage("\n");
    }

    {
        logMessage("Calling unionWith method: ");
        IntArrayContainer initialObject;
        initialObject.add(22);
        initialObject.print();
        IntArrayContainer second;
        second.add(20);
        second.add(22);
        second.print();

        IntArrayContainer united = initialObject.unionWith(second);
        united.print();
        logMessage("\n");
    }

    {
        logMessage("Calling bool operator: ");
        IntArrayContainer emptyContainer;
        if (!emptyContainer) {
            std::cout<< "emptyContainer is empty!\n";
        } else {
            std::cout<< "emptyContainer is not empty!\n";
        }

        IntArrayContainer notEmptyContainer;
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
    // IntArrayContainer a; // a -> 4 el
    // IntArrayContainer b(20); // b -> 20 el

    // for(int i=0;i<10;i++) {
    //     a.add(i);
    // }

    // std::cout<<a.count()<<std::endl;
    // a.print();
    containerTests();
}