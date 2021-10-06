# CReact- An Programmable HyperText Markup Language

“ What if we could hack NASA with HTML!” - a dream of every programmer

Well we took it seriously, so let's make something that could extend HTML beyond its limits, so we went to the GOD of all languages to seek some help, yea it's not python it’s the old age C, and guess what we got ourselves…..

CReact is a brand new crazy language that does all, plus its open-source add more layers to it make it more powerful :)

So we would be building a new esoteric (basically means crazy af) language that gets interpreted to C language and gets compiled to give any result you want: conditionals, loops, characters, arithmetic, functions, recursion...

## Prerequisites :

    1. A tad bit of knowledge on C and CPP both...

    2. Slight overview of bash scripting and makefile.

So here we shall go step by step and understand how to transpile our code in any format to a proper C code for easier reference. We have used a simple language like HTML to work with.

## Step 0 : Basics

### An inbuilt Database :

Though it sounds very tricky rather it isn't, so what does a database does, in layman terms it helps us search for a particular data or a particular value based on our query, so here our query can be based on keywords which would be the basic constructs of the language which shouldn’t be modified and should inject predetermined code whenever needed in the program this can significantly reduce the time complexity of the code making it more efficient.

A basic implementation of a database will be storing a collection of tuples having a key-value pair to be used to insert code snippets on the go.

For example: let's say I stored a string named HTML having a value of say “#include” or say “import” in java so at first instance it can pop this value to be stored on a container.

Ex-Tuple Container : [{“html”:”#include”},{ “h1”:”headers”} ,.....likewise].

### File Input/Output in programming :

While handling files we should take care of the commands that are used with them, which generally are associated with reading/write operations...

In Read-only operations it can read each line of string which is written in another file and character by character arranges it to form each line in the file

In write operations, we can work out by rendering or parsing the text lines by manipulating the string statements and writing them in a file.

In the project, as we shall be writing the code on a .txt file so your transpiler script shall read the esolang-code from the file line by line and parse each line as a collection of characters, so here we shall take each line as an input from the base .txt file and parse it accordingly and store it in a container which shall allow us to make changes in the placement of values whenever writing in the result file at last (this seems unnecessary and rather it is more practical to just inject code inside the output file directly but there's a catch to do so which we'll get through later..)

## Step 1: INITIAL STEPS: WRITING A HELLO WORLD OR PRINTING PROGRAM IN THE ESOLANG

The given eso-lang follows an HTML syntax construct so for example we have used here the following syntax :

```html
<htpl>
  <main>
    <log>Hello World </log>
  </main>
</htpl>
```

The snippet is a very simple code so let's de-structure it to understand the working behind the scenes.

The principal thing is removing the initial spaces from each string line, the reason being we just require what's given the extra spaces will only cause a hindrance so it's better to remove them & only work with what's required...

For this, we can implement a basic loop function that reads the string, and as a character other than " " is encountered would refactor itself...

### Pseudocode

```
    INPUT a string variable
    FOR i in string_var
        IF i != ' '
            string_var = string_var[i,length of string_var-i]
            BREAK

```

Now working with tags:

Here the 1st thing which is the `<htpl>` tag basically is a constant keyword identifier, as it will be always written to start coding in your esolang...

So for that instance, we can store the appropriate code for this specific tag in our globally defined tuple collection, and on recognizing this specific tag can push the appropriate code inside our result container which will be pushed in the parsed file later.

Now in this case we have a string with log as `<log>(word)</log>`, so the only way to parse it is breaking the string in parts and getting the required portion in this case checking for a keyword “log” that in our tuple collection stores a value of PRINT statement,

So using string manipulation extracting the word “log” we can get the statement print identifier of the result programming language; it can be “printf for C”, “System.out.print for Java” or “console.log for Javascript” etc which can be inserted in the container.

Whereas the respective closing tag can be distinguished with a starting 2 indexes of “<\”
It can be replaced by any sequence user likes say “); for C”, or simply “)” for python or Js, in a similar way the material to be inserted can be extracted by manipulating the strings.

Now arises a concern say we are printing a large number of words as shown as :

