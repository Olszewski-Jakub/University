#include <time.h>
#include "../include/SortingOperations.h"

int isSorted(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        if (arr[i] > arr[i + 1]) {
            return 0;
        }
    }
    return 1;
}

void executeSort(int numbers[],void (*sort)(int[], int, int *, int *, int *), char *algorithmName, int *arrIndex,
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
