// can use scanf to get user input

#include <stdio.h>

int main() {
    int age;
    printf("Enter your age: ");
    scanf("%d", &age); //taking integer input
    printf("You are %d years old.\n", age);
    return 0;
}

//scanf("%d", &age); %d tells scanf to expect an integer input.
// the & address-of operator is required because scanf() needs to store the input
// at the memory address of age.

// taking float input

#include <stdio.h>

int main() {
    float temperature;
    printf("Enter the temperature in Celsius: ");
    scanf("%f", &temperature);
    printf("The temperature in Fahrenheit is %.2f\n", temperature * 1.8 + 32);
    return 0;

}

// %f is used for float values in scanf
// Use & before the variable name when using scanf
