#include "../include/FileOperations.h"


int writeResultsToFile(SortingResult sortingResults[], int size, const char *filePath) {
    FILE *file;
    file = fopen(filePath, "w");
    if (file == NULL) {
        printf("Error opening file\n");
        return 0;
    } else {
        fprintf(file, "Sorting Algorithm, Size, Swaps, Comparisons, Function Calls, Time Taken\n");
        for (int i = 0; i < size; i++) {
            fprintf(file, "%s, %d, %d, %d, %d, %f\n", sortingResults[i].sortingAlgorithm, sortingResults[i].size,
                    sortingResults[i].swaps, sortingResults[i].comparisons,sortingResults[i].functionCalls, sortingResults[i].timeTaken);
        }
        fclose(file);
    }
    return 1;
}

int readNumbersFromFile(const char *filename, int size, int numbers[]) {
    FILE *file;

    // Open the file for reading
    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file %s\n", filename);
        return -1; // Error opening file
    }

    // Read integers from the file and store them in the array
    for (int i = 0; i < size; i++) {
        if (fscanf(file, "%d", &numbers[i]) == EOF) {
            printf("Error: Insufficient numbers in file.\n");
            fclose(file);
            return i; // Return the number of integers read
        }
    }

    // Close the file
    fclose(file);
    return size; // Return the size of the array
}