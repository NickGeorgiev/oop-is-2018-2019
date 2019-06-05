#include<iostream>
#include<cassert>

int badFunction(int number) {
    if( number < 0 ) {
        throw "I am a bad function";
    }
    return number;
}
struct custom_exception : public std::exception {
    const char* what() {
        std::cout<<"I am custom exception";
    }
};

int worseFunction(int number) {
    if (number > 0) {
        throw custom_exception();
    }
    return number;
}
int g () {
    try{
        std::cout << badFunction(12);
        std::cout << worseFunction(14);
    }catch(std::exception*& e) {
        e->what();
    }
    catch(custom_exception& e) {
        e.what();
    }
    catch(int e) {
        std::cout<<"handled int exception";
    }catch(double e) {
        std::cout<<"handled double exception";
    }catch(const char* e) {
        std::cout<<badFunction(15);
    }catch(const char* e) {
        std::cout<<"Merilin e prava?";
    }
}

int main() {
    try {
        g();
    }catch(const char* e) {
        std::cout<<e;
    }
}