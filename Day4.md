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
