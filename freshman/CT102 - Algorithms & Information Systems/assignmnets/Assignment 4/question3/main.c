
#include "include/SortingResult.h"
#include "include/SortingOperations.h"
#include "include/SortingAlgorithms.h"

#define file1 "C:\\Users\\jolsz\\uni\\freshman\\CT102 - Algorithms & Information Systems\\assignmnets\\Assignment 4\\question3\\files\\file1.txt"
#define file2 "C:\\Users\\jolsz\\uni\\freshman\\CT102 - Algorithms & Information Systems\\assignmnets\\Assignment 4\\question3\\files\\file2.txt"

#define result_file_1 "C:\\Users\\jolsz\\uni\\freshman\\CT102 - Algorithms & Information Systems\\assignmnets\\Assignment 4\\question3\\files\\result_file1.csv"
#define result_file_2 "C:\\Users\\jolsz\\uni\\freshman\\CT102 - Algorithms & Information Systems\\assignmnets\\Assignment 4\\question3\\files\\result_file2.csv"



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
    SortingResult sortingResultsFile[40];

    // Pass the address of arrIndex and sortingResultsFile to the function
    executeSort(numbers, bubbleSort, "Bubble Sort", &arrIndex, sortingResultsFile, filePath);
    executeSort(numbers, selectionSort, "Selection Sort", &arrIndex, sortingResultsFile, filePath);
    executeSort(numbers, insertionSort, "Insertion Sort", &arrIndex, sortingResultsFile, filePath);
    executeSort(numbers, countingSort, "Count Sort", &arrIndex, sortingResultsFile, filePath);


    printResults(&arrIndex, sortingResultsFile);
    writeResultsToFile(sortingResultsFile, 40, resultFilePath);
}




