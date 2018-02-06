///////////////////////////////////////////////////////////////////////
                    Jan 25 2018
    References continued
    Pass by values
    Dynamic Memory allocation
    Operator overloading
    Preprocessor    
///////////////////////////////////////////////////////////////////////
//! Refereces are a constant pointer (cannot change what they are pointing to) 
//* Operator overloading continued
cin >> x 
// operator >> (cin, x);
std::istream& operator>> (std::istream& in, int& data);

Passby value vs Pass by reference
struct ReallyBig {...}
void f(ReallBig rb) {...} // pass by value
ReallyBig b;
f(b) // results in a copy of b to be created within the scope of f
    // space and time expensive!
In C to avoid copy "pass by pointer"
    //TODO f(*b)
    can do the same in C++, but pass by reference is preferable
//TODO Pass by reference
void g(ReallBig& rb) {...}
    rb will now act as an alias for "b"
g(b) // pass by reference: avoids copy

///////////////////////////////////////////////////////////////////////
How to avoid mutation for b?
// TODO use a reference to a constant
void h(const ReallBig& rb) {...}
    // avoids copy AND mutation

///////////////////////////////////////////////////////////////////////
/* 
*ADVICE
    * whenever possible prefere to pass by reference to const for anything bigger than an int
    * another benefit of passing by refer to const
        can reference non-lval
*/
        while void foo(int &x) {...}
            foo(5) X
            foo(y + y) X
        for void foo2(const int& x) {...}
            foo2(5) OK
            foo2(y + y) OK
    //! C++ will allow initialization of a reference to a const from a non-lvalue

//! Dynamic Memory allocation (Heap allocation)
In C,
    int* p = malloc(...)
    ...
    free(p);

Not allowed to use malloc free 
C++ uses new/delete

new is type aware knows the size of different types
struct Node {
    int data
    Node* next;
}
Node* np = new Node;
    // no need to specify how much space is needed 
...
delete np;

Allocating an array of structs
Node* narray = new Node[10]
...
delete [] narray;

//! Returning values

Node getMeANode() {
    Node n;
    return n; // return by value ie: a copy is returned
    can be expensive
}
//TODO Bad attempt of return by pointer
Node* getMeANode() {
    Node n;
    return &n;
}
NO!! "Dangling pointer"
Node n only function scope, the returned address can be used again

//* Never return a pointer or a reference to stack allocated memory

Alternative Return by Heap address
Node* getMeANode() {
    Node *np = new Node;
    return np; // return by value, but the value is an address
}

///////////////////////////////////////////////////////////////////////
//! Opeator overloading

C++ allows users to redefine operators for user created types

//TODO Adding vectors
struct Vec {
    int x;
    int y;
}
Vec operator+ (const Vec& v1, const Vec& v2){
    Vec v{v1.x + v2.x,
          v1.y + v2.y};
    return v;
}
///////////////////////////////////////////////////////////////////////
//Todo Scalar multiplication
Vec operator* (const Vec& v, int c){
    return {v1.x*c, v1.y*c}
}
Vec operator* (int c, const Vec& v){
    return {v1.x*c, v1.y*c}
    OR
    return v*c // implement one operator in turns of another
}
///////////////////////////////////////////////////////////////////////

//TODO I/O operators
struct Grade {
    int theGrade;
}
// cout << g
std::ostream& operator<<(std::ostream& out, const Grade& g){
    out << g.theGrade << "%";
    return out;
}
// cin >> g
std::istream& operator>>(std::istream& in, const Grade& g){
    cin >> g.theGrade;
    if (g.theGrade < 0) g.theGrade = 0;
    if (g.theGrade > 100) g.theGrade = 100;
    return in;
}

//! The Preprocessor
A program that runs before the complier actually sees your code
    changes your code
#include <___>
    Preprocessor directive 
    copy and pastes contents of header right here
Note <> is reserved for headers from STD library
"" for normal (and user created) headers
#include "___"
To see the output of the Preprocessor use -E (additionally -P for better formatting)
//* g++ -E -P file.cc

Define Directive
    #define Variable Value
Searches and replaces Variable with Value
ie #define Max 10
int array[Max] // Max gets replaced by 10 by preprocessor