#ifndef QUESTION3_FILEOPERATIONS_H
#define QUESTION3_FILEOPERATIONS_H

#include "SortingResult.h"
#include <stdio.h>
#include <stdlib.h>


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
 * Writes the results of the sorting algorithms to a file.
 *
 * @param sortingResults An array of SortingResult structs containing the results of the sorting algorithms.
 * @param size The number of elements in the sortingResults array.
 * @param filePath The path of the file where the results should be written.
 */
int writeResultsToFile(SortingResult sortingResults[], int size, const char *filePath);

#endif //QUESTION3_FILEOPERATIONS_H