/////////////////////////////////////////////////////////////////////////////////////
                                Jan 30 2018
    Preprocessor (cont)
        Conditional Compliation
        Debug statuments
    Separate Compliation
        Makefiles
    Include Guards
/////////////////////////////////////////////////////////////////////////////////////
//! Last time
    #include <___> 
    g++ -E -P <file.cc> // to see preprocess output
    #define VAR VALUE
        #define MAX 10
        int arr[MAX];

//! Conditional Compliation
//TODO using preprocessor to target certain architectures (IOS vs BBOS)
#define IOS 1 
#define BBOS 2 (blackberry)
#define os IOS
#if os == BBOS
    long long int key; //  executed if os is BBOS
#elif os == IOS
    int key;
endif

This requires manually changing the define for OS to target IOS/BBOS
    lets use Preprocessor directives as arguments to the complier
//* g++ -DVAR=VALUE <file.cc>
ie: g++ -Dos=IOS file.cc // replaces #define os IOS


#define VAR // perfectly legal; VAR=""
Usually used with "#ifdef VAR" OR 
    "#ifndef VAR"

//! Debug statuments
refine debug.cc

#ifdef DEBUG
    cout << "error message"
#endif
g++ -DDEBUG debug.cc

//! Separate Compliation
    Divide code into header (.h) 
        type definition forward declaration of functions
    and Implementation (.cc)

1) g++ *.cc
    only works if all files in pwd are part of the project
    .h files are meant to be INCLUDED NEVER Implementated

2) g++ file1.cc file2.cc file3.cc
    manually enter the files as arguments

Neither 1 nor 2 are separate Compliation

separate complier
Compile each file separately then put them all together to make executionable

Linking: to produce executable from complied files

g++ vec.cc or g++ main.cc compiles but does not link
By default comlier tries to produce an executable to tell g++ to just compile (and not link)
    g++ -c vec.cc
    g++ -c main.cc
this creates vec.o main.o

to link .o files
    g++ main.o vec.o 
this produces the executable

    -c produces .o (object) files
        contain compiled binary
        also contain what is defined what is needed
    To merge
        g++ main.o vec.o -o myprogram //(creates exec myprogram)

The problem: keeping track of which files(s) need to be recompiled


//! Make files

    makes files contains the layout of your program
    contains dependencies btwn files

myprogram depends on main.o and vec.o
vec.o depends on vec.h and vec.cc
etc

tools/make/example1/Makefile
-> When executed first time it will complie all targets 

Commands: "make" "target" ".phony clean"
    make: checks which files need to be updated and updates them
        initial usage: complies all target

        if vec.cc is changed, make determine that the timestamp on vec.cc is new than vec.o,
        vec.o is updated and timestamp on vec.o is more recent thant myprogram, myprogram is recomplied
    target: reveals dependencies

    ".phony clean"
        the clean target enables you to delete all binaries to start fresh
        .phony tells make that "clean is not a file"

//TODO code in make/example2 

We can leave out the compile command, make will infer
${CXX} ${CXXFLAGS} -c x.cc


// make/example3
-MMD
    g++ -MMD -c vec.cc
    -c produces vec.o
    -MMD produces vec.d which contains
        vec.o: vec.cc vec.h 

DEPENDS = ${OBJECTS:.O=.d} for each .o there is a .d file
    .d files contains .o file dependencies

//* Basically copy makefile/example3  and change exec and objects 


//! Include Guards

Always put inlcude guards in all .h files

vec.h
    #ifndef VEC_H; // or some unique name
    #define VEC_H`;
    .... // contents of vec.h or whatever
    #endif

separate/examples3
    g++ -c main.cc causes error: redef struct Vec