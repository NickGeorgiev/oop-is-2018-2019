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
    char name[30];

    //we moved the logic from the copy-constructor into a separate function in order to use it in other methods if needed
    void copy(const Student& other){
        this->facultyNumber = other.facultyNumber;
        this->avg_grades = other.avg_grades;
        strcpy(this->name, other.name);
    }

    void destroy(){
        //this function should be called in the destructor if there is any dynamic resource to be freed
        //right now we work only with static data and we don't do anything usefull yet.
        std::cout << "I have been destroyed!\n";
    }

    public: 
    //Cannonical representation for the Student class - basic 4 methods that are applied to all objects
    
    //1-Default constructor
    // Student() = delete; -> if we want to restrict the compiler from creating the default constructor
    // Student() = default; -> if we want to follow the compiler default behaviour for this constructor

    //Simple way to implement it
    // Student(){
    //     this->facultyNumber = 71000;
    //     this->avg_grades = 5.25;
    //     strcpy(this->name,"default");
    // }

    Student(): facultyNumber(71000), avg_grades(5.25), name("text"){ // we dont need to have anything in the body
        // this->facultyNumber = 71000;
        // this->avg_grades = 5.25;
        // strcpy(this->name,"default");
    }

    //Parametric constructor - NOT PART OF THE CANNONICAL REPRESENTATION!!!!
    //We can have more than one parametric constructor if we need
    Student(size_t _fn, float _grades, const char* name){
        facultyNumber = _fn;
        avg_grades = _grades;
        strcpy(this->name, name);
    }

    // 2 - Copy constructor
    // Student(const Student&) = delete;
    // Student(const Student& other) = default;
    Student(const Student& other){
        copy(other);
    }

    // 3 - assignment operator
    // Student& operator = (const Student&) = delete;
    // Student& operator = (const Student&) = default;
    Student& operator = (const Student& other){
        if(this != &other){
            //phase 1 -> delete current resources

            //phase 2 -> set new ones
             copy(other);
        }
        return *this;
    }
    //4 - Destructor
    // ~Student() = default;
    ~Student(){
        std::cout<<"I died\n";
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
    // Student st(71001, 5.25, "test");// Student(int, float, const char* )
    // st.print();
    // Student st1(st);
    // // Student st1=st;
    // st1.print(); 

    return 0;
}