## Step 6: Functions

Now implementing functions requires two components of the process that must be implemented in our esolang. One is the statement where the function is defined, and the other being the statement where the function is called in our main function. ( Please note that Creact does not have a single main function wherein all the code resides, but may have multiple functions outside the main function as well just like C/C++).

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

As you can see from the above snippet, the functions are defined using 'fx', which is followed by the return type of the function. The function name takes the parameters of the function, and then we write the function body. 'throw' is the keyword to return a value. (similar to the keyword return in C/C++)

An example of function call syntax in the main function in Creact -

```
    <fx res=gcd_algo(val1,val) />
```

Here, our transpiler understands that a function is being called from 'fx'. We have defined an integer 'res' previously, which will store the returned value from the function 'gcd_algo'. ''val1' and 'val' are the parameters being sent to the function.

We check for the 'fx' term in the statement to check if it is a functional block.

Now, before we start parsing, we need to check if our statement is the definition of the function or the function call in the main function.
If the statement is a function call, we need to parse it in the following way :

```
    <fx res=gcd_algo(val1,val) />      ===========>        res=gcd_algo(val1,val);
```

At this point, this is comparatively one of the simpler parsings that we do, using a temporary string vector. We also need to make sure that if any variables are defined in the statement, we find their respective values from the 'varKey' database that we have predefined.

If the statement is a function definition instead, we parse the return type from 'varKey' and then parse the parameters as done previously.
The body of the function shall be parsed as it is, as our previously defined functions such as arithmetic take care of everything. We do this parsing until we reach the end of the function.

As we are converting our esolang file to a C file, and by the syntax of C we already know that a function defined anywhere in the program should be defined with a function signature at the beginning of the program as shown in an example snippet below :

```c
int func(param); // This is a function signature so for each function defined a signature needs to be added while parsing
int main(){
    func(setter)
}
int func(param){
    //statements
}

```

To execute this task we have to first start extracting the instance of function from the line it is written first in the htpl, say anywhere before the `<main></main>` or even after it, while reading through it, we shall store all such functions in a vector set of strings during the moment that function statement is parsed as the syntax for functions signature is same as that of a function call,

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