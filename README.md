Authors: Austine Abine and Jotham Josiah

Monty Interpreter
This is a Monty bytecode interpreter written in C.

Usage
To use the interpreter, first compile the source code using gcc:

$ gcc -Wall -Werror -Wextra -pedantic *.c -o monty
This will generate an executable file called monty. You can then run the interpreter on a Monty bytecode file:

$ ./monty filename.m
Supported Opcodes
The interpreter supports the following opcodes:

push
pall
pint
pop
swap
add
nop
sub
div
mul
mod
pchar
pstr
rotl
rotr
Data Structures
The interpreter uses two data structures to store the stack: a singly linked list and a doubly linked list. The default data structure is the singly linked list, but you can switch to the doubly linked list using the queue opcode.

Examples
Here are some examples of Monty bytecode programs:

push 1
push 2
push 3
pall
pop
pall
This program pushes the values 1, 2, and 3 onto the stack, prints the entire stack, pops the top value off the stack, and then prints the stack again.

push 1
push 2
push 3
queue
push 4
pall
This program pushes the values 1, 2, and 3 onto the stack, switches to the doubly linked list, pushes the value 4 onto the stack, and then prints the entire stack.