```html
<log>
  (some words --------------------------------------------
  ------------------------------------------------------------
  --------------------------------------------------end)
</log>
```

Here we can’t simply extract the string in between and work on it as each line is read separately so for this reason we can extract part of the string having the tags opening/closing and adding on to it to construct the whole paragraph present between the log tags…

So this points out that simply parsing and writing in an output file won’t do for that we have another solution which is using that same container in which we are storing the parsed values accordingly in a specific pattern so that it can be arranged to get the desired parsed code in the output file...

The list shall store in the strings inside it which are to be inserted and at the creation and scripting period would be activated to fill in the string nodes line after line.

The printf implementation :

```py

    [	{ 	“print()“	}  ,  {	“Material to be inserted i.e connected parts of a multiline <log> ”	}  ,  {	  “;”	 }];

```

So it can be parsed as ==========> [ { “ print(“material---------”); “ } ]

and then re-inserted at the head node whereas removing the already present nodes.

This way we can create a simple printing program in our language.

## Step 2 : Working with Data Types and Input/Output

Taking user input is a very basic task that is expected of our esolang. For convenience let us assume that we have already declared a variable of integer type (we will see how to do that later in this section).

To understand how to achieve this, our first step is to decide what our user input syntax is going to look like. In CReact, the syntax that we have defined is as follows :

```js
    declare the integer variable named var
    <take var/>
```

Our motive is to parse this syntax in such a way, that the desired output in our C file looks like :

```c
    declared variable var
    scanf("%d",&var);
```

To execute the above-mentioned translation, we use string manipulation to extract the word “take” to get the statement scan identifier of the result programming language(scanf in our case) from the predefined map, which can be inserted in the output file.

Whereas the respective closing tag can be distinguished with a starting 2 indexes of “<\”
It can be replaced by any sequence user likes say “); for C”, or simply “)” for python or Js, in a similar way the material to be inserted can be extracted by manipulating the strings.

Now, very similar to the fashion in which we implemented the print function above, we have to use a dynamic array or list that stores the parsed values.

Say a list has the contents for the print statement parsed as :

```js
 [	{ 	“scanf()“	}  ,  {	“variable_name”	}  ,  {	  “;”	 }];
```

So it can be parsed as ==========> [ { “ scanf(“variable_name---------”); “ } ]
and then re-inserted at the head node whereas removing the already present nodes.

This is how we achieve a basic implementation of user input in our esolang.

Now a programming language is incomplete without providing a base to specify its variables as anything that we write must have a meaning so to use certain variables for different purposes, in CReact an easy and simple method to define data types and introduce similarities with other programming languages we have created some predefined datatypes so that we can work with alphanumeric values :

It is generally defined using keywords like "in" and "ch" with denotes the integer and character respectively in CReact, for making things crazier u can define it yourselves as anything u wish to...

Maintaining the norms of React a variable can be statically initialized with a value under a self-closing bracket value :

### Syntax

```js
    For static allocation :
    < data_type variable_name = value />

    For Dynamically allocation it can be written as :
    < data_type variable_name, variable_name1 />

    Example -> For integers it can be written as :  <in val = 75/>

```

Now to parse this we have to update our tuple data - collection my adding another tuple that can convert the defined identifier to the datatype and while reading the string statement just replace that with the value from the collection and parse that statement into the temporary storage container to push into the file at the end...

The second part comes into initializing the same into our lang of choice when required, for eg in C we use different identifiers when taking input like for

- Integer is denoted by %d in C
- Character is denoted by %c in C

So in the tuple collector, we shall initialize these identifiers with that of respective datatypes and while taking input using **<take var_name />** just write insert
respective identifier and reconfigure the string in the same order as :

```js
    <take var_name/>
    scanf("\\identifier\\",&var_name);

```

As this specific practice is followed in C language and this whole string is inserted into the temp_container to write afterwards in the file...

### Printing Multi Variables

In this language es6 standards for formatting and printing the expression is used here, i.e. using ${varName}

### Syntax

```js
    <log> ${varName1} ${varName2} </log>
```

For example:-

