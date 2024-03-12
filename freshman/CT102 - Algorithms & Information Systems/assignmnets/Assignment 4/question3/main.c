#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "sortingAlgorithms.h"

#define file1 "C:\\Users\\jolsz\\uni\\freshman\\CT102 - Algorithms & Information Systems\\assignmnets\\Assignment 4\\question3\\files\\file1.txt"
#define file2 "C:\\Users\\jolsz\\uni\\freshman\\CT102 - Algorithms & Information Systems\\assignmnets\\Assignment 4\\question3\\files\\file2.txt"

#define result_file_1 "C:\\Users\\jolsz\\uni\\freshman\\CT102 - Algorithms & Information Systems\\assignmnets\\Assignment 4\\question3\\files\\result_file1.csv"
#define result_file_2 "C:\\Users\\jolsz\\uni\\freshman\\CT102 - Algorithms & Information Systems\\assignmnets\\Assignment 4\\question3\\files\result_file2.csv"

typedef struct {
    char sortingAlgorithm[100];
    int size;
    int swaps;
    int comparisons;
    int functionCalls;
    double timeTaken;
} SortingResult;

int numbers[10000];

/**
 * Process the file and save the results in a file
 * @param filePath
 * @param resultFilePath
 */
void processFile(const char *filePath, const char *resultFilePath);

/**
 * Reads numbers from a file and stores them in an array.
 *
 * @param filename The name of the file to read from.
 * @param size The number of integers to read from the file.
 * @param numbers An array to store the numbers read from the file.
 *
 * @return The number of integers successfully read from the file.
 *         Returns -1 if there was an error opening the file.
 */
int readNumbersFromFile(const char *filename, int size, int numbers[]);


/**
 * Saves the results of a sorting algorithm in a struct and increments the array index.
 *
 * @param size The size of the array that was sorted.
 * @param swaps The number of swaps performed by the sorting algorithm.
 * @param comparisons The number of comparisons performed by the sorting algorithm.
 * @param timeTaken The time taken by the sorting algorithm to sort the array.
 * @param sortingAlgorithm The name of the sorting algorithm.
 * @param arrIndex A pointer to the index of the array where the result struct should be stored.
 * @param sortingResultsFile The array of SortingResult structs where the result should be stored.
 */
void saveResultInStruct(int size, int swaps, int comparisons,int functionCalls, double timeTaken, char sortingAlgorithm[], int *arrIndex,
                        SortingResult sortingResultsFile[]);


/**
 * Print the results
 * @param arrIndex
 * @param sortingResultsFile
 */
void printResults(int *arrIndex, SortingResult sortingResultsFile[]);

/**
 * Prints the results of the sorting algorithms to the console.
 *
 * @param arrIndex A pointer to the index of the array containing the results.
 * @param sortingResultsFile The array of SortingResult structs containing the results of the sorting algorithms.
 */
int isSorted(int arr[], int n);

/**
 * Executes a given sorting algorithm on an array of numbers read from a file.
 * The results of the sorting algorithm are stored in an array of SortingResult structs.
 *
 * @param sort A pointer to the sorting function to be executed.
 * @param arrIndex A pointer to the index of the array where the result struct should be stored.
 * @param sortingResultsFile The array of SortingResult structs where the result should be stored.
 * @param filePath The path of the file containing the numbers to be sorted.
 */
void executeSort(void (*sort)(int[], int, int *, int *, int *), char *algorithmName, int *arrIndex,
                 SortingResult sortingResultsFile[], const char *filePath);

/**
 * Writes the results of the sorting algorithms to a file.
 *
 * @param sortingResults An array of SortingResult structs containing the results of the sorting algorithms.
 * @param size The number of elements in the sortingResults array.
 * @param filePath The path of the file where the results should be written.
 */
void writeResultsToFile(SortingResult sortingResults[], int size, const char *filePath);


int main() {

    processFile(file1, result_file_1);
    processFile(file2, result_file_2);

    return 0;
}

