/*
 * Jakub Olszewski
 * 23710521
 * 31/10/2023
 */

#include <stdio.h>
#include "string.h"
// Defining constants
#define PI 3.14
// Defining macros for calculating areas of given shapes
#define triangleArea(heigh, base) (float)((heigh*base)/2.0)
#define rectangleArea(length, width) (float)(length*width)
#define circleArea(radius) (float)(PI*radius*radius)
#define trapeziumArea(height, base1, base2) ((float)(height*(base1+base2))/2.0)


// Function performing area calculation for triangle
void triangle() {
    int height;
    int base;
    do {
        puts("Enter height (a positive integer):");
        scanf("%d", &height);
    } while (height <= 0); // Check if height is not positive
    do {
        puts("Enter base (a positive integer):");
        scanf("%d", &base);
    } while (base <= 0); // Check if base is not positive
    printf("Area of triangle is: %.2f \n", triangleArea(height, base));
}

// Function performing area calculation for rectangle
void rectangle() {
    int length;
    int width;
    do {
        puts("Enter length (a positive integer):");
        scanf("%d", &length);
    } while (length <= 0); // Check if length is not positive

    do {
        puts("Enter width (a positive integer):");
        scanf("%d", &width);
    } while (width <= 0); // Check if width is not positive

    printf("Area of rectangle is: %.2f \n", rectangleArea(length, width));
}

void circle() {
    int radius;
    do {
        puts("Enter radius (a positive integer):");
        scanf("%d", &radius);
    } while (radius <= 0); // Check if radius is not positive

    printf("Area of circle is: %.2f \n", circleArea(radius));
}

void trapezium() {
    int height;
    int base1;
    int base2;
    do {
        puts("Enter height (a positive integer):");
        scanf("%d", &height);
    } while (height <= 0); // Check if height is not positive

    do {
        puts("Enter base1 (a positive integer):");
        scanf("%d", &base1);
    } while (base1 <= 0); // Check if base1 is not positive

    do {
        puts("Enter base2 (a positive integer):");
        scanf("%d", &base2);
    } while (base2 <= 0); // Check if base2 is not positive

    printf("Area of trapezium is: %.2f \n", trapeziumArea(height, base1, base2));
}

// Function performing shape choice
int shapeChoice(char userInput[9]) {
    //Comparing inputted value with shape names then executing function for chosen shape
    if (strcmp(userInput, "Triangle") == 0) {
        triangle();
    } else if (strcmp(userInput, "Rectangle") == 0) {
        rectangle();
    } else if (strcmp(userInput, "Circle") == 0) {
        circle();
    } else if (strcmp(userInput, "Trapezium") == 0) {
        trapezium();
    } else if (strcmp(userInput, "Done") == 0) {
        puts("Program finished");
        return 0;
    } else {
        puts("Wrong input");
    }
    puts("");
    getchar();
    return 1;
}

// Function setting up message for user
void setUpMessage() {
    puts("Area calculator - Shape Choices are:");
    puts("----------------------------------------------------------------------");
    puts("Triangle, Rectangle, Circle, Trapezium, \"Done\" to end program");
    puts("----------------------------------------------------------------------");
}

int main() {
    int execute = 1;
    char userInput[9];
    while (execute) {
        setUpMessage();
        printf("Choice:");
        gets(userInput);
        execute = shapeChoice(userInput);
    }
    return 0;
}
