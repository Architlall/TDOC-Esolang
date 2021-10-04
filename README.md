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


While handling files we should take care of the commands that are used with them,which generally are associated with read/write operations..

In Read only operations it can read each line of string which is written in another file and character by character arranges it to form each line in the file

In write operations, we can work out by rendering or parsing the text lines by manipulating the string statements and writing them in a file.

In the project as we shall be writing the code on a .txt file so your transpiler script shall read the esolang-code from the file line by line and parse each line as collection of characters, so here we shall take each line as an input from the base .txt file and parse it accordingly and store it in a container which shall allow us to make changes in the placement of values whenever writing in th result file at last (this seems un-necessary and rather it is more practical to just inject code inside the output file directly but there's a catch to do so which we'll get through later..)

## Step 1 : INITIAL STEPS : WRITING A HELLO WORLD OR PRINTING PROGRAM IN  THE ESOLANG


The given eso-lang follows a HTML syntax construct so for example we have used here the following syntax : 

```

    <htpl>
        <main>
            <log>Hello World </log>
        </main>
    </htpl>

```
The snippet is a very simple code so lets de-structure it to understnad the working bts.

The principle thing is removing the initial spaces from each string line, reason being we just require what's given the extra spaces will only cause a hindrance so its better to remove them & only work with what's required..

For this we can implement a basic loop function that reads the string and as a character other than "  " is encountered would refactor itself..

### Pseudocode 

```
    INPUT a string variable
    FOR i in string_var
        IF i != ' '
            string_var = string_var[i,length of string_var-i]
            BREAK

``` 

Now working with tags:

Here the 1st thing which is the `` <htpl> `` tag basically is a constant keyword identifier, as it will be always wriiten to start coding in your esolang..

So for that instance we can store the appropriate code for this specific tag in our globally defined tuple collection and on recognising this specific tag can push the appropriate code inside our result-container which will be pushed in the parsed file later.

Now in this case we have a string with log as `` <log>(word)</log> ``, so the only way to parse it is breaking the string in parts and getting the required portion in this case checking for a keyword “log” that in our tuple collection stores a value of PRINT statement,

So using string manipulation extracting the word “log” we can get the statement print identifier of the result programming language; it can be “printf for C”, “System.out.print for Java” or “console.log for Javascript” etc which can be inserted in the container.

Whereas the respective closing tag which can be distinguished with a starting 2 indexes of “<\”
It can be replaced by any sequence user likes say “); for C”, or simply “)” for python or Js, in similar way the material to be inserted can be extracted by manipulating the strings.

Now arises a concern say we are printing a large number of words as shown as :

```

<log> (some words --------------------------------------------
	------------------------------------------------------------
	--------------------------------------------------end)
</log>

```

Here we can’t simply extract the string in between and work on it as each line is read separately so for this reason we can extract part of the string having the tags opening/closing and adding on to it to construct the whole paragraph present between the log tags…

So this points out that simply parsing and writing in an output file won’t do for that we have another solution which is using that same conatiner in which we are storing the parsed values accordingly in a specific pattern so that it can be arranged to get the desired parsed code in the output file..

The list shall store in the strings inside it which is to be inserted and at the creation and scripting period would be activated to fill in the string nodes line after line.

The printf implementation : 


```

    [	{ 	“print()“	}  ,  {	“Material to be inserted i.e connected parts of a multiline <log> ”	}  ,  {	  “;”	 }];

```

So it can be parsed as ==========>  [ { “ print(“material---------”); “ } ] 

and then re-inserted at the head node whereas removing the already present nodes.

This way we can create a simple printing program in our language.


## Step 2 : Working with Data Types and  Input/Output



Taking user input is a very basic task that is expected of our esolang. For convinience let us assume that we have already declared a variable of integer type (we will see how to do that later in this section).

To understand how to achieve this, our first step is to decide what our user input syntax is going to look like. In CReact, the syntax that we have defined is as follows :

```
    declare the integer variable named var
    <take var/>
```

Our motive is to parse this syntax is such a way, that the desired output in our C file looks like :

