#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define file1 "C:\\Users\\jolsz\\uni\\freshman\\CT102 - Algorithms & Information Systems\\assignmnets\\Assignment 4\\question3\\files\\file1.txt"
#define file2 "C:\\Users\\jolsz\\uni\\freshman\\CT102 - Algorithms & Information Systems\\assignmnets\\Assignment 4\\question3\\files\\file2.txt"

#define result_file_1 "C:\\Users\\jolsz\\uni\\freshman\\CT102 - Algorithms & Information Systems\\assignmnets\\Assignment 4\\question3\\files\\result_file1.csv"
#define result_file_2 "C:\\Users\\jolsz\\uni\\freshman\\CT102 - Algorithms & Information Systems\\assignmnets\\Assignment 4\\question3\\files\result_file2.csv"

typedef struct {
    char sortingAlgorithm[100];
    int size;
    int swaps;
    int comparisons;
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
 * Swaps the values of two integers.
 *
 * @param a A pointer to the first integer.
 * @param b A pointer to the second integer.
 */
void swap(int *a, int *b);

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
void saveResultInStruct(int size, int swaps, int comparisons, double timeTaken, char sortingAlgorithm[], int *arrIndex,
                        SortingResult sortingResultsFile[]);

/**
 * Executes the bubble sort algorithm on an array of integers.
 *
 * @param nums The array of integers to be sorted.
 * @param size The size of the array to be sorted.
 * @param arrIndex A pointer to the index of the array where the result struct should be stored.
 * @param sortingResultsFile The array of SortingResult structs where the result should be stored.
 */
void bubbleSort(int nums[], int size, int *arrIndex, SortingResult sortingResultsFile[]);

/**
 * Executes the selection sort algorithm on an array of integers.
 *
 * @param nums The array of integers to be sorted.
 * @param size The size of the array to be sorted.
 * @param arrIndex A pointer to the index of the array where the result struct should be stored.
 * @param sortingResultsFile The array of SortingResult structs where the result should be stored.
 */
void selectionSort(int nums[], int size, int *arrIndex, SortingResult sortingResultsFile[]);

/**
 * Executes the insertion sort algorithm on an array of integers.
 *
 * @param nums The array of integers to be sorted.
 * @param size The size of the array to be sorted.
 * @param arrIndex A pointer to the index of the array where the result struct should be stored.
 * @param sortingResultsFile The array of SortingResult structs where the result should be stored.
 */
void insertionSort(int nums[], int size, int *arrIndex, SortingResult sortingResultsFile[]);

/**
 * Executes the counting sort algorithm on an array of integers.
 *
 * @param nums The array of integers to be sorted.
 * @param size The size of the array to be sorted.
 * @param arrIndex A pointer to the index of the array where the result struct should be stored.
 * @param sortingResultsFile The array of SortingResult structs where the result should be stored.
 */
void countingSort(int nums[], int size, int *arrIndex, SortingResult sortingResultsFile[]);

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
void executeSort(void (*sort)(int[], int, int *, SortingResult[]), int *arrIndex, SortingResult sortingResultsFile[],
                 const char *filePath);

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
    executeSort(bubbleSort, &arrIndex, sortingResultsFile, filePath);
    executeSort(selectionSort, &arrIndex, sortingResultsFile, filePath);
    executeSort(insertionSort, &arrIndex, sortingResultsFile, filePath);
    executeSort(countingSort, &arrIndex, sortingResultsFile, filePath);

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

void saveResultInStruct(int size, int swaps, int comparisons, double timeTaken, char sortingAlgorithm[], int *arrIndex,
                        SortingResult sortingResultsFile[]) {
    SortingResult result;
    result.size = size;
    result.swaps = swaps;
    result.comparisons = comparisons;
    result.timeTaken = timeTaken;
    strcpy(result.sortingAlgorithm, sortingAlgorithm);

    sortingResultsFile[*arrIndex] = result;
    (*arrIndex)++;
}

// Bubble Sort function
void bubbleSort(int nums[], int size, int *arrIndex, SortingResult sortingResultsFile[]) {
    int swaps = 0;
    int comparisons = 0;

    clock_t start_time = clock(); // Start time

    for (int i = 0; i < size - 1; i++) { // Iterate over each element in the array
        for (int j = 0;
             j < size - i - 1; j++) { // For each element, iterate over the array again, excluding the last i elements
            (comparisons)++; // Increment the comparison count
            if (nums[j] > nums[j + 1]) { // If the current element is greater than the next one
                swap(&nums[j], &nums[j + 1]); // Swap the current element with the next one
                (swaps)++; // Increment the swap count
            }
        }
    }

    clock_t end_time = clock(); // End time
    double time_taken = ((double) (end_time - start_time)) / CLOCKS_PER_SEC; // Time taken in seconds

    saveResultInStruct(size, swaps, comparisons, time_taken, "Bubble Sort", arrIndex, sortingResultsFile);
}

void selectionSort(int nums[], int size, int *arrIndex, SortingResult sortingResultsFile[]) {
    clock_t start_time = clock(); // Start time
    int swaps = 0;
    int comparisons = 0;

    for (int step = 0; step < size - 1; step++) { // Iterate over each element in the array
        int min_idx = step; // Assume the current element is the smallest
        for (int i = step + 1; i < size; i++) { // For each element, iterate over the rest of the array
            comparisons++; // Increment the comparison count
            if (nums[i] < nums[min_idx]) { // If a smaller element is found
                min_idx = i; // Update the index of the smallest element
            }
        }

        // After finding the smallest element in the unsorted part of the array
        swaps++; // Increment the swap count
        swap(&nums[min_idx], &nums[step]); // Swap the smallest element with the first element of the unsorted part
    }
    clock_t end_time = clock(); // End time
    double time_taken = ((double) (end_time - start_time)) / CLOCKS_PER_SEC; // Time taken in seconds

    saveResultInStruct(size, swaps, comparisons, time_taken, "Selection Sort", arrIndex, sortingResultsFile);
}

void insertionSort(int nums[], int size, int *arrIndex, SortingResult sortingResultsFile[]) {

    clock_t start_time = clock(); // Start time
    int swaps = 0;
    int comparisons = 0;

    int i, j, current;
    for (i = 0; i < size; i++) { // Iterate over each element in the array
        current = nums[i]; // Store the current element
        for (j = i - 1; j >= 0 && current < nums[j]; j--) { // Iterate backwards from the current element
            nums[j + 1] = nums[j]; // Shift the elements to the right
            swaps++; // Increment the swap count
            comparisons++; // Increment the comparison count
        }
        if (i != j + 1) { // If the current element has been moved
            nums[j + 1] = current; // Insert the current element in its correct position
            swaps++; // Increment the swap count
        }
    }

    clock_t end_time = clock(); // End time
    double time_taken = ((double) (end_time - start_time)) / CLOCKS_PER_SEC; // Time taken in seconds

    saveResultInStruct(size, swaps, comparisons, time_taken, "Insertion Sort", arrIndex, sortingResultsFile);
}

void countingSort(int nums[], int size, int *arrIndex, SortingResult sortingResultsFile[]) {
    clock_t start_time = clock(); // Start time
    int swaps = 0;
    int comparisons = 0; // Counting Sort doesn't involve comparisons

    int max = nums[0]; // Initialize max with the first element of the array
    int min = nums[0]; // Initialize min with the first element of the array
    for (int i = 1; i < size; ++i) { // Iterate over the array starting from the second element
        if (nums[i] > max) { // If the current element is greater than max
            max = nums[i]; // Update max
        }
        if (nums[i] < min) { // If the current element is less than min
            min = nums[i]; // Update min
        }
    }

    // Calculate the range of the count array
    int range = max - min + 1; // The range is the difference between max and min plus 1

    // Allocate memory for count array
    int *count = (int *) malloc(
            range * sizeof(int)); // Allocate memory for the count array with size equal to the range
    // Allocate memory for output array
    int *output = (int *) malloc(
            size * sizeof(int)); // Allocate memory for the output array with size equal to the size of the input array
    if (count == NULL || output == NULL) { // If memory allocation failed for either of the arrays
        printf("Memory allocation failed.\n"); // Print an error message
        return; // Exit the function
    }

    // Initialize count array with all zeros
    for (int i = 0; i < range; ++i) // Iterate over the count array
        count[i] = 0; // Set each element to 0

    // Store the count of each element in count array
    for (int i = 0; i < size; ++i) // Iterate over the input array
        ++count[nums[i] - min]; // Increment the count of the current element in the count array

    // Store the cumulative count of each array
    for (int i = 1; i < range; ++i) // Iterate over the count array starting from the second element
        count[i] += count[i - 1]; // Add the count of the previous element to the current element

    // Build the output array
    for (int i = size - 1; i >= 0; --i) { // Iterate over the input array in reverse order
        output[count[nums[i] - min] -
               1] = nums[i]; // Place the current element in its sorted position in the output array
        --count[nums[i] - min]; // Decrement the count of the current element in the count array
    }

    // Copy the sorted elements back into original array
    for (int i = 0; i < size; ++i) // Iterate over the output array
        nums[i] = output[i]; // Copy each element to the input array

    // Free dynamically allocated memory
    free(count); // Free the memory allocated for the count array
    free(output); // Free the memory allocated for the output array

    clock_t end_time = clock(); // End time
    double time_taken = ((double) (end_time - start_time)) / CLOCKS_PER_SEC; // Time taken in seconds

    saveResultInStruct(size, swaps, comparisons, time_taken, "Count Sort", arrIndex, sortingResultsFile);

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

void executeSort(void (*sort)(int[], int, int *, SortingResult[]), int *arrIndex, SortingResult sortingResultsFile[],
                 const char *filePath) {
    for (int i = 0; i < 10; i++) { // Loop over the array 10 times
        int size = (i + 1) * 1000; // Calculate the size of the array for each iteration
        int num_read = readNumbersFromFile(filePath, size, numbers); // Read numbers from the file

        if (num_read == -1) { // If there was an error reading the file
            printf("Error reading file\n"); // Print an error message
            return; // Exit the function
        } else if (num_read < size) { // If the number of numbers read is less than the size
            printf("Only %d numbers read from file.\n", num_read); // Print a message indicating the number of numbers read
        }


        sort(numbers, size, arrIndex, sortingResultsFile); // Sort the numbers


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
        fprintf(file, "Sorting Algorithm, Size, Swaps, Comparisons, Time Taken\n");
        for (int i = 0; i < size; i++) {
            fprintf(file, "%s, %d, %d, %d, %f\n", sortingResults[i].sortingAlgorithm, sortingResults[i].size,
                    sortingResults[i].swaps, sortingResults[i].comparisons, sortingResults[i].timeTaken);
        }
        fclose(file);
    }
}
