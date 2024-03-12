#ifndef QUESTION3_RESULTMANAGEMENT_H
#define QUESTION3_RESULTMANAGEMENT_H

#include "SortingResult.h"
#include "string.h"
#include "stdio.h"
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


#endif //QUESTION3_RESULTMANAGEMENT_H
