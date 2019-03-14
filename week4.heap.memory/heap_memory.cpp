#include<iostream>
#include<cstring>

//we will use 
class Student;
//predicate type function in the filter method below
using predicate = bool (*) (const Student&);

//mapping function in the mapOperation below
using mapper = void (*) (Student&);


class Student{
    size_t facultyNumber;
    float avg_grades;
    char* name;

    //we moved the logic from the copy-constructor into a separate function in order to use it in other methods if needed
    void copy(const Student& other){
        facultyNumber = other.facultyNumber;
        avg_grades = other.avg_grades;
        name = new char[strlen(other.name)+1];
        strcpy(name, other.name);
    }

    void destroy(){
        delete [] name;
    }

    public:

    Student() {
        facultyNumber = 71000;
        avg_grades = 3.25;
        name = new char[strlen("Petar")+1];
        strcpy(name, "Petar");
    }

    Student(const Student& other) {
        copy(other);
    }

    Student( int fn, float grades, char* name):facultyNumber(fn), avg_grades(grades) {
        this->name = new char[strlen(name) + 1];
        strcpy(this->name, name);
    }

    Student& operator = (const Student& other) {
        if(this != &other){
            destroy();
            copy(other);
        }
        return *this;
    }

    ~Student(){
        destroy();
    }

    size_t getFn() const {
        return this->facultyNumber;
    }

    float getGrades() const {
        return this->avg_grades;
    }

    const char* getName() const {
        return this->name;
    }

    void setFn(size_t facultyNumber) {
        this->facultyNumber = facultyNumber; 
    }

    void setGrades(float newGrades) {
        this->avg_grades = newGrades;
    }

    void seName(const char* newName) {
        // if we use the default constructor that compiler creates for us 
        // the pointer should have some random address as value and we will try to delete something that 
        // does not belong to us. That's another reason to redefine the default constructor
        if (this->name) {
            delete [] this->name;
        }

        this->name = new char[strlen(newName)+1];
        strcpy(this->name, newName);
    }

    void print() const {
        std::cout << this->facultyNumber << '\n';
        std::cout << this->name << '\n';
        std::cout << this->avg_grades << '\n';
    }
};

int main(){

    Student st;
    st.print();
    Student st2(st);
    st2.print();
    st2.seName("Ivan");
    st.print();
    st2.print();
    // Student test("Ivan Petrov Ivanov");

    return 0;
}