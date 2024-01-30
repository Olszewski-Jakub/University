/*
 * Jakub Olszewski
 * 23710521
 * 30.01.2024
 * */

#include <stdio.h>


#define MAX_COUNTRIES 100
#define MAX_COUNTRY_NAME_LENGTH 100

typedef struct {
    char name[MAX_COUNTRY_NAME_LENGTH];
    int population;
} Country;

void question_one();

void question_two();

void question_three();

void question_four();

int main() {
    question_one();
    question_two();
    question_three();
    question_four();
    return 0;
}

void question_one() {
    FILE *fptr;
    long fileSize;

    // Open the file in read mode
    fopen_s(&fptr,
            "C:\\Users\\jolsz\\uni\\freshman\\CT103 - Programming\\assignments\\Assignment16_JakubOlszewski_23710521\\dogs.txt",
            "r+");
    if (fptr != NULL) {
        fseek(fptr, 0, SEEK_END); // seek to end of file
        int len = ftell(fptr); // get current file pointer
        printf("File size is %d bytes\n", len);
        fclose(fptr);
    }
}

void question_two() {
    FILE *fptr;
    char str[1000];

    // Open the file in read mode
    fopen_s(&fptr,
            "C:\\Users\\jolsz\\uni\\freshman\\CT103 - Programming\\assignments\\Assignment16_JakubOlszewski_23710521\\dogs.txt",
            "r+");
    // Check if file opened successfully
    if (fptr != NULL) {
        fseek(fptr, -3, SEEK_END); // seek to end of file
        fputs("Boxer", fptr); // write to file
        fclose(fptr); // close file
    }
}

void question_three() {
    FILE *filePtr;
    char line[256]; // Assuming maximum line length is 256 characters
    Country countries[MAX_COUNTRIES]; // Assuming maximum number of countries is 100
    int numCountries = 0;

    // Open the file in read mode
    filePtr = fopen(
            "C:\\Users\\jolsz\\uni\\freshman\\CT103 - Programming\\assignments\\Assignment16_JakubOlszewski_23710521\\countries.txt",
            "r");

    // Check if file opened successfully
    if (filePtr == NULL) {
        printf("Error opening the file.\n");
        return;
    }

    // Read data from the file
    while (fgets(line, sizeof(line), filePtr) != NULL && numCountries < MAX_COUNTRIES) {
        sscanf(line, "%[^\t]\t%d", countries[numCountries].name, &countries[numCountries].population); // Read the line
        numCountries++; // Increment the number of countries
    }

    // Close the file
    fclose(filePtr);

    // Print the data to the screen
    printf("Countries and their populations:\n");
    for (int i = 0; i < numCountries; i++) {
        printf("Country: %s, Population: %d\n", countries[i].name, countries[i].population);
    }
}

void question_four() {
    FILE *filePtr;
    char newCountry[100];
    int population;

    // Open the file in append mode
    filePtr = fopen(
            "C:\\Users\\jolsz\\uni\\freshman\\CT103 - Programming\\assignments\\Assignment16_JakubOlszewski_23710521\\countries.txt",
            "a");

    // Check if file opened successfully
    if (filePtr == NULL) {
        printf("Error opening the file.\n");
        return;
    }

    // Append the new country and population to the file
    fprintf(filePtr, "Oman\t4580000\n");

    // Close the file
    fclose(filePtr);
}