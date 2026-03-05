*This project has been created as part of the 42 curriculum by acastald*

# ft_printf

## Description
The `ft_printf` project is a fundamental challenge in the 42 curriculum that requires recoding the standard C `printf` function. The core objective is to master **variadic functions** and build a robust extensible formatting engine. 

By implementing this, I gained a deep understanding of how data is managed in the stack, how type promotion works in C, and how to handle complex memory addresses.

### ✨ Supported Conversions
| Specifier | Description |
| :--- | :--- |
| `%c` | Prints a single character |
| `%s` | Prints a string of characters |
| `%p` | Prints a pointer address in hexadecimal |
| `%d` | Prints a decimal (base 10) number |
| `%i` | Prints an integer in base 10 |
| `%u` | Prints an unsigned decimal (base 10) integer |
| `%x` | Prints a number in hexadecimal (base 16) lowercase format |
| `%X` | Prints a number in hexadecimal (base 16) uppercase format |
| `%%` | Prints a percent sign |

---

## Instructions

### Compilation
The project is managed by a `Makefile` that complies with the 42 Norm. To compile the library, use:

make - compiles source files into object files and creates the library.
make clean -  removes all generated object files but keeps the library.
make fclean - removes object files and the libftprintf.a file.
make re - executes fclean followed by make (clean recompilation).

## Resources

During this project, I watched videos on Youtube tu understand better the variadic functions, peers from 42 and I used an AI for for minor bugs and assistance in structuring this README to meet specific curriculum requirements while maintaining professional formatting.

---

### Algorithm and Data Structures

#### Data Structure: va_list
The core of the project relies on the va_list data structure provided by <stdarg.h>. This structure allows the function to access a variable number of arguments passed after the format string. The macros va_start, va_arg, and va_end are used to initialize, retrieve, and clean up the argument list.

#### Algorithm
Recursive Base Conversion: For numeric conversions (%d, %x, etc.), I implemented a recursive algorithm to handle base-n division. This avoids the need for large temporary buffers and naturally handles the order of digits from most significant to least significant.

#### Technical Choices
Casting for %c: since the arguments are retrieved as int due to default argument promotion in variadic functions and then cast to unsigned char for safe output.
Pointer Handling: the address is treated as an unsigned long long to ensure compatibility with 64-bit architectures, then converted to hexadecimal with a 0x prefix.