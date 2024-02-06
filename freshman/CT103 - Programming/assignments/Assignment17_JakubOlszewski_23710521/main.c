#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void printDoubleArray(double *dp, int len);

void swapIntegerValues(int *i1, int *i2);

void squareIntArray(int *ip, int len);

void printIntegerArrayBackwards(int *ip, int len);

void randomIntArray(int *ip, int len, int max);

int main() {
    //Initialize an array of 4 doubles and a pointer to the first element of the array
    double dArray[] = {1.50, 2.30, 4.70, 8.90};
    double *dp = dArray;
    printDoubleArray(dp, 4);


    printf("\n");
    //Initialize two integers and two pointers to the integers
    int integer1 = 4;
    int integer2 = 12;
    int *i1 = &integer1;
    int *i2 = &integer2;
    //Call the swapIntegerValues function with the two pointers as arguments
    swapIntegerValues(i1, i2);

    printf("\n");
    //Initialize an array of 5 integers and a pointer to the first element of the array
    int intArray[] = {1, 2, 3, 4, 5};
    int *ip = intArray;
    squareIntArray(ip, 5);

    printf("\n\n");

    printIntegerArrayBackwards(ip, 5);

    printf("\n\n");
    srand(time(NULL));
    int len = 5;
    int max = 100;
    int randArr[len];
    int *randArrPointer = randArr;
    randomIntArray(randArrPointer, len, max);
    return 0;
}


void printDoubleArray(double *dp, int len) {
    printf("Q1: Double Array\n");
    for (int i = 0; i < len; i++) {
        printf("%.2f\n", *(dp + i));
    }
}

void swapIntegerValues(int *i1, int *i2) {
    printf("Q2: Integer Swap\n");
    printf("x = %d, y = %d\n", *i1, *i2);
    int temp = *i1;
    *i1 = *i2;
    *i2 = temp;
    printf("x = %d, y = %d\n", *i1, *i2);
}

void squareIntArray(int *ip, int len) {
    printf("Q3: Square Array\n");
    for (int i = 0; i < len; i++) {
        *(ip + i) = *(ip + i) * *(ip + i);
    }
    for (int i = 0; i < len; i++) {
        printf("%d ", *(ip + i));
    }
}

void printIntegerArrayBackwards(int *ip, int len) {
    printf("Q4: Print Array Backwards\n");
    for (int i = len - 1; i >= 0; i--) {
        printf("%d ", *(ip + i));
    }
}

void randomIntArray(int *ip, int len, int max) {
    printf("Q5: Random Integers\n");
    for (int i = 0; i < len; i++) {
        *(ip + i) = rand() % max;
    }
    for (int i = 0; i < len; i++) {
        printf("%d ", *(ip + i));
    }
}
