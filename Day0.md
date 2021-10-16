# CReact- An Programmable HyperText Markup Language

“ What if we could hack NASA with HTML!” - a dream of every programmer

Well we took it seriously, so let's make something that could extend HTML beyond its limits, so we went to the GOD of all languages to seek some help, yea it's not python it’s the old age C, and guess what we got ourselves…..

CReact is a brand new crazy language that does all, plus its open-source add more layers to it make it more powerful :)

So we would be building a new esoteric (basically means crazy) language that gets interpreted to C language and gets compiled to give any result you want: conditionals, loops, characters, arithmetic, functions, recursion...

## Prerequisites :

    1. A tad bit of knowledge on C and CPP both...

    2. Slight overview of bash scripting and makefile.

So here we shall go step by step and understand how to transpile our code in any format to a proper C code for easier reference. We have used a simple language like HTML to work with.

## Introduction Resources :

    - Overview Of C++ Language (Docs)  : https://www.cplusplus.com/reference/
    - Overview Of C++ Language (Docs)  : https://docs.microsoft.com/en-us/cpp/cpp/?view=msvc-160
    - Overview Of C++ Language (Video) : https://www.youtube.com/watch?v=vLnPwxZdW4Y&t=10067s
    - Overview Of Pointers in C/C++    : https://www.youtube.com/watch?v=zuegQmMdy8M

## Step 0 : Basics

### An overview of STL and its concepts :

The Standard Template Library (STL) is a set of C++ template classes to provide common programming data structures and functions such as lists, stacks, arrays, etc. It is a library of container classes, algorithms, and iterators. It is a generalized library and so, its components are parameterized.

Containers or container classes store objects and data.
Each container contains some inbuilt functions that help in operating on the containers and manipulating
them to store as well modify data in it. These containers work as parameterized template classes, which are called from the library appropriately when required, lets look at 2 main examples of containers that are being used in our project :

1. Vectors: Vectors are the same as dynamic arrays with the ability to resize themselves automatically when an element is inserted or deleted, with their storage being handled automatically by the container. Vector elements are placed in contiguous storage so that they can be accessed and traversed using iterators. In vectors, data is inserted at the end. Inserting at the end takes differential time, as sometimes there may be a need of extending the array. Removing the last element takes only constant time because no resizing happens.

For example :

```cpp

    vector<_datatype> _variablename;
    Some basic functions include :
    For a vector<int> v;
    - v.push_back(val);
    - v.pop(val);
    - v.size();

```

For more details check out this link: https://www.cplusplus.com/reference/vector/vector/

2. Unordered-Maps: unordered_map is an associated container that stores elements formed by the combination of key-value and a mapped value. The key value is used to uniquely identify the element and the mapped value is the content associated with the key. Both key and value can be of any type predefined or user-defined.

```cpp

    unordered_map<_datatype1,_datatype2> _variablename;
    Some basic methods for an unordered_map mp include :
    - mp.insert({val1,val2});
    - mp.find(val1)->first = val1
    - mp.find(val1)->second = val2
```

For more details check out this link: https://www.cplusplus.com/reference/unordered_map/unordered_map/

### An inbuilt Database :

Though it sounds very tricky rather it isn't, so what does a database does, in layman terms it helps us search for a particular data or a particular value based on our query, so here our query can be based on keywords which would be the basic constructs of the language which shouldn’t be modified and should inject predetermined code whenever needed in the program this can significantly reduce the time complexity of the code making it more efficient.

A basic implementation of a database will be storing a collection of tuples having a key-value pair to be used to insert code snippets on the go.

For example: let's say I stored a string named HTML having a value of say “#include” or say “import” in java so at first instance it can pop this value to be stored on a container.

Ex-Tuple Container : [{“html”:”#include”},{ “h1”:”headers”} ,.....likewise].

### File Input/Output in programming :

While handling files we should take care of the commands that are used with them, which generally are associated with reading/write operations...

In Read-only operations it can read each line of string which is written in another file and character by character arranges it to form each line in the file

In write operations, we can work out by rendering or parsing the text lines by manipulating the string statements and writing them in a file.

In C++, we have the file operations contained in the header called `#include<fstream>`
which can be included to do the following operations :

    -ifstream = Reading from a file.
    -ofstream = Writing to a file.
    -fstream = to do both the operations.

Basic Syntax :

```cpp
    - Reading:
    string st;
    ifstream myfile("<filename>")
    while(getline(myfile,st)){
        //Here we get each line from the txt file given above
    }
    - Writing:
    ofstream writeIn("<filename>")
    writeIn << /* statement */ <<"\n"

```

For more details on file handling in Cpp checkout: https://www.cplusplus.com/doc/tutorial/files/

In the project, as we shall be writing the code on a .txt file so your transpiler script shall read the esolang-code from the file line by line and parse each line as a collection of characters, so here we shall take each line as an input from the base .txt file and parse it accordingly and store it in a container which shall allow us to make changes in the placement of values whenever writing in the result file at last (this seems unnecessary and rather it is more practical to just inject code inside the output file directly but there's a catch to do so which we'll get through later..)