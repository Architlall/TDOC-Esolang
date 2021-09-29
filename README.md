# CReact- An Programmable HyperText Markup Language


“ What if we could hack NASA with HTML!”  - dream of every programmer

Well we took it seriously, so lets make something which could extend HTML beyond its limits, so we went to the GOD of all languages to seek some help, yea its not python it’s the old age C, and guess what we got ourselves…..

CReact a brand new crazy language that does all , plus its open source add more layers to it make it more powerful :)

So we would be building a new esoteric (basically means crazy af) language that gets interpreted to C language and gets compiled to give any result you want: conditionals , loops, characters, arithmetic, functions, recursion..

## Prerequisites :

    1. A tad bit knowledge on C and CPP both..

    2. Slight overview of bash scripting and makefile.


So here we shall go step by step and understand how to transpile our code in any format to a proper C code for easier reference. We have used a simple language like HTML to work with.
## Step 0 : Basics 

### An inbuilt Database :

Though it sounds very tricky but actually isn't, so what does a database does, in layman terms it helps us search for a particular data or a particular value based on our query, so here our query can be based on keywords which would be the basic constructs of the language which shouldn’t be modified and should inject predetermined code whenever needed in the program this can significantly reduce the time complexity of the code making it more efficient.

A basic implementation of a database will be storing a collection of tuples having a key-value pair to be used to insert code snippets on the go.

For example : let's say I stored a string named HTML having a value of say “#include” or say “import” in java so at first instance it can pop this value to be stored on a container.

Ex-Tuple Container : [{“html”:”#include”},{ “h1”:”headers”} ,.....likewise].


### File Input/Output in programming : 

Now this is one of the most important portions of the code, as we shall be writing the code on a .txt file so your transpiler shall read the esolang-code from the file line by line and parse each line as collection of characters.

While handling files we should take care of the commands that are used with them,which generally are associated with read/write operations..

In Read only operations it can read each line of string which is written in another file and character by character arranges it to form each line in the file

In Write Operations we can modify the file by inscribing out given texts in the file and changing the file from the parent file.

In the given objective we shall use both operations , first reading from the input txt file and parsing each sentence and writing it on another file which is compiled as a C file then gives the output.

## Step 1 : INITIAL STEPS : WRITING A HELLO WORLD OR PRINTING PROGRAM IN  THE ESOLANG


The given eso-lang follows a HTML syntax construct so for example we have used here the following syntax : 

```
<htpl>
    <log>Hello World </log>
</htpl>

```
Now in this code we are just printing a statement but initial setting is also of utmost importance.
For example the initial tag “<htpl>” this can help us include a basic syntactical header to start with coding as in any kind of input file htpl tag is permanent so here this string can be stored in the tuple database and can be used to return a set of other strings that begins to code in the preferred language.


### Pseudocode : 

Function(string_param)

    Search in the collection of tuples for the matching tag here htpl as a key

    Returns a value stored as a second parameter in the tuple

Write the value to the output file.


Now, the next line in the filereader reads is the <log> line here, we observe there is a huge number of spaces before it , so this might take unusual time to get to the actual value as these spaces in a hypothetical situation can reach any number so to increase the efficiency of the code as well as make it easier to work with any language we shall strip the spaces from each of the string lines and make it possible for use to work only with the required fields.
This can be done using a helper function that takes in a string and returns a string stripped of initial spaces…

### Pseudocode :

Function(string param)
	Iterate via the string 
		Remove spaces until a character is found
Return result_string

Now in this case we have a string with log as <log>(word)</log>, so the only way to parse it is breaking the string in parts and getting the required portion in this case checking for a keyword “log” that in our tuple collection stores a value of PRINT statement,

So using string manipulation extracting the word “log” we can get the statement print identifier of the result programming language; it can be “printf for C”, “System.out.print for Java” or “console.log for Javascript” etc which can be inserted in  the output file.

Whereas the respective closing tag which can be distinguished with a starting 2 indexes of “<\”
It can be replaced by any sequence user likes say “); for C”, or simply “)” for python or Js, in similar way the material to be inserted can be extracted by manipulating the strings.

Now arises a concern if we are constantly just checking then parsing appropriately and writing to the output file there’s high chance we won’t get another chance to modify the data is required say we have printing as :
Bordercase to consider : 
```

<log> (some words --------------------------------------------
	------------------------------------------------------------
	--------------------------------------------------end)
</log>

```

Here we can’t simply extract the string in between and work on it as each line is read separately so for this reason we can extract part of the string having the tags opening/closing and adding on to it to construct the whole string…

So this points out that simply parsing and writing in an output file won’t do for that we have another solution which is using a dynamic array or list that stores the parsed values in their pattern so that if there are some deeper manipulations required then we can handle that before scripting it on the output file.
The list shall store in the strings inside it which is to be inserted and at the creation and scripting period would be activated to fill in the string nodes line after line.

A basic example : 

Say a list has the contents for the print statement parsed as :
```

 [	{ 	“print()“	}  ,  {	“Material to be inserted”	}  ,  {	  “;”	 }];

```

So it can be parsed as ==========>  [ { “ print(“material---------”); “ } ] 
and then re-inserted at the head node whereas removing the already present nodes.

This way we can create a simple printing program in our language.
 
## Step 2 : Working with Data Types and  Input/Output

//Take vars here...........


Now a programming language is incomplete without providing a base to specify its variables as anything that we write must have a meaning so to use certain variables for different purposes, in CReact an easy and simple method to define data types and introduce similarity with other programming languages we have created some predefined datatypes so that we can work with alphanumeric values :

It is generally defined using keywords like "in" and "ch" with denotes the integer and character respectively in CReact , for making things more craxy u can define it yourselves as anything u wish to..

Maintaing the norms of React a variable can be statically initialised with a value under a self closing bracket value : 

### Syntax

```
    For static allocation : 
    < data_type variable_name = value />

    For Dynamically allocation it can be written as : 
    < data_type variable_name, variable_name1 />

    Example -> For integers it can be written as :  <in val = 75/> 

```

Now to parse this we have to update our tuple data - collection my adding another tuple that can convert the defined identifier to the datatype and while reading the string statement just replace that with the value from the collection and parse that statement into the temporary storage container to push into the file at the end..

The second part comes into initializing the same into our lang of choice when required , for eg in C we use different identifiers when taking input like for
 
* Interger is denoted by %d in C
* Character is denoted by %c in C

So in the tuple collector we shall initialize these indentifiers with that of respective datatypes and while taking input using **<take var_name />** just write insert
respective identifier and re configure the string in the same order as : 

```
    <take var_name/>
    scanf("\\identifier\\",&var_name);
    
```
As this specific practice is followed in C language and this whole string is inserted into the temp_container to write afterwards in the file...

### Printing Multi Variables

In this language es6 standards for formatting and printing the expresstion is used here, i.e. using ${varName}

### Syntax
	
    ```
        <log> ${varName1} ${varName2} </log>
    ```

For example :-
	
```
	<htpl>
	    <in a=3,b=4 />
	    <log>
		Printing value of a and b : ${a} ${b}
	    </log>
	</htpl>
	
```

In the log function the string between the htpl log tags are parsed into an equivalent format string statement one letter at a time until it has encountered a "${" string  

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
