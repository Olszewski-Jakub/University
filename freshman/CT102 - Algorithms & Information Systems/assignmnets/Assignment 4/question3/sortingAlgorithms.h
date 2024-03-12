//
// Created by jolsz on 12.03.2024.
//

#ifndef QUESTION3_SORTINGALGORITHMS_H
#define QUESTION3_SORTINGALGORITHMS_H

#endif //QUESTION3_SORTINGALGORITHMS_H

/**
 * Swaps the values of two integers.
 *
 * @param a A pointer to the first integer.
 * @param b A pointer to the second integer.
 */
void swap(int *a, int *b);

/**
 * Executes the bubble sort algorithm on an array of integers.
 *
 * @param nums The array of integers to be sorted.
 * @param size The size of the array to be sorted.
 * @param arrIndex A pointer to the index of the array where the result struct should be stored.
 * @param sortingResultsFile The array of SortingResult structs where the result should be stored.
 */
void bubbleSort(int nums[], int size, int *swaps, int *comparisons);

/**
 * Executes the selection sort algorithm on an array of integers.
 *
 * @param nums The array of integers to be sorted.
 * @param size The size of the array to be sorted.
 * @param arrIndex A pointer to the index of the array where the result struct should be stored.
 * @param sortingResultsFile The array of SortingResult structs where the result should be stored.
 */
void selectionSort(int nums[], int size, int *swaps, int *comparisons);

/**
 * Executes the insertion sort algorithm on an array of integers.
 *
 * @param nums The array of integers to be sorted.
 * @param size The size of the array to be sorted.
 * @param arrIndex A pointer to the index of the array where the result struct should be stored.
 * @param sortingResultsFile The array of SortingResult structs where the result should be stored.
 */
void insertionSort(int nums[], int size, int *swaps, int *comparisons);

/**
 * Executes the counting sort algorithm on an array of integers.
 *
 * @param nums The array of integers to be sorted.
 * @param size The size of the array to be sorted.
 * @param arrIndex A pointer to the index of the array where the result struct should be stored.
 * @param sortingResultsFile The array of SortingResult structs where the result should be stored.
 */
void countingSort(int nums[], int size, int *swaps, int *comparisons);