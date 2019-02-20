#include<iostream>
#include<cstring>
//we do not need to use the whole namespace std !!!!


// Student = {
//   facultyNumber -> int/size_t,
//   avg_grades -> double/float,
//   name -> char[30]
// }

struct Student{
    size_t facultyNumber;
    float avg_grades;
    char name[30];
    void print() const {
        std::cout << this->facultyNumber << '\n';
        std::cout << this->name << '\n';
        std::cout << this->avg_grades << '\n';
    }
};


void greetStudent(Student& st){
    std::cout << "Hello ";
    std::cout << st.name << "!\n";
    std::cout << "FN: " << st.facultyNumber << '\n';
    std::cout << "Avg. grades: " << st.avg_grades << '\n';
}

int main() {
    //work with single student
    Student testStudent;
    strcpy(testStudent.name, "Test student");
    testStudent.facultyNumber = 71010;
    testStudent.avg_grades = 5.25;

    std::cout << testStudent.facultyNumber << '\n';
    std::cout << testStudent.avg_grades + 0.5 << '\n';

    //work with multiple students - arrays introduced but only one
    Student students[3];

    for(int i=0;i<3;i++) {
        //some dummy data to initialize the objects -> everyone will have same name for now
        strcpy(students[i].name, "Test student");
        students[i].facultyNumber = 71000 + i;
        students[i].avg_grades = 3.25 + i*0.25;
    }

    //now if we want to do something with themq for example print their data - we can call directly their method
    for(int i=0;i<3;i++) {
        students[i].print();
    }

    //parse it to a function - we will use testStudent
    greetStudent(testStudent);

  return 0;
}