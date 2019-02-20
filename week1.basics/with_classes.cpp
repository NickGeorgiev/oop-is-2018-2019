#include<iostream>
#include<cstring>
//we do not need to use the whole namespace std !!!!


// Student = {
//   facultyNumber -> int/size_t,
//   avg_grades -> double/float,
//   name -> char[30]
// }

class Student{
    //private: is not necessary here
    size_t facultyNumber;
    float avg_grades;
    char name[30];
    public: //part of the interface of the type Student
    //we start with the basic getter functions
    size_t getFn() const {
        return this->facultyNumber;
    }

    float getGrades() const {
        return this->avg_grades;
    }

    const char* getName() const { //what is the type of name if it is declared as char name[30] ??
        return this->name;
    }

    //and continue with setters
    void setFn(size_t facultyNumber) {
        this->facultyNumber = facultyNumber; // what will happen if we omit "this" pointer
    }

    void setGrades(float newGrades) {
        this->avg_grades = newGrades;
    }

    void seName(const char* newName) {
        strcpy(this->name, newName);
    }

    //some sample functionality
    void print() const {
        std::cout << this->facultyNumber << '\n';
        std::cout << this->name << '\n';
        std::cout << this->avg_grades << '\n';
    }
};


void greetStudent(Student& st){
    std::cout << "Hello ";
    std::cout << st.getName() << "!\n";
    std::cout << "FN: " << st.getFn() << '\n';
    std::cout << "Avg. grades: " << st.getGrades() << '\n';
}

int main() {
    //work with single student
    Student testStudent;
    // testStudent.facultyNumber = 71010; <- why we can't do this now?
    testStudent.setFn(71010);
    testStudent.seName("Test student");
    testStudent.setGrades(5.25);

    std::cout << testStudent.getFn() << '\n';
    std::cout << testStudent.getGrades() + 0.5 << '\n';

    //work with multiple students - arrays introduced but only one
    Student students[3];

    for(int i=0;i<3;i++) {
        //some dummy data to initialize the objects -> everyone will have same name for now
        students[i].seName("Test student");
        students[i].setFn(71000 + i);
        students[i].setGrades(3.25 + i*0.25);
    }

    //now if we want to do something with themq for example print their data - we can call directly their method
    for(int i=0;i<3;i++) {
        students[i].print();
    }

    //parse it to a function - we will use testStudent
    greetStudent(testStudent);

  return 0;
}