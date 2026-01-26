# README.md - Printf Project

*This project has been created as part of the 42 curriculum by pcaudron, brouzaud.*

## Description

__Push_Swap__ is a program which permits to sort a set of integer in the most optimal way using only two stacks and operations to manipulate the stacks. It sorts depending of the disorder of the set of integers. The disorder defines how much of the set is already sorted. Depending of the value of the disorder the sorting algorithm will change to optimize the number of operations required.

## Instructions

### Compilation

The project includes a **Makefile** with the following rules:

```
make       # Compiles the library and creates libftprintf.a
make all   # Same as above
make clean # Removes object files
make fclean # Removes all generated files including libftprintf.a
make re    # Recompiles the entire project from scratch
```

### Compilation Flags

All source files are compiled with:
- `-Wall -Wextra -Werror` flags for strict error checking
- `cc` compiler
- No relinking on subsequent builds

### Library Creation

The library is created using the `ar` command (not libtool) and is output as `libftprintf.a` at the repository root.

### Using the Library

To use ft_printf in other projects:

1. Include the header file in your source:
   ```c
   #include "ft_printf.h"
   ```

2. Link against the library during compilation:
   ```
   cc -Wall -Wextra -Werror my_program.c ft_printf.a -o my_program
   ```

## Project Structure

| Functions | Description |
| -------- |:------- |
| `ft_printf`  |**Behave like the printf function of the stdio library** |
| `ft_putchar` | **Write a single character**. |
| `ft_putnbr_hexa` |**Write a number in hexadecimal**. |
| `ft_putnbr_u` |**Write an unsigned int**. |
| `putnbr` |**Write a number in decimal**. |
| `putptr` |**Write the memory adress of a pointer**. |
| `putstr` |**Write a string**. |

## Resources

### Learning References

- **W3Schools C Reference** — Comprehensive documentation on C language fundamentals and standard functions
- **GeeksforGeeks C Tutorials** — Detailed articles on variadic functions
- **Official C Standard Library (man pages)** — Authoritative source for standard function behavior

### AI Usage Disclosure

AI wasn't used in this project.

## Notes
### Explanation and Justification of Algorithm and Data Structure

The algorithm is in two parts: first the conversion and writing of arguments depending of their formats, and a second which go through the given string and converts each arguments using the first function. This algorithm seemed to be the most intuitive.