```js
	<htpl>
	    <in a=3,b=4 />
	    <log>
		Printing value of a and b : ${a} ${b}
	    </log>
	</htpl>

```

In the log function, the string between the htpl log tags are parsed into an equivalent format string statement one letter at a time until it has encountered a "${" string

### Pseodocode:

    Function(string param)
        Let str be an empty string to hold result
        Iterate 1 letter at a time over the string
        if (given letter word is equal to '$' and next letter is '{')
    	search for variables declared before with the name between the braces
    	if search was successful
    	    add appropriate modifier to str
    	else
    	    add string including the braces as it is to str
        else
    	add string as it is to str
    Return str

The code in the above example converts into a format string
for eg in C
("Printing value of a and b : %d %d",a,b)
while in python it would look like:
f'Printing value of a and b : {a} {b}'

This formatted string along with with their variable names are passed onto their respective print statements hence facilitating multi-variable output

## Step 3: Conditional Statements

Whenever we have to implement a logic it doesn't end with just mathematical operations, sometimes to check whether what we are working with is logically apt or not generally we use an if-else block that makes it easier to question and follow a certain pathway in that manner.

Any modern-day programming language is always equipped with the power to question a certain course of action and chalk out a working plan accordingly, this helps us execute tasks in a much simpler way and integrate segmented code to make it multi-functional.

In basic programming lang a simple if-else block is generally written as :

```
Pseudocode :

    IF(cond1)
        Execute this part
    ELSE IF(cond2)
        Execute this part
    ELSE
        Execute this last part

```

In our CReact Esolang to make things more intuitive and much simpler to understand we follow the following syntax :

```js
If block clause :

    <? if(cond1)
        statement1
    ?>
    <? elif(cond2)
        statement2
    ?>

```

Take it as a fragment that renders an if-else construct to work with, here we shall first look for the special tag such that the angular brackets have "?" inside it which triggers a function that works with conditionals, here we shall strip down the spaces again, this shall then give us only the required string to work with, after which we shall look for some general keyword associated with conditionals and look for them to properly format the substring to arrange the condition properly and add an opening a "{" then push in the required statements inside temp-container and use the last identifier "?>" that can push in the required the closing bracket as "}".

### A basic conversion:

```js
                       <? if(cond1)              if(cond1){
                           statement1               statement1;
                       ?>                        }

```

Now to add to more functionality we shall implement nested conditions in the if-else block and differentiate it from the outside marker we shall implement a unique identifier logic that works with the help of indentation , like in the CReact we have made nest if-else block logic work by the help of adding indentation based on the no. of '?' one adds to identify where is the block lying for instance

### Example helper

```js

(space)  <?
(space)        if(cond1)
(space)(space)<??
                    if(cond2)
(space)(space)??>
(space)  ?>

```

Here if you can see a pattern if the nested condition increases so does the number of '?' in the tags, this does what is it

    * Firstly helps the interpreter parse the conditionals easily as it will be able to differentiate between the 2 blocks and put the C interpretation more clearly

    * Make code look easier to design.

So that's how we develop the power of conditions in our programming language.

## Step 4: Implementing arithmetic operations

An esolang is incomplete if it cannot perform all the basic mathematical operations. Since we are following the syntax of HTML, we needed a specific way to tell the transpiler that the following line to be parsed is a mathematical operation. So the operator that we have used is '%'.

```js
    An example of a mathematical statement in Creact :

    <% x = (x+(2*y)/z) %>

```

Achieving this transpilation is significantly simpler than you might be thinking. Note that we are just making a transpiler and not an actual compiler. So we just need to parse the statement and translate it to C/C++ and the GCC call does the rest of the work for us.

So we parse the line after checking the presence of '%' and then transpile the mathematical statement with the help of a temporary vector to push into the parent vector string that must be transpiled. One point of caution in such parsing is checking that the spaces between different terms don't affect the process of parsing. Using the brute force method to check positions will not help and may lead to the code crashing. So instead use a temporary vector to push the different characters.

In conclusion, we perform all the mathematical operations in Creact inside blocks that are labeled with '%' for easier understanding of the transpiler and maintaining the syntax of the language.

## Step 5: Loops

Loops are an essential programming language utility to instruct the sequence of operations to repeat itself a set number of times or until a certain condition is met. Loops reduce redundancy in code and also the effort to repeat operations in a programming language

In general, the syntax of common loops in modern-day programming languages are

```
Pseudocode :

    FOR(DECLARATION; CONDITION;ITERATION)                  WHILE(CONDITION)
        Execute Statement                                       Execute Statement

```

## Syntax

In our CReact Esolang to make things more intuitive and much simpler to understand we follow the following syntax :

```js

FOR CLAUSE :                                                WHILE CLAUSE:
                <# f (declaration,condition,iteration)              <# w(condition)
                    Statement                                           Statement
                #>                                                  #>
```

Loops have a characteristic tag of '#' and the two loops are differentiated with respect to the letter that shows at the start of
the loop syntax, which is 'f' referring to for loop while 'w' for while loop, the traspiling program looks specifically for the '#'
symbol to execute a function to parse loops. The function first strips off spaces from the statements and first determines which
category of the loop the statements belong to (i.e. for or while). The statements are then compiled into the compiling programming language
syntax for example:

```c
In C:                                       In python

    for(var=1;var<10;var++)                      for var in range(1,10,1):

    while(var>10)                                while var > 10:

```

the beginning and conclusion of the statements in CReact are determined by the "<#" and "#>" respectively.

## Nested loops

Nested loops are much required in programming languages and in CReact, the level of nesting is described by the number of '#'
in the first line of the loop syntax.

```
<# f (var=1,var<5,var++)
    <## f (var1=1,var1<5;var1++)
        Statements
    ##>
#>

```

This way you can nest multiple while loops or for loops in while loops and vice-versa
This process of transpiling is not very different from what is used in conditional statements

## Step 6: Functions

Now implementing functions requires two components of the process that must be implemented in our esolang. One being the statement where the function is define, and the other being the statement where the function is called in our main function. ( Please note that Creact does not have a single main function wherein all the code resides, but may have multiple functions outside the main function as well just like C/C++).



An example of function definition syntax in Creact -

```
     <fx in gcd_algo(in a,in b)>
        <? if(a==0)
            <throw b/> 
        ?>
        <? else
            <throw gcd_algo(b%a,a)/> 
        ?>
    </gcd_algo>

```

As you can see from the above snippet, the functions are define using 'fx', which is followed by the return type of the function. The function name takes the parameters of the function, and then we write the function body. 'throw' is the keyword to return a value. (similar to the keyword return in C/C++)

An example of function call syntax in the main function in Creact - 

```
    <fx res=gcd_algo(val1,val) />
```

Here, our transpiler understands that a function is being called from 'fx'. We have defined an integer 'res' previously, which will store the returned value from the function 'gcd_algo'. ''val1' and 'val' are the parameters beinf sent to the function. 

We check for the 'fx' term in the statement to check if it is a functional block. 

Now, before we start parsing, we need to check if our statement is the definition of the function, or the function call in the main function.
If the statement is a function call, we need to parse it in the following way :

```
    <fx res=gcd_algo(val1,val) />      ===========>        res=gcd_algo(val1,val);
```
At this point, this is comparatively one of the simpler parsings that we do, using a temporary string vector. We also need to make sure that if any variables are defined in the statement, we find their respective values from the 'varKey' database that we have predefined. 

If the statement is a function definition instead, we parse the return type from 'varKey', and then parse the parameters as done previously.
The body of the function shall be parsed as it is, as our previously defined functions such as arithmetic take care of everything. We do this parsing until we reach the end of the function.


As we are converting our esolang file to a C file , and by syntax of C we already know that a function defined anywhere in the program should be defined with a function signature at the beginning of the program as shown in an example snippet below :

```c
int fund(param); // This is a function signature so for each function defined a signature needs to be added while parsing
int main(){
    func(setter)
}
int func(param){
    //statements
}

```

To execute this task we have to first start extracting the instance of function from the line it is written first in the htpl, say anywhere before the `<main></main>` or even after it , while reading through it , we shall store all such functions in a vector set of strings during moment that function statement is parsed as the syntax for functions signature is same as that of function call,

