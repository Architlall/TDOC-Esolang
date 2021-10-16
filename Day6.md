## Step 7: Dynamic Arrays

If you came this far you would surely know how much we have worked with vectors in the whole project, so let's try to make one in esolang, it would work as a normal vector as usual just would be able to work with integers.

To understand how to implement it, let's focus on memory a bit :

In arrays, we always statically ask for some contiguous block of memory from the heap, which once given cant be extended furthermore this restricts it to work furthermore with a humongous amount of data.

So for this, we have to delve deep into the domain of memory management, and one of the chief reasons we're working on this project in C/C++ is because memory management is offered best by C/C++ due to the age-old concept of pointers.
In C we have 2 very interesting functions in stdlib.h library which include the malloc & realloc see their definition bellow :

1. malloc() :- The “malloc” or “memory allocation” method in C is used to dynamically allocate a single large block of memory with the specified size. It returns a pointer of type void which can be cast into a pointer of any form.

Syntax : `ptr = (cast-type*) malloc(byte-size)`

2. realloc() :- “realloc” or “re-allocation” method in C is used to dynamically change the memory allocation of a previously allocated memory. In other words, if the memory previously allocated with the help of malloc or calloc is insufficient, realloc can be used to dynamically re-allocate memory.

Syntax : `ptr = realloc(ptr, newSize)` ,where ptr is an previously allocated pointer

So how can we use these functions to implement dynamic arrays, basically we will be using a pointer by allocating a fixed amount of space initially, say 2 blocks of memory, and to keep things simple we shall be using an integer array, so say :

```cpp
int* ptr = (int*)malloc(sizeof(int)*2);

```

This allocates 2 blocks of memory to the ptr variable to store 2 values, but say we have to enter more variables so we shall be using realloc module and reallocating ourselves more space for comfort it shall be double the present size of the array, so initially, if it is 2 it shall become 4, then 8, 16 likewise :

```cpp
ptr = (int*)realloc(ptr,sizeof(int)*present_size*2)

```

Likewise, the extended memory allocation works, but remember this reallocation can work effectively when used in the present block of memory is completely used up, so we can use an if-else block to keep a check and insert if and only if the present allocated space is completely used up.

Now in our CReact how shall we implement this, for dynamic arrays we are using a special syntax and tags which include :

Syntax `<<stream::(_datatype) _varname>>`

This initializes a pointer variable as shown as well as allocates the constant 2 blocks memory as well as can be programmed to trigger the insertion of important headers in the program like `stdlib.h` or any preprocessor derivatives.

Now, this is not the only thing that shall complete the allocation completely as we have to put in more layers to the code,

1. Firstly, say a user initializes 10 such dynamic arrays each can be initialized with the same size i.e 2 but while working on the push/pop operations the total size of each array might vary considering that fact the variable that works as size-reallocator, should be assigned a unique value that should only control the size of that specific array...

2. Secondly say an array initially 2, extended to 16 sizes and filled with only 10 elements, so while operating why should we work with that extra 6 spaces as a pop function will give errors at that part, so we shall be using a flag-pointer that shall always point to the last element pushed inside and if more are pushed inside then do a flag++ with that of the pointer else on popping flag-- to get the required answer, moreover the counter-flag for each array should also be unique as several elements in them can vary as well.

This shall help with the proper allocation.

Now, let's move to its functions, we have :

    - plus() : To push in values, but there is a check if the size is full/not, because then we have to reallocate, now unlike in a loop, it can be called anywhere so for that reason, we have to constantly check whether the size limit is reached because then we have to apply an if-else check which on each push operation would make it more cumbersome, so we shall write the important functions in a helper.txt file and write those functions in the main file just after the headers, as it shall help in quick reallocation and prevent writing an if-else check before each push-back.

    - minus() : To pop out elements, we have to work with the counter-flag which shall decrease by 1 automatically if a function is encountered.

    -show() : As this is a regular function so we shall insert it with the reallocation construct from a file to display the number of elements up to the flag.

To work with them we shall manipulate the strings and display them in the correct format :

For example :

```cpp

    v.plus(x);      ===============>    *(v+cnt++) = x; , where cnt is the counter flag

```

Now lastly 2 other operations that should work on it are updating a specific position & assigning the value of a specific block of the array to a variable, as both come under the mathematical/logical operations so it is done using the `<% %>` tags :

For example :

```cpp

Update operations :

    v[position] = x;    ===============>    *(v+position) = x;

Assigning Operations :

    x = v[position];    ===============>    x = *(v+position);

```

Now to parse it correctly we can look for the position of '=', divide the strings into 2 halves then on each half tokenize the parts like a variable name, value and place it accordingly.

So that's how we can work with dynamic arrays in CReact.