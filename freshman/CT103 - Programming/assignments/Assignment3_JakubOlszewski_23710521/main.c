/*
 * Jakub Olszewski
 * Student id: 237810521
 * Date 03/10/2023 16:10
 */

#include <stdio.h>

// Function calculates the sum of the array
float arraySum(const float sales[4]) {
    float sum = 0.0f; // Initialize sum
    for (int i = 0; i < 4; ++i) { // Iterate through all elements
        sum += sales[i]; // Add each element to sum
    }
    return sum; // Return sum
}

// Function calculates the average of the array
float averageSales(float sales[4]) {
    return arraySum(sales) / 4.0f; // Using arrySum function to calculate the average sales
}

// Function calculates the average spend per customer
float avgSpendPerCustomerDaily(float sales[4]) {
    float customers = 500.0f; // Number of customers
    float avgSpend = arraySum(sales) / (customers * 4.0f); // Using arraySum function to calculate the average spend per customer
    return avgSpend; // Return average spend per customer
}

// Function returns a message based on the average sales
// Using a function to return a message based on the avarage is more efficient
// than using if statements in the main function, because of the inversion of statements
char * salesValueMsg(float avgSales) {
    if (avgSales > 15000.0f) // If average sales are higher than 15000 return "Sales are very high"
        return "Sales are high";
    if (avgSales >= 10000.0f) // If average sales are higher than 10000 return "Sales are high"
        return "Sales are normal";
    return "Sales are low"; // If average sales are lower than 10000 return "Sales are low"
}

int main() {
    printf("Input values in Euro");
    float dailySales[4]; // Array to store the daily sales
    for (int i = 0; i < 4; ++i) {
        printf("\nInput sales from day %d: ", i+1);
        scanf_s("%f", &dailySales[i]); // Input sales from each day and saving them in array dailySales
    }
    float avgSales = averageSales(dailySales); // Calculate the average sales
    printf("Average daily sales from 4 days: %.2f Euro", avgSales);
    printf("\n%s", salesValueMsg(avgSales));
    printf("\nAverage spend per customer daily is: %.2f Euro", avgSpendPerCustomerDaily(dailySales));
    return 0;
}
