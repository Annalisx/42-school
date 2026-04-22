*This project has been created as part of the 42 curriculum by acastald*

# Push_swap

## Description
The `Push_swap` project is a fundamental challenge in the 42 curriculum. The core objective is to sort data (a stack of integers) using a limited set of instructions and the lowest possible number of actions.. 

By implementing this, I gained a deep understanding of how data is managed in the stack, how type lists works in C.

The program receives a list of random integers as arguments. Initially, all numbers are loaded into Stack A, while Stack B is empty. The objective is to have all numbers in Stack A sorted in ascending order using a specific set of allowed moves.

### Allowed moves
| Operation | Description |
| :--- | :--- |
| `pa` | Take the first element at the top of B and put it at the top of A. |
| `pb` | Take the first element at the top of A and put it at the top of B. |
| `sa` | Swap the first 2 elements at the top of stack A. |
| `sb` | Swap the first 2 elements at the top of stack B. |
| `ss` | sa and sb at the same time. |
| `ra` | Shift up all elements of stack A by 1. The first element becomes the last one. |
| `rb` | Shift up all elements of stack B by 1. The first element becomes the last one. |
| `rr` | ra and rb at the same time. |
| `rra` | Shift down all elements of stack A by 1. The last element becomes the first one. |
| `rrb` | Shift down all elements of stack B by 1. The last element becomes the first one. |
| `rrr` | rra and rrb at the same time. |

---

## Instructions

### Compilation
The project is managed by a `Makefile` that complies with the 42 Norm. To compile the library, use:

make - compiles source files into object files and creates the library.
make clean -  removes all generated object files but keeps the library.
make fclean - removes object files and the libftprintf.a file.
make re - executes fclean followed by make (clean recompilation).

### Execution
Run the program by passing a list of integers as arguments. The numbers must not be duplicated and must be within INT_MIN and INT_MAX limits.

## Resources

During this project, I watched videos on Youtube to understand better the Turk algorithm, peers from 42 also made me understand how optimize the project and I used an AI for for minor bugs, assistance in structuring and for this README to meet specific curriculum requirements while maintaining professional formatting.

---

### Algorithm Structures
Declaring two pointers for stacks A and B. Initialized to NULL to prevent undefined behavior and signify empty stacks.

Checks that the inputs are valid (it works even if the input is a string, by splitting it), have no duplicates, and are within integer limits.

Inizialize the stack A, taking the numbers and loading them into nodes in a linked list.

Check if the stack is sorted in ascending order, if not I check how many node i have, if there are 2 number i swap them, if there are 3 i use the sort three algorithm and if there are more i implement the Turk algorithm.

In the turk algorithm I push the numbers to Stack B, leaving only 3 numbers in A to sort them quickly.

If there are only 3 number in the stack B i use sort three algorithm to make them in descending order (this is useful only in few cases tho).

For each number in B, find the correct target in A (the closest greater number, if there is no greater number is the minimum value)

The "cost" in moves to bring both the node and its target to the top of their respective stacks is calculated.

Then before pushing the node back to A i have to find which one is the 'cheapest' between the push cost of all the nodes.

When i know which one i have to push, i check if it is above the median or not, to maximize the efficiency.

Stack A is rotated one last time to bring the smallest number to the top.
