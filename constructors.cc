////////////////////////////////////////////////////////////
                        Feb 6 2018
        Member intialization
        Copy constructor
        Single parameter Ctor
        Destructors
        Copy assignment
////////////////////////////////////////////////////////////

MIL
    Must use to to intialize const and references
    can be used for all fields
    intialization occurs in declaration order
    can be more efficient than intializing objects in the ctor body

Student::Student(int, id, int assns,....)
    :id{id}, assn{assns}, mt{mt}, final{final}{}


//! Copy constructor
Creating copies of a object
    Student billy{80,50,75};
    Student bobby{billy} // bobby is a copy of billy
Objects are coppied by calling the "copy constructor"

Every Class comes with a default "copy constructor" for free

Every class comes with: 
    default ctor
    // Big five
    copy constructor
    destructor
    copy assignment operator
    move constructor
    move assignment operator

The default copy ctor does a "field for field copy" (values not methods)

//TODO how the default copy ctor works
    Student::Student(const Student& other)
        :assns{others.assns}, mt{others.mt}...{}

The default ctor is inappropriate for certain situation

ie:
//TODO Node Class
Node.h
struct Node{
    int data;
    Node* next;
    Node(int data, Node *next); // ctor
    Node(const Node& other) // copy`
}

Node.cc
include "Node.h"

//ctor
Node::Node(int data, Node* next)
    : data{data}, next{next} {}

// default copy constructor
Node::Node(const Node& other)
    : data{other.data}, next{other.next}{}
Suppose:
    Node *np = new Node{1, new Node{2, new{Node 3, nullptr}}}
        //1 -> 2 -> 3 -> nullptr
    Node m{*np} // calling default copy ctor on the stack
    Node *np1 = new Node{*np}

Should have three separate linked lists
        np: 1 -> 2 -> 3 -> nullptr
        m: 1 -> 2 -> 3 -> nullptr
        np1: 1 -> 2 -> 3 -> nullptr

But actually only the first node will be copied over,
    m and np1 will share the share the rest of the list with np
This is called "Shallow copy" ("copies the address")
    Only the address copied not the object at the address
    For a ptr we might want to "copy" the "object the ptr is pointing to"
Deep copy ("copies the object at the address")

//TODO Deep copy implementation
Node::Node(const Node& other):
    data{other.data},
    next{
       other.next ? New Node{*other.next} : nullptr; 
       // recursively call copy ctor on deferenced other.next if it is not null 
    }{}


A copy ctyor is used 
    1) To creat a copy of an objevt
    2) when passing an arg by value
        The parameter of the copy ctor "must be pass by ref" 
    3) when return by value

//! Single parameter Ctor
Node::Node(int data)
    : data{data}, next{nullptr}{}

Node{4};// OK
Node n = 4; //OK
void foo (Node n){......}
foo(4); //OK

One parameter ctor create implicit/automatic conversions
    striing s = "hello";
    void foo("hello");
        // string class has a single parameter ctor
To disable implicit conversions use the keyword "explicit"

//TODO Disable implicit conversions in Node
Struct Node{
    explicit Node(int data);
}
Node n = 4 // X
Node n{4} // OK 
foo(4) // X

//! DESTRUCTORS

When an object is destroyed, a method called the destructor runs
    When stack allocated object goes out of scope
    When a heap obj gets deleted

Steps for object destruction
    1) dtor body runs
    2) fields are destructed
        call dtor for any fields that are objects
    3) Space is reclaimed

A class can "only have one dtor"

Name: ~ClassName()
ie: ~Node(); ~Student();
    no return type

The free dtor has an empty ddtor body 
    ie: call dtor on fields that are objects (but not heap memory)

// TODO How default dtor can fail us
Node *np = new Node{1, new Node{2, new{Node 3, nullptr}}}

When we write
    delete np
    Which cause dtor for Node with value 1
    However since next is a node ptr not a node object the rest of the linked list are "leaked" 
result: 2-> 3 -> nullptr

// Delete Node* next(s)
Node::~Node(){
    delete next; // recursively calls dtor
}

//! COPY ASSIGNMENT OPERATOR
Student billy{80,50,75};
// Copy constructor
Student bobby{billy}; // or Student bobby = billy
// Copy assignment
Student jane;
jane = billy // constructing Student::operator=

Copy assignment: reassign an "existing obj" as a copy of another objects
Copy ctor: create a new object as a copy of another

The free copy operator= does a field for field copy

Again default copy operator= fails when heap memory is involved

// TODO Deep copy assignment operator
Note: assignment is evaluated from the right
    a = b = c = 0;
    c = 0 -> b = 0 -> a = 0;

Works for objets too
    n1 = n2 = n3// OK 

So assignment oeprator must "return a node to do casscade assignments" 

Note: cannot  use MIL, as MIL is for ctors only
Node& Node::operator=(const Node& other){
    if (this == &other) return *this; // compare addresses
    data = other.data;
    delete next; // in case next is already pointing to heap memory 
        // contingency n = n,  attempts to copy n.next after it's deleted (n.next is a dangling ptr) 
        //* solution check for self assignment
    next = other.next ? new Node{other.next} : nullptr; // recursively call COPY CTOR

    return *this; // remember this->data = other.data, etc
}
 