### Helper snippet :

```js

<main>
    //some statements
</main>
<fx _datatype func_name(_datatype param1) /> //This statement in C becomes _datatype func_name(_datatype param1)
    //inner statements
</func_name>

```

Now as we have the function signature in another vector, while writing the equivalent C code in a file we shall, after insertion of the headers we shall check whether such a vector exists or not, if yes then insert all the signatures at that point else move on with insertion of other parts of the code.

## Step 7: Dynamic Arrays

If you came this far you would surely know how much we have worked with vectors in the whole project, so lets try to make one in esolang, it would work as a normal vector as usual just would be able to work with integers.

To understand how to implement it, lets focus on memory a bit :

In arrays we always statically ask for some contiguous block of memory from the heap, which once given cant be extended further more this restricts it to work further more with humongous amount of data.

So we shall use an easier approach that is allocate each block of memory one at a time and link it up using the address of that block, you must have guessed it right by now, we shall implement a linked list to allocate single block of memory for us and operate on it in a sameway as we do in any normal regular vectors, which is pushing in elements, popping elements out of it, updating any index or searching for item in that index.

In CReact we shall be using a different syntax to implement the dynamic arrays concept i.e

```jsx
    <<$tream _datatype _varname >>//Initializing a dynamic array

    //Some operations to implement here include

    <<_varname.plus(value)>> // To push in elements

    <<_varname.minus(value)>> // To pop out elements

    <% _varname[pos] = val %> // To update the element at that position

    <% c = _varname[pos] %> // To assign a value to a certain variable

```

Now to implement the linkedlists based approach on it, you must be wondering we have to implement linkedlists in Creact but in reality it isn't required, firstly the newer tags `<< >>` makes it easier to separate the IO and function call on dynamic arrays & then start to work on it.

Firstly we shall look for the syntax with `<<$` this will help us recognise that a vector is being initiliazed with this we shall start with the linkedlist part :

In the whole project we are writing the language in a simple txt file and then parsing it and printing in another file , so we shall use the same approach here, write the C code for creation, push, pop, update, show, operaions in a separate file and use it as a helper file and as we find the respective syntax insert the whole code in a vector of strings which is then inserted in the final C file after the header and function signatures such that calling those functions in Creact will be only thing what shall remain then :

Let's try this approach :

```cpp

Folder structure :

|---Main folder
    |---tokenizer.cpp
    |---helper.txt

In helper.txt :
//BASIC LINKED LIST NODE CREATION SNIPPET
#include<stdlib.h>
struct Node {
    int data;
    struct Node *next;
}
struct Node *createNode(struct Node *root){
    root = (struct Node*)malloc(sizeof(struct Node));
    return root;
}

In tokenizer.cpp

ifstream._varname("helper.txt");
while(getline(_varname, localstring)){
    store in vector of strings;
}
ofstream.writeIn(result_file);

```

hence using this approach we can work with initilizing...

Now for functions like push, pop and others we have to define more functions in helper.txt & call them appropriately....
One more problem that can be faced here is of a basic operation which will fail that is : `v[position] = x`, as the above data
structure is a linkedlist so directly calling the positions is not permitted for that we have to tweak our already set functions in such a way so that it can recognise the call and act according to the function which is being asked to implement :

Lets see exactly what we are talking about :

In linked list to reach a specific position we have to always scan it linearly in any measure to do so, as they are connected by certain addresses and are separate blocks of memory so to link them we have to go through each of the nodes one by one,.

Now to work on it :

```cpp
    //1st statement
    vec[position] = x;  // This means updating the block at that position.

    x = vec[position];  // This means assigning a variable with the value at that position.

```

To work on this we have to keep in mind the position of the equals symbol and parse it carefully as it calls a function very differently like for example :

```cpp

   To write vector[position] = x , where vector is the dynamic array name, x is a variable
   In Creact we write it as : <% vector[position] = x %>
   In C we would write it as : update(&root_node, position, value), where root_node is the headnode;

```

In similar way we follow up with the assigning feature and parse accordingly.