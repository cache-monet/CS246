////////////////////////////////////////////////////////////////////
                    Jan 18 2018 I/O Stream
////////////////////////////////////////////////////////////////////

//! I/O Stream
#include<iostream> imports 3 global variables
    std::cout (type ostream)
        Writes the standard output
        Uses the output operator <<
        ie: cout << "Hello World" << endl
    std::in (type istream)
        Reads standard input
        Uses the input opeator >>
        ie: cin >> x
    std::cerr (type ostream)
        Writes to standard error
        cerr << "error msg"

//TODO Add two numbers
#include<iostream>
using namespace std;

int main () {
    int x, y;
    cin >> x >> y; // waiting to read in two ints, ignoring whitespace
    cout << x + y << endl;
}
If a read fails, the programs continues to run with subsequences reads "automatically failing"
After a read we should check if it was successful
offer reads the expression cinfail() // True if read fails
If read fails b/c of EOF cin.fail() AND cin.eof() are both true
////////////////////////////////////////////////////////////////////
                    
//TODO Read all ints from stdin of echo to stdout one per line. Stop if read fails
#include<iostream>
using namespace std;

int main () {
    int i;
    while (true) {
        cin >> i;
        if (cin.fail()) break;
        cout << i << end
    }
}
C++ defines an "automatic conversion" between istream (ie cin) and bool
//? How does it do the conversion?
    cin is true if the last read did not fail
    cin = T iff cin.fail() = F
////////////////////////////////////////////////////////////////////


//! Bit Shifting

int a = 21
a >> 3 // Right bit shift 

In C++ operators can have multiple meanings ("operator overloading")

Expressiosn produce a value
cin >> i; // expression produces cin


//TODO Read all ints and echo to stdout until EOF
#include<iostream>
using namespace std;

int main () {
    int i;
    while (true) {
        if(cin >> i) cout << i << endl;
        else if (cin.eof()) break; // stopping condition reached
        else { // read failed due to bad input
            cin.clear(); // acknowledge the a read failed
            cin.ignore(); // ignore the error causing character from stdin         
////////////////////////////////////////////////////////////////////////////

//! C++ Strings

In C, strings were simulatedusing null terminated char arrays
    error prone
    memory management
C++ has a "string" type
ie: 
#include<string>
string s = "Hello world"

methods from <string>
=== (string compare)
string.length();
s= s1 + s2 // string concat

//! I/O Manipulators
C had format specifiers %d, %s, ...
//? Print 95 in hex
#include <iomanip>
int i  = 95;
cout << i; // prints 95 in dec
cout << hex; // prints all subset numbers in hex
//! Hex and Dec are sticky manipulator
