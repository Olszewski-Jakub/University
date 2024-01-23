/*
 * Jakub Olszewski
 * 23710521
 * 23.01.2024
 * */

#include <stdio.h>
#include <string.h>


void openFileAndPrintContents();

void readDataAndCalculateStats();

void appendNewEntry();

typedef struct {
    char orderDate[10];
    char region[20];
    char rep[20];
    char item[20];
    int units;
    float unitCost;
    float total;
} OrderData;

int main() {
    printf("Part 1:\n\n");
    openFileAndPrintContents();
    printf("\n\nPart 2:\n\n");
    readDataAndCalculateStats();
    printf("\n\nPart 3:\n\n");
    appendNewEntry();
    return 0;
}

void openFileAndPrintContents() {
    FILE *fptr;
    fopen_s(&fptr,
            "C:\\Users\\jolsz\\uni\\freshman\\CT103 - Programming\\assignments\\Assignment15_JakubOlszewski_23710521\\SampleData.txt",
            "r");
    if (fptr == NULL) {
        puts("Error opening file");
    }

    char buffer[256];

    // Read and print the first line (header)
    if (fgets(buffer, sizeof(buffer), fptr) != NULL) {
        // Print the header
        printf("%-10s %-10s %-10s %-10s %-10s %-10s %-10s\n", "OrderDate", "Region", "Rep", "Item", "Units",
               "Unit Cost", "Total");
    }

    // Read and print each subsequent line from the file
    while (fgets(buffer, sizeof(buffer), fptr) != NULL) {
        // Print the content of each line
        printf("%s", buffer);
    }

    // Close the fptr
    fclose(fptr);
}

void readDataAndCalculateStats() {
    FILE *fptr;
    fopen_s(&fptr,
            "C:\\Users\\jolsz\\uni\\freshman\\CT103 - Programming\\assignments\\Assignment15_JakubOlszewski_23710521\\SampleData.txt",
            "r");
    if (fptr == NULL) {
        puts("Error opening file");
        return;
    }

    char buffer[256];
    OrderData order;
    float totalIncome = 0;
    int orderCount = 0;

    // Read and print the first line (header)
    if (fgets(buffer, sizeof(buffer), fptr) != NULL) {
        // Print the header
        printf("%-10s %-10s %-10s %-10s %-10s %-10s %-10s\n", "OrderDate", "Region", "Rep", "Item", "Units",
               "Unit Cost", "Total");
    }

    // Read and print each subsequent line from the file
    while (fgets(buffer, sizeof(buffer), fptr) != NULL) {
        // Extract values
        sscanf(buffer, "%s %s %s %s %d %f %f",
               order.orderDate, order.region, order.rep, order.item, &order.units, &order.unitCost, &order.total);

        // Print the content of each line
        printf("%-10s %-10s %-10s %-10s %-10d %-10.2f %-10.2f\n",
               order.orderDate, order.region, order.rep, order.item, order.units, order.unitCost, order.total);

        // Calculate stats
        totalIncome += order.total;
        orderCount++;
    }

    // Calculate and print stats
    if (orderCount > 0) {
        float averageOrderValue = (float) totalIncome / orderCount;
        printf("\nTotal Income: %.2lf\n", (float) totalIncome);
        printf("Average Order Value: %.2lf\n", averageOrderValue);
    }

    // Close the fptr
    fclose(fptr);
}

void appendNewEntry() {
    FILE *fptr;
    fopen_s(&fptr, "C:\\Users\\jolsz\\uni\\freshman\\CT103 - Programming\\assignments\\Assignment15_JakubOlszewski_23710521\\SampleData.txt", "a");
    if (fptr == NULL) {
        puts("Error opening file");
        return;
    }

    fprintf(fptr, "23/01/2024\tGalway\tOlszewski\tPen\t21\t19.99\t%.2f\n", 21.00 * 19.99);

    fclose(fptr);

    printf("File updated\n");
}