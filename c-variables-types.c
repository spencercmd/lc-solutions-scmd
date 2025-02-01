//variables and types
// variable is a named memory allocation used to store data.
// it allows us to work with values dynamically rather than
// hardcoding values into the program.

// c support different data types to store different kinds of values

// integer, int, 4 bytes
// float, 4 bytes
// double, 8 bytes
// char, 1 byte
// boolean, 1 byte
// void, no type

// Note: The size of int and other types depends on the system architecture (32-bit or 64-bit).
#include <stdio.h>

int main() {
    int age = 25; //integer variable
    float height = 5.9; //float
    char initial = 'J'; //char

    printf("Age: %d\n", age); //%d placeholder for an int
    printf("Height: %.1f\n", height); //%.1f for floats (%.1f limits to a single decimal place)
    printf("Initial: %c\n", initial); //%c for char type.

    return 0;
}

// you can control decimal places in floating-point numbers:

// printf("%.2f", 3.14159) //prints 3.14

