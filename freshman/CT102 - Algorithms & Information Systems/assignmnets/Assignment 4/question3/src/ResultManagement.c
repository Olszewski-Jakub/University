#include "../include/ResultManagement.h"

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
        printf("Number of function calls: %d\n", sortingResultsFile[i].functionCalls);
        printf("\n");
    }
}