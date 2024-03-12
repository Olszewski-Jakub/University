#ifndef QUESTION3_SORTINGOPERATIONS_H
#define QUESTION3_SORTINGOPERATIONS_H


#include "FileOperations.h"
#include "SortingResult.h"
#include "ResultManagement.h"

void executeSort(int numbers[],void (*sort)(int[], int, int *, int *, int *), char *algorithmName, int *arrIndex,
                 SortingResult sortingResultsFile[], const char *filePath);

int isSorted(int arr[], int n);

#endif //QUESTION3_SORTINGOPERATIONS_H
