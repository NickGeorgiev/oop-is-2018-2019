#include<iostream>
#include<cstring>
#include<cassert>

//we will use 
class Student;
using predicate = bool (*) (const Student&);


class Student{
    size_t facultyNumber;
    float avg_grades;
    char name[30];
    public: 
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

class StudentsGroup {
    Student students[30];
    int size = 0; //Until we discuss what constructors are. Then this should not be seen in your code
    public:
    void addStudent(const Student& newStudent) {
        if (size < 30) { // What will happen if we skip this check??
            this->students[this->size++] = newStudent;
            //equivalent to:
            //students[size++] = new students. Why?
        }
    }

    //same as previous one but using operator +=
    void operator += (const Student& newStudent) {
            if (size < 30) { 
            this->students[this->size++] = newStudent;
        }
    }

    //Notice: If we are to use any of the following operators - +, -, *, / etc. (all arithmetic operators that are not grouped with the assignment operator "=")
    // It is better to return a copy of the current object. So if we are to use operator + in this case it should look like this:
    StudentsGroup operator + (const Student& newStudent) {
        if (size < 30) {
            StudentsGroup newGroup;
            for(int i=0;i< 30;i++) {
                newGroup.addStudent(this->students[i]);
            }

            newGroup.addStudent(newStudent);
            return newGroup;
        }

        //we haven't added anything so should return the same object or throw an error - last onw will be discussed
        return *this;//We can return the object itself
    }

    //function to "pop" a student from the group - removing the last added element to the array
    void popStudent() {
        if (size > 0) {// the initial value is 0 and we don't want to have an array with index -1 for example
            size--;
        }
    }

    void operator -- (int temp = 0){ //if you are curious enough, ask the colleagues tommorrow
        if (size > 0) {
            size--;
        }
    }

    void print() const {
        for (int i=0; i<size; i++) {
            this->students[i].print();
            std::cout<<std::endl;
        }
    }

    //higher order functions
    //we filter our group to find all students that match the provided predicate "p" and return new group only with them
    StudentsGroup filter(predicate p) {
        StudentsGroup filteredStudents;
        for(int i=0;i<size;i++) {
            if (p(this->students[i])) { //the predicate is exepcted to return true/false
                filteredStudents.addStudent(students[i]);
            }
        }
        return filteredStudents;
    }

    //for excercise
    //finish the implementation of the function "find" that accepts predicate and returns the first student that matches it 

    //uncomment the fragment below
    // [what_type] find([what_params])[const/nothing]{
    //     //...remove me and add logic
        
    //     //if we do not find anything - right now we should assert that case. In the future an exception should be thrown.
    //     assert(false);
    // }
};

//test bool predicate
bool evenFacultyNumber(const Student& st) {
    return st.getFn() % 2 == 0;
}

//helper function to initialise many test students - all have the same name
void initialiseStudents(Student* studentList, int studentsCount) {
    for (int i=0;i<studentsCount; i++) {
        studentList[i].seName("TestStudent");
        studentList[i].setFn(71000 + i);
        studentList[i].setGrades((3+i)%6 + 0.1);
    }
}


void executeTestsWithoutLambda(){
    std::cout << "StudentsGroup tests w/o lambda:" << std::endl;
    Student sts[10];
    initialiseStudents(sts, 10);
    StudentsGroup group;
    for(int i=0;i<10;i++){
        if (i%2 == 0){ //some check to demonstrate that it works with both approaches
            group.addStudent(sts[i]);
        } else {
            group+=sts[i]; // what was the equivalent syntax for this?? And how to make it a non-member function?
            //how should we proceed with the other variants? Do it yourself
        }
    }

    StudentsGroup result = group.filter(&evenFacultyNumber);
    result.print();
}

//offtopic
void executeTestsWithLambda() {
    std::cout << "StudentsGroup tests w/ lambda:" << std::endl;
    Student sts[10];
    initialiseStudents(sts, 10);
    StudentsGroup group;
    for(int i=0;i<10;i++){
        if (i%2 == 0){ //some check to demonstrate that it works with both approaches
            group.addStudent(sts[i]);
        } else {
            group+=sts[i]; // what was the equivalent syntax for this?? And how to make it a non-member function?
            //how should we proceed with the other variants? Do it yourself
        }
    }
    StudentsGroup resultWithLambda = group.filter([](const Student& st)->bool {return st.getFn()%2 == 0;});
    resultWithLambda.print();

}
int main(){
    executeTestsWithoutLambda();
    executeTestsWithLambda();
    return 0;
}