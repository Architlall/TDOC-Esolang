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

Here the 1st thing which is the `<htpl>` tag is a constant keyword identifier, as it will be always written to start coding in your esolang...

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

    [   {   “print()“   }  ,  { “Material to be inserted i.e connected parts of a multiline <log> ” }  ,  {   “;”    }];

```

So it can be parsed as ==========> [ { “ print(“material---------”); “ } ]

and then re-inserted at the head node whereas removing the already present nodes.

This way we can create a simple printing program in our language.

### Automating compilation using makefile and bash scripting

#### Makefile

        Make is a Unix utility that is designed to start the execution of a makefile. A makefile is a special file, containing shell commands, that you create and name makefile (or Makefile depending upon the system). While in the directory containing this makefile, you will typically make and the commands in the makefile will be executed

        Make keeps track of the last time files (normally object files) were updated and only updates those files which are required (ones containing changes) to keep the source file up-to-date.

        With this, you don't have to compile the code repeatedly, a simple make command in the terminal will compile the changed code

#### Bash scripting

    A bash script file is a file containing several bash commands, all of which gets executed once the bash script file is run on the system
    In this project contents of the bash script file include
        1. Changing working directory to Main
        2. make command
        3. Running transpiler binary with the file name
        4. Compiling transpiled program using g++
        5. Executing transpiled binary
        6. Removing transpiled c file and binary
    Bash script files can be run using the command ./script.sh

Note: you might need to allow execution of the bash script in your system by using:` chmod +x script.sh` or ` chmod 777 script.sh`

#### Executing the program

    You need to place a .txt file in the Main folder with contents of CReact code to be executed
    then change directory to root of the project (if you are not already there) then execute the commands

```
chmod +x script.sh
./script.sh input.txt # assuming name of the file is input.txt
```
