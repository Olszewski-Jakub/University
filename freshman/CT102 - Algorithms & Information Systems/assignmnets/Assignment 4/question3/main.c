
#include "include/SortingResult.h"
#include "include/SortingOperations.h"
#include "include/SortingAlgorithms.h"

#define file1 "..\\files\\file1.txt"
#define file2 "..\\files\\file2.txt"

#define result_file_1 "..\\files\\result_file1.csv"
#define result_file_2 "..\\files\\result_file2.csv"

#define NUM_SORTING_ALGORITHMS 4
#define NUM_RESULTS_PER_ALGORITHM 10

int numbers[10000];

/**
 * Process the file and save the results in a file
 * @param filePath
 * @param resultFilePath
 */
void processFile(const char *filePath, const char *resultFilePath);


int main() {

    processFile(file1, result_file_1);
    processFile(file2, result_file_2);

    return 0;
}

void processFile(const char *filePath, const char *resultFilePath) {
    int arrIndex = 0;
    SortingResult sortingResultsFile[NUM_SORTING_ALGORITHMS * NUM_RESULTS_PER_ALGORITHM];

    // Pass the address of arrIndex and sortingResultsFile to the function
    executeSort(numbers, bubbleSort, "Bubble Sort", &arrIndex, sortingResultsFile, filePath);
    executeSort(numbers, selectionSort, "Selection Sort", &arrIndex, sortingResultsFile, filePath);
    executeSort(numbers, insertionSort, "Insertion Sort", &arrIndex, sortingResultsFile, filePath);
    executeSort(numbers, countingSort, "Count Sort", &arrIndex, sortingResultsFile, filePath);


    printResults(&arrIndex, sortingResultsFile);
//    writeResultsToFile(sortingResultsFile, NUM_SORTING_ALGORITHMS * 10, resultFilePath);
    if (!writeResultsToFile(sortingResultsFile, NUM_SORTING_ALGORITHMS * NUM_RESULTS_PER_ALGORITHM, resultFilePath)) {
        printf("Error writing to file: %s\n", resultFilePath);
    }
}




