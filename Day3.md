## Step 4: Conditional Statements

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

Now to add to more functionality we shall implement nested conditions in the if-else block and differentiate it from the outside marker we shall implement a unique identifier logic that works with the help of indentation, like in the CReact we have made nest if-else block logic work by the help of adding indentation based on the no. of '?' one adds to identify where is the block lying for instance

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

## Step 5: Loops

Loops are an essential programming language utility to instruct the sequence of operations to repeat itself a set number of times or until a certain condition is met. Loops reduce redundancy in code and also the effort to repeat operations in a programming language

In general, the syntax of common loops in modern-day programming languages are

```
Pseudocode :

    FOR(DECLARATION; CONDITION; ITERATION)                  WHILE(CONDITION)
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

Loops have a characteristic tag of '#' and the two loops are differentiated concerning the letter that shows at the start of
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

```js
<# f (var=1,var<5,var++)
    <## f (var1=1,var1<5;var1++)
        Statements
    ##>
#>

```

This way you can nest multiple while loops or for loops in while loops and vice-versa
This process of transpiling is not very different from what is used in conditional statements
