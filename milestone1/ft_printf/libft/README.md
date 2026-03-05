*This project has been created as part of the 42 curriculum by acastald.*

# libft

## Description

`libft` is the first project of the 42 School curriculum.
The goal is to create a custom C library named `libft.a` from scratch. This library serves as a foundational toolset for future projects, as we are often not allowed to use standard C library functions (like `printf`, `strlen`, etc.) in the 42 curriculum.

This project enforces a deep understanding of standard functions, memory management, and basic data structures (Linked Lists).

This library is intended to be reused in future projects at 42, serving as a personal foundation of reliable and well-tested functions.

## Library Overview

The `libft` library includes reimplementations of standard C functions, along with additional helpers commonly used in later projects.

### Libc Functions
Re-implementation of standard C library functions.

| Function | Description |
| :--- | :--- |
| `ft_isalpha` | Checks for an alphabetic character. |
| `ft_isdigit` | Checks for a digit (0 through 9). |
| `ft_isalnum` | Checks for an alphanumeric character. |
| `ft_isascii` | Checks whether c fits into the ASCII character set. |
| `ft_isprint` | Checks for any printable character. |
| `ft_strlen` | Calculates the length of a string. |
| `ft_memset` | Fills memory with a constant byte. |
| `ft_bzero` | Zeroes a byte string. |
| `ft_memcpy` | Copies memory area. |
| `ft_memmove` | Copies memory area (handling overlaps). |
| `ft_strlcpy` | Copies string to a specific size. |
| `ft_strlcat` | Concatenates string to a specific size. |
| `ft_toupper` | Converts char to uppercase. |
| `ft_tolower` | Converts char to lowercase. |
| `ft_strchr` | Locates character in string. |
| `ft_strrchr` | Locates character in string (from the end). |
| `ft_strncmp` | Compares two strings. |
| `ft_memchr` | Scans memory for a character. |
| `ft_memcmp` | Compares memory areas. |
| `ft_strnstr` | Locates a substring in a string. |
| `ft_atoi` | Converts a string to an integer. |
| `ft_calloc` | Allocates memory and sets its bytes' values to 0. |
| `ft_strdup` | Creates a duplicate for the string passed as parameter. |

### Additional Functions
Functions that are either not in the libc, or part of it but in a different form.

| Function | Description |
| :--- | :--- |
| `ft_substr` | Allocates and returns a substring from the string 's'. |
| `ft_strjoin` | Allocates and returns a new string, result of the concatenation of 's1' and 's2'. |
| `ft_strtrim` | Allocates and returns a copy of 's1' with the characters specified in 'set' removed from the beginning and the end of the string. |
| `ft_split` | Allocates and returns an array of strings obtained by splitting 's' using the character 'c' as a delimiter. |
| `ft_itoa` | Allocates and returns a string representing the integer received as an argument. |
| `ft_strmapi` | Applies the function 'f' to each character of the string 's' to create a new string. |
| `ft_striteri` | Applies the function 'f' to each character of the string 's'. |
| `ft_putchar_fd` | Outputs the character 'c' to the given file descriptor. |
| `ft_putstr_fd` | Outputs the string 's' to the given file descriptor. |
| `ft_putendl_fd` | Outputs the string 's' to the given file descriptor, followed by a newline. |
| `ft_putnbr_fd` | Outputs the integer 'n' to the given file descriptor. |

### Linked Lists
Functions to manipulate lists.

| Function | Description |
| :--- | :--- |
| `ft_lstnew` | Allocates and returns a new element. |
| `ft_lstadd_front` | Adds the element 'new' at the beginning of the list. |
| `ft_lstsize` | Counts the number of elements in a list. |
| `ft_lstlast` | Returns the last element of the list. |
| `ft_lstadd_back` | Adds the element 'new' at the end of the list. |
| `ft_lstdelone` | Takes as a parameter an element and frees the memory of the element’s content. |
| `ft_lstclear` | Deletes and frees the given element and every successor of that element. |
| `ft_lstiter` | Iterates the list 'lst' and applies the function 'f' to the content of each element. |
| `ft_lstmap` | Iterates the list 'lst' and applies the function 'f' to the content of each element to create a new list. |

All functions are written in C and follow the constraints and coding standards imposed by the 42 school.

## Instructions

Do make and then cc -Wall -Wextra -Werror *.c libft.a 

## Resources

Linux manual pages, peers from 42, myself and AI for minor bugs and help with making this README
