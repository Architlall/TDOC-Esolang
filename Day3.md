## Step 3: Implementing arithmetic operations

An esolang is incomplete if it cannot perform all the basic mathematical operations. Since we are following the syntax of HTML, we needed a specific way to tell the transpiler that the following line to be parsed is a mathematical operation. So the operator that we have used is '%'.

```js
    An example of a mathematical statement in Creact :

    <% x = (x+(2*y)/z) %>

```

Achieving this transpilation is significantly simpler than you might be thinking. Note that we are just making a transpiler and not an actual compiler. So we just need to parse the statement and translate it to C/C++ and the GCC call does the rest of the work for us.

So we parse the line after checking the presence of '%' and then transpile the mathematical statement with the help of a temporary vector to push into the parent vector string that must be transpiled. One point of caution in such parsing is checking that the spaces between different terms don't affect the process of parsing. Using the brute force method to check positions will not help and may lead to the code crashing. So instead use a temporary vector to push the different characters.

In conclusion, we perform all the mathematical operations in Creact inside blocks that are labeled with '%' for easier understanding of the transpiler and maintaining the syntax of the language.


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