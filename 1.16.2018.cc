////////////////////////////////////////////////////////////////////
                           Jan 16 2018 
////////////////////////////////////////////////////////////////////
                    
//TODO Checking if a word is in a dictionary (Continued from Last time)
#!/bin/bash
egrep "^$1$" /usr/share/dict/words > dev/nul
if [ $? -eq 0]; then //status code is 0 (successfull)
    echo Not a good password
else
    echo Maybe a good password
fi
////////////////////////////////////////////////////////////////////

//! LOOPS

// WHILE loop

//TODO Print numbers from 1 to $1
#!/bin/bash
X=1
while [$X -le $1]; do
    echo $X
    // X=$X+1 cannot increment X this way would concat 1 to X (ie X=50 -> X=501)
    X=$((X+1))
    
////////////////////////////////////////////////////////////////////
// FOR loop

//TODO Rename all .C files to .cc
    ie: mv hello.C hello.cc
    OR 
    file=hello.C
    mv ${file} ${file%C}cc // truncate the C and Concat the cc ending
for name in *.C; do
    mv ${name} ${name%C}cc
done
////////////////////////////////////////////////////////////////////

//TODO How many times does the word $1 appear in file $2
#!/bin/bash
X=0
for word in $(cat $2); do // execute cat first and then place results here
    if [ $word} == $1 ]; then
        X=$((X+1))
    fi
done
////////////////////////////////////////////////////////////////////

Note: if file name contains whitespace, wrap in ""


////////////////////////////////////////////////////////////////////
                           Testing 
////////////////////////////////////////////////////////////////////

Testing is not the same as debugging
Testing does NOT guarantee correctness
Black box testing without looking at code
    check for "numeric ranges"
        < 0, =0, > 0
        Boundaries (edge and corner cases)
            edge is the extreme of a Boundary
            corner is where two boundaries meet
Do NOT check for invalid inputs

////////////////////////////////////////////////////////////////////
                           C++ 
////////////////////////////////////////////////////////////////////

C++ developed by Bjarne Stroustrup
    Simula67 (first OO language, but no one was using it)
    C++ is C with "classes"

//TODO Hello World
//! C
#include <stdio.h>
int main() {
    printf("hello world\n");
    return 0;
}
////////////////////////////////////////////////////////////////////

//! C++
#include <iostream>
int main() {
    cout << "hellow world" << endl;
    return 0
}
////////////////////////////////////////////////////////////////////

//! Compiling
g++ -std=c++14 === g++14

//TODO Complilation
g++14 file.cc // produces a *.out OR
g++14 file.cc -o myprogram // renames *.out