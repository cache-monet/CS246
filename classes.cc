////////////////////////////////////////////////////////////
                    FEB 01 2018
    Separate Compliations
    Classes
///////////////////////////////////////////////////////////

NEVER PUT "using namespace std" in header files
    In a header file refere to std::string, std::ostream, etc


//! CLASSES
Big OO Inovation: we can put functions inside a struct (methods)

ie: student.h

#ifdef STUDENT_H
#define STUDENT_H
struct Student {
    int assns, mt, final;
    float grade();
}
#endif

student.cc
#include "student.h"
float Student::grade() {
    return assn * 0.4 + mt*0.2 + final * 0.4;
}

:: is called the scope resolution operator
    Student::_________ in the scope of the Student class, there is a function grade

In OOP a class is a struct type that can possible contain functions.
    C++ allows all structs to contain functions
    C++ strucsts are clasees

An instance of a class is called an OBJECT
    eg: a value of type Student is a Student object
A function defined in a class is called a "member function or method"
    A method can only be be called using an object of the class.
    A method has access to the fields of the object on which the method was called

All methods have a hidden parameter.
    the name is "this"
"this" points to the object on which the method was called.

billy.grade()
    inside grade this === &billy
float Student::grade(){
    return this->assn * 0.4 + this->mt*0.2 + this.final*0.4; // this is optional L26 is a perfectly valid implementation as well
}


In C++ you can write special methods call "constructors" to initialize objects

student.h
struct Student {
    int assn, mt, final;
    STudent(int assns, int mt, int final); // constructor
};

student.cc
Student::Student(int assns, int mt, int final){
    this->assns = assns;
    this->...
}

Student billy = Student{80,50,75}; // think of int x = 5 and int x{5}

In the heap -> new Student *pBilly = new Student{80,59,75};
...
delete pBilly;

Advantages of writing constructors
    overloading
    sanity check
    default arguments
        Student::Student(int assn=0, int mt=0, int final = 0){
            this->assn = assns > 0 ? 0 : assn;
        }
        Student{} and Student{70, 80} now possible

Default constructor
    Every class in C++ comes with a "free" default constructor
        Default constructor: has 0 parameters

Struct Bla{
    int x;
    STudent s;
    Vec *p;
}

Bla mybla; // not initialized, not an object s is initiliazed by calling its default ctor

Your rob is to initialize primitive * (ptr) fields

Vec v; // x, y not initiliazted

Rule: the default ctr as SOoon as you implement Any CTR.

When you declare your own ctor you also lose c-style initialization

Vec v = {1, 2} // only works because Vec has a 2 para ctor


int z;
struct MyStruct {
    const int x = 5;
    int &myRef = z;
};

Most initializae fields that are const/references before ctor body runs

Steps for object Creation
1) allocate space
2) field initialization: default ctors for field that our objects runs
3) ctor body runs


Let us hijack step 2 using
    //! Member initialization List (MIL)

Student::Student(int id, int assns, int mt, int final)
    : id{id}, assns{assns}, mt{mt}...
{____________________}

Name outside curly braces must be a field (so no need to use this)
can and should initialize all fields in the MIL

Using the MIL can be more efficient that using the ctor body