void processFile(const char *filePath, const char *resultFilePath) {
    int arrIndex = 0;
    SortingResult sortingResultsFile[40];

    // Pass the address of arrIndex and sortingResultsFile to the function
    executeSort(bubbleSort, "Bubble Sort", &arrIndex, sortingResultsFile, filePath);
    executeSort(selectionSort, "Selection Sort", &arrIndex, sortingResultsFile, filePath);
    executeSort(insertionSort, "Insertion Sort", &arrIndex, sortingResultsFile, filePath);
    executeSort(countingSort, "Count Sort", &arrIndex, sortingResultsFile, filePath);


    printResults(&arrIndex, sortingResultsFile);
    writeResultsToFile(sortingResultsFile, 40, resultFilePath);
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

// Function to swap two integers
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void saveResultInStruct(int size, int swaps, int comparisons,int functionCalls, double timeTaken, char sortingAlgorithm[], int *arrIndex,
                        SortingResult sortingResultsFile[]) {
    SortingResult result;
    result.size = size;
    result.swaps = swaps;
    result.comparisons = comparisons;
    result.functionCalls = functionCalls;
    result.timeTaken = timeTaken;
    strcpy(result.sortingAlgorithm, sortingAlgorithm);

    sortingResultsFile[*arrIndex] = result;
    (*arrIndex)++;
}


void printResults(int *arrIndex, SortingResult sortingResultsFile[]) {
    for (int i = 0; i < *arrIndex; i++) {
        printf("%s with %d numbers:\n", sortingResultsFile[i].sortingAlgorithm, sortingResultsFile[i].size);
        printf("Time taken: %f seconds\n", sortingResultsFile[i].timeTaken);
        printf("Number of swaps/data moves: %d\n", sortingResultsFile[i].swaps);
        printf("Number of comparisons: %d\n", sortingResultsFile[i].comparisons);
        printf("\n");
    }
}

int isSorted(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        if (arr[i] > arr[i + 1]) {
            return 0;
        }
    }
    return 1;
}

void executeSort(void (*sort)(int[], int, int *, int *, int *), char *algorithmName, int *arrIndex,
                 SortingResult sortingResultsFile[], const char *filePath) {
    for (int i = 0; i < 10; i++) { // Loop over the array 10 times
        int size = (i + 1) * 1000; // Calculate the size of the array for each iteration
        int num_read = readNumbersFromFile(filePath, size, numbers); // Read numbers from the file

        if (num_read == -1) { // If there was an error reading the file
            printf("Error reading file\n"); // Print an error message
            return; // Exit the function
        } else if (num_read < size) { // If the number of numbers read is less than the size
            printf("Only %d numbers read from file.\n",
                   num_read); // Print a message indicating the number of numbers read
        }

        int swaps = 0;
        int comparisons = 0;
        int functionCalls = 0;

        clock_t start_time = clock();

        sort(numbers, size, &swaps, &comparisons,&functionCalls); // Sort the numbers

        clock_t end_time = clock(); // End time
        double time_taken = ((double) (end_time - start_time)) / CLOCKS_PER_SEC; // Time taken in seconds

        saveResultInStruct(size, swaps, comparisons,functionCalls, time_taken, algorithmName, arrIndex, sortingResultsFile);

        if (!isSorted(numbers, size)) { // If the numbers are not sorted
            printf("Array not sorted\n"); // Print a message indicating that the array is not sorted
        }
    }
}


void writeResultsToFile(SortingResult sortingResults[], int size, const char *filePath) {
    FILE *file;
    file = fopen(filePath, "w");
    if (file == NULL) {
        printf("Error opening file\n");
        exit(1);
    } else {
        fprintf(file, "Sorting Algorithm, Size, Swaps, Comparisons, Function Calls, Time Taken\n");
        for (int i = 0; i < size; i++) {
            fprintf(file, "%s, %d, %d, %d, %d, %f\n", sortingResults[i].sortingAlgorithm, sortingResults[i].size,
                    sortingResults[i].swaps, sortingResults[i].comparisons,sortingResults[i].functionCalls, sortingResults[i].timeTaken);
        }
        fclose(file);
    }
}
