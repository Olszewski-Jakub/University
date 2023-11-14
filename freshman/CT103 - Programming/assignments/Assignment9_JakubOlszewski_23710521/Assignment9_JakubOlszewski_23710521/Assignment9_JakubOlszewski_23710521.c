/*
 * Jakub Olszewski
 * 23710521
 * 14/11/2023
 */

#include <stdio.h>
#include <math.h>
// Defining constants
#define barrel 0.48
#define density 1000
// Defining functions
float volume(float length, float width, float depth);

void mass(float volume);

int howManyBarrels(float volume);

int main() {
//    Test Values
//    int L = 7;
//    int W = 8;
//    int H = 9;
// dimensions from student id number
    int L = 5;
    int W = 2;
    int H = 1;

    // Executing functions
    // Casting int to float to avoid loss of precision
    float V = volume((float) L, (float) W, (float) H);
    int B = howManyBarrels(V);
    mass(V);
    printf("Volume = %.2f\n", V);
    printf("Barrels = %d\n", B);

    return 0;
}

// Calculating volume of an swing pool
float volume(float length, float width, float depth) {
    return length * width * depth;
}


//Calculating mass of water in a swing pool
void mass(float volume) {
    printf("The mass of water in the swimming pool is %.2f kg\n", volume * density);
}

// Calculating how many barrels can be filled with water in the swimming pool
int howManyBarrels(float volume) {
    // Using ceil function to round up the number of barrels and return an integer
    return (int) ceil(volume / barrel);
}