```
    declared variable var
    scanf("%d",&var);
```

To execute the above mentioned translation, we use string manipulation to extract the word “take” to get the statement scan identifier of the result programming language(scanf in our case) from the predefined map, which can be inserted in the output file. 

Whereas the respective closing tag which can be distinguished with a starting 2 indexes of “<\”
It can be replaced by any sequence user likes say “); for C”, or simply “)” for python or Js, in similar way the material to be inserted can be extracted by manipulating the strings.

Now, very similar to the fashion in which we implemented the print function above, we have to use a dynamic array or list that stores the parsed values.

Say a list has the contents for the print statement parsed as :
```
 [	{ 	“scanf()“	}  ,  {	“variable_name”	}  ,  {	  “;”	 }];
```

So it can be parsed as ==========>  [ { “ scanf(“variable_name---------”); “ } ] 
and then re-inserted at the head node whereas removing the already present nodes.

This is how we achieve a basic implementation of user input in our esolang.



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

## Step 3: Conditional Statements

Whenever we have to implement a logic it doesn't end with just mathematical operations, sometimes to check whether what we are working with is logically apt or not generally we use an if-else block that makes it easier to question and follow a certain pathway in that manner.

Any mordern day programming language is always equipped with the power to question a certain course of action and chalk out a working plan accordingly, this helps us execute tasks in a much more simpler way and integrate segmented code to make it multi functional.

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

In our CReact Esolang to make things more intutive and much more simpler to understand we follow the following syntax :

```
If block clause :

    <? if(cond1)
        statement1
    ?>
    <? elif(cond2)
        statement2
    ?>

```

Take it as a fragment that renders an if else construct to work with, here we shall first look for the special tag such that the angular brackets have "?" inside it which triggers a function that works with conditionals, here we shall strip down the spaces again, this shall then give us only the required string to work with, after which we shall look for some general keyword associated with conditionals and look for them to properly format the substring to arrage the condition properly and add an opening a "{" then push in the required statements inside temp-container and use the last identifier "?>" that can push in the required the closing bracket as "}".
 
### A basic conversion:

 ```
                        <? if(cond1)              if(cond1){
                            statement1               statement1;
                        ?>                        }

 ```

Now to add to more functionality we shall implement nested conditions in the if-else block and differentiate it from the outside marker we shall implement a unique identifier logic that works with the help of indendation , like in the CReact we have made nest if-else block logic work by the help of adding indendation based on the no. of '?' one adds to identify where is the block lying for instance

### Example helper 

```
(space)  <?
(space)        if(cond1)
(space)(space)<??
                    if(cond2)        
(space)(space)??>
(space)  ?>

```

Here if you can see a pattern if the nested condition increases so does the number of '?' in the tags this does what is it 

    * Firstly helps the interpreter parse the conditionals easily as it will be able to differentiate between the 2 blocks and put the C interpretation more clearly

    * Make code look more easier to design.

So that's how we develop the power of conditions in our programming language.


## Step 2 : Implementing arithmetic operations

An esolang is clearly incomplete if it cannot perform all the basic mathematical operations. Since we are following the syntax of HTML, we needed a specific way to tell the transpiler that the following line to be parsed is a mathemtical operation. So the operator that we have used is '%'.

```
    An example of a mathematical statement in Creact :

    <% x = (x+(2*y)/z) %>
    
```

Achieving this transpilation is significantly simpler than you might be thinking. Note that we are just making a transpiler and not an actual compiler. So we just need to parse the statement and translate it to C/C++ and the gcc call does the rest of the work for us. 

So we parse the line after checking the presence of '%', and then transpile the mathematical statement with the help of a temporary vector to push into the parent vector string that must be transpiled. One point of caution in such parsing is checking that the spaces between different terms don't affect the process of parsing. Using the brute force method to check positions will not help and may lead to the code crashing. So instead use a temporary vector to push the different characters.

In conclusion, we perform all the mathematical operations in Creact inside blocks that are labelled with '%' for easier understanding of the transpiler and maintaining the syntax of the language. 




