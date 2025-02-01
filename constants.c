// a constant is a fixed value that cannot be changed
// define using either #define or const keyword

// #define CONSTANT_NAME value


#include <stdio.h>

#define PI 3.14159 //defining a constant

int main() {
    printf("Value of PI: %f\n", PI);
    return 0;
}

// key points

// #define is processed before compilation, meaning it doesn't occupy memory
// no = or ; is used in define
// trying to modify PI in the program will cause an error

//using const

#include <stdio.h>
int main() {
    const float gravity = 9.8; //declaring a constant
    printf("Gravity: %.2f m/s^2\n", gravity);
    // gravity = 10.0; //this will cause an error
    return 0;
}

// key points

// const variables occupy memory like normal variables
// unlike #define, const variables have a specific data type
// any attempt to modify a const variable will cause a compilation error

