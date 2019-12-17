# simple-basic-script-interpreter
A simple and basic scripting language + interpreter, inteded to be an example for educational purposes.
## Keywords in the Language
|Keyword|Definition|
|---|---|
|`#`|Comment|
|`LET`|Defines a variable, optionally provide an initial value.|
|`SET`|Sets a variable to the value of another variable or an integer literal.|
|`PRINT`|Prints out a variable to the standard output.|
|`ADD`|Adds a variable with the value of another variable or an integer literal.|
|`SUB`|Subtracts from a variable the value of another variable or an integer literal.|
|`MUL`|Multiplies a variable with the value of another variable or an integer literal.|
|`DIV`|Divides a variable with the value of another variable or an integer literal.|
|`MOD`|Performs Modulus on a variable with the value of another variable or an integer literal.|
|`INPUT`|Reads an integer from standard input and sets the value of a variable to it.|
|`DO`|Places the "do pointer" at that line.|
|`WHILE_NEQ`|Compares a variable with the value of another variable or an integer literal, and jumps to the "do pointer" if they are not equal.|


It's worth noting that although nested do loops are not possible, you can use multiple `WHILE_NEQ` following a `DO` - and simulate the effect of a nested do loop.
## Provided Example Programs
* `fibonacci.basic`
* `power_of_two.basic`
* `decimal_to_binary.basic`
