////////////////////////////////////////////////////////////////////
                    Jan 23 2018 C++ Streams
////////////////////////////////////////////////////////////////////

Streams abstraction can be used on other sources of data

#include <fstream> //file Streams
    ifstream reading files
    ofstream writing files

io/readFile.cc
#include <string>
#include<iostream>
#include<fstream>

//TODO Read Files and display to stdout
int main () {
    ifstream fileStream{"myfile.txt"};
    "ifstraem is type" filestream is the var name
    string s;
    while (fileStream >> s) {
           cout << s << endl
    }
}
Where do we open the file?
File is opened during initialization "ifstream fileStraem{'myfile.txt'}"
When do we open the file?
When the fileStream variable goes out of scope
////////////////////////////////////////////

Anything that we can do with istream variable (cin) we can do with a ifstream variable
Same with ostream (cout) and ofstream

#include <sstream> // string streams
can attach streams to strings to read/write
    "istringstream" - read from string
    "ostringstream" - write to string

    int lo = ..., high = ...;
    ostringstream ss;
    ss << "enter value between" << lo << "and" << high; // message stored to ss
    string s = ss.str(); // extract string from ss and store it to s
////////////////////////////////////////////////////////////////////

io/getNum.cc

int n;
while(true) {
    string s;
    cin >> s; // read into a string
    istringstream ss{s}; // read string from s
    if (if ss >> n) break; // if ss can be redirected to an int end
    cout << "enter a number" << endl;
}
ignore/clear flags are unneeded as the nested scope means the s and ss will be reinitilized with every loop  
////////////////////////////////////////////////////////////////////

//! Default Arguments

//TODO consume file name and gives input
void printFile(string name="myfile.txt") { // name is a Default argument
    ifstream fileStream{name};
    while(filesStream >> s) {
        cout << s << endl;
    }
}

printFile uses a default argument
Can be called with a specific argument, if no argument is given, the default args is used
printFile("argument") // runs with argument
printFile() // runs with myfile.txt

Restrictions:
Default arguments must appear last
ie: void function(int x = 0, int y) // X will not compile
void function(int x=0, int y=0) // Ok!

//! Funtion Overloading
Can functions have hte same name?
Yes so long as either "the number or type of parameters" are different
    Cannot just be different return type

// Negates an integer
int neg (int x) return -x;
// Negates a bool
bool neg (bool x) return !x;

note: cannot overload a function with default values with a function with the default val removed
ie void foo(int x, string a = "a", string b = "b")
    void foo(int x) X
    void foo(string a) X
    void foo(int x, string b) X

//! References

int n = 5;
const int* p = &n;
p = &x; //OK
*p = 10; // X (does not compile)
n = 10;

int* const p = &n;
p = &x; //X
*p = 10; // OK

//! Structs
Struct Node {
    int data;
    Node* next;
};
Node n = {3, nullptr};


// Parameters Passing (Pass by value, pass by Reference)

void inc(int n) n = n+1
int x=5
inc(x);
cout << x << endl; //prints 5

Why cin >> x; and not cin >> &x
because cin >> is written with pass by reference

//! Pass by Reference

LValue references and Rvalue references

//* LValue refrence
int x = 10;
int& z = x; //  z is a LValue reference to x 
    z is like a "const ptr" to x "z is always pointing to x"
    int* const z = &x;
    With "automatic deferencing"

    The address of z (&z) is the address of x (&x)
    Same with size of z
    z has no presenece, it exist solely as an "alias" for x
        complier does not allocate memory/space for z

Restrictions
    references must always be initialized to an Lvalue
        int& z; //X    
        //* An lval is anything with an address (ie all variables)
            int &z = 5; //X
            int &z = y + y //X
    Cannot create pointers to References
    Cannot create a reference to reference
    Cannot create an "array" of references

void inc(int& n) n = n+1
inc(x);
cout << x << endl; //prints 6
