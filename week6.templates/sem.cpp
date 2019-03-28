#include<iostream>
#include "./ArrayContainer/ArrayContainer.cpp"


struct Student {
    int fn;
    friend std::ostream& operator <<(std::ostream& os, Student& st) {
        os << st.fn;
        return os;
    }
};

// void print(int a) {
//     std::cout << a;
// }

// void print(double a) {
//     std::cout << a;
// }

// void print(Student a) {
//     std::cout << a;
// }

template<typename T>
void print(T a) {
    std::cout<< "\nCalling template\n";
    T b;
    std::cout << b;
    std::cout << a;
}

void print(Student st) {
    std::cout<<"\nI am a student!\n";
}

template<typename T>
T sum(T a, T b) {
    return a+b;
}

template<typename T, int K>
struct dummyArray {
    T array[K];
    int size = K;
    void print() {
        std::cout << size << std::endl;
    }
};

//using defined template params in type declaration
//note - we can have default type values if no type is provided - same as functions with default parameters
template<typename T,int K, typename C = dummyArray<T, K> >
struct dummyContainer{
    C container;
    void selfPrint() {
        container.print();
    }
};

int main() {
    print<int>(3);
    print(2.14);
    Student st;
    st.fn = 71004;
    print(st);
    print<Student>(st); //if we specify the type then we call the template function not the classified one!
    std::cout << "\nCreating dummy array with 10 elements at compile time:\n";
    dummyArray<int,10> d;
    d.print();
    d.array[9] = 12;
    std::cout << "At 10th pos: " << d.array[9] << std::endl;
    ArrayContainer<int> c;
    //We declare an instance of class dummyContainer that holds integers in a dummyContainer with size 22
    dummyContainer<int, 22> dummyC;
    std::cout << "\ndummyContainer inner container size: \n";
    dummyC.selfPrint();
}