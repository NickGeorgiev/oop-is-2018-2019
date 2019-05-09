#include<iostream>
class Person {
    int age;
    public:
    Person() {
        std::cout << "Person()\n"; 
    }
    Person(int k) {
        std::cout<<"Person(int)\n";
    }
    Person(const Person& other) {
        std::cout<<"Preson(const Person&)\n";
    }
    ~Person() {
        std::cout << "~Person()\n";
    }
    Person& operator=(const Person& other) {
        std::cout<< "Person& operator =() \n";
    }
    virtual void f(int k=0) {
        std::cout << k+1;
    }
};

class Foo{
    public:
    Foo() {
        std::cout<<"Foo() \n";
    }
    ~Foo() {
        std::cout<<"~Foo() \n";
    }
};

class Student :public Person {
    int fN;
    // Person b;
    public: 
    Student() {
        std::cout<<"Student()\n";
    }
    Student(int k): Person(k) {
        std::cout<<"Student(int)\n";
    }
    Student(const Student& other):Person(other) {
        std::cout <<"Student(const Stundet&)\n";
    }
    Student& operator= (const Student& other) {
        Person::operator=(other);
        Foo:
        std::cout<<"Student& operator=\n";
    }
    ~Student() {
        std::cout<< "~Student()\n";
    }
    void f(int k=0) {
        std::cout << k +2;
    }
};


class Animal {
    char name[30];
    int age;
    public:
    virtual void makeSound() const = 0;
};

class Dog: public Animal {
  public:
    void makeSound() const override {
        std::cout<< "Woof\n";
    }
};

class Cat: public Animal {
 public:
 void makeSound() const override {
     std::cout<<"Meow\n";
 } 
};
// Abstract container and test classes have been removed

int main() {
    // Student a;
    // std::cout<<std::endl;
    // Student b(a);

    // // a.f();
    // Person c;
    // c.f();

    // Person d;
    // d.f();
    // Student c;
    // c.f();
    // Person* ptr = &d;
    // ptr->f();
    // ptr = &c;
    // ptr->f();
    // Dog d;
    // d.makeSound();
    // Cat c;
    // c.makeSound();

    // Animal* an = new Dog;
    // an->makeSound();
    // an = new Cat;
    // an->makeSound();
    B b;
    b.f();
}