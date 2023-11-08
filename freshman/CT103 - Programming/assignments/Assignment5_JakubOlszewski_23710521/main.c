#include <stdio.h>

int main() {
    float sales[7];
    float total = 0;
    float average;

    printf("Enter the daily sales for 7 days:\n");
    for (int i = 0; i < 7; i++) {
        printf("Day %d: ", i + 1);
        scanf("%f", &sales[i]); // Adding inputed value to the array
        total += sales[i]; // Adding inputed value to the total sales
    }

    average = total / 7; // Calculating the average sales
    printf("Total sales over 7 days: %.2f\n", total);
    printf("Average daily sales over 7 days: %.2f\n", average);

    int additionalDays;
    printf("How many additional days of sales would you like to record? ");
    scanf("%d", &additionalDays); // Getting the number of additional days

    float newTotal = total;
    int k = 7;
    while(k < 7 + additionalDays) {
        printf("Day %d: ", k + 1);
        scanf("%f", &sales[k]); // Adding inputed value to the array
        newTotal += sales[k]; // Adding inputed value to the total sales
        k++;
    }

    average = newTotal / (7 + additionalDays); // Calculating the average sales
    printf("New total sales over %d days: %.2f\n", 7 + additionalDays, newTotal);
    printf("New average daily sales over %d days: %.2f\n", 7 + additionalDays, average);

    printf("All sales values stored in the array:\n");
    for (int i = 0; i < 7 + additionalDays; i++) { // Looping through the array
        printf("Day %d: %.2f\n", i + 1, sales[i]); // Printing all the values in the array
    }

    return 0;
}
