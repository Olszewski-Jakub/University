//
// Created by jolsz on 12.03.2024.
//

#include "../include/Swap.h"

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}