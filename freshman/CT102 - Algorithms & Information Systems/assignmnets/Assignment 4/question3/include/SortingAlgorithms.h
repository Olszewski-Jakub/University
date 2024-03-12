#ifndef QUESTION3_SORTINGALGORITHMS_H
#define QUESTION3_SORTINGALGORITHMS_H

#include <stdio.h>
#include <stdlib.h>
#include "Swap.h"



/**
 * Sorts an array of integers using the bubble sort algorithm.
 *
 * @param nums The array to be sorted.
 * @param size The size of the array.
 * @param swaps A pointer to an integer where the number of swaps will be stored.
 * @param comparisons A pointer to an integer where the number of comparisons will be stored.
 * @param functionCalls A pointer to an integer where the number of function calls will be stored.
 */
void bubbleSort(int nums[], int size, int *swaps, int *comparisons, int *functionCalls);

/**
 * Sorts an array of integers using the selection sort algorithm.
 *
 * @param nums The array to be sorted.
 * @param size The size of the array.
 * @param swaps A pointer to an integer where the number of swaps will be stored.
 * @param comparisons A pointer to an integer where the number of comparisons will be stored.
 * @param functionCalls A pointer to an integer where the number of function calls will be stored.
 */
void selectionSort(int nums[], int size, int *swaps, int *comparisons, int *functionCalls);

/**
 * Sorts an array of integers using the insertion sort algorithm.
 *
 * @param nums The array to be sorted.
 * @param size The size of the array.
 * @param swaps A pointer to an integer where the number of swaps will be stored.
 * @param comparisons A pointer to an integer where the number of comparisons will be stored.
 * @param functionCalls A pointer to an integer where the number of function calls will be stored.
 */
void insertionSort(int nums[], int size, int *swaps, int *comparisons, int *functionCalls);

/**
 * Sorts an array of integers using the counting sort algorithm.
 *
 * @param nums The array to be sorted.
 * @param size The size of the array.
 * @param swaps A pointer to an integer where the number of swaps will be stored.
 * @param comparisons A pointer to an integer where the number of comparisons will be stored.
 * @param functionCalls A pointer to an integer where the number of function calls will be stored.
 */
void countingSort(int nums[], int size, int *swaps, int *comparisons, int *functionCalls);

#endif //QUESTION3_SORTINGALGORITHMS_H