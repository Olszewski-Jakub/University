#include <stdio.h>
#include <string.h>

// Define a structure for storing date information
typedef struct {
    int day, month, year;
} date;

// Define a structure for storing customer information
typedef struct {
    char name[50]; // Name of the customer
    int accountNumber; // Account number of the customer
    double balance; // Balance of the customer
    date lastTrans; // Date of the last transaction of the customer
} customer;

// Function prototypes
void getCustomerName(customer *cptr);
void getAccountNumber(customer *cptr);
void getLastTransDate(customer *cptr);
void getBalance(customer *cptr);
void printCustomer(customer *cptr);

// Main function
int main() {
    int i;
    customer customers[3]; // Array to store information of 3 customers

    // Loop to input information for each customer
    for (i = 0; i < 3; i++) {
        getCustomerName(&customers[i]); // Get customer name
        getAccountNumber(&customers[i]); // Get account number
        getLastTransDate(&customers[i]); // Get last transaction date
        getBalance(&customers[i]); // Get balance
        printf("\n");
    }

    // Print header for the table
    printf("\n\n%25s\t%13s\t%12s\t%s\n\n", "Name", "Account Number", "Balance", "Date of Last Transaction");

    // Loop to print information of each customer
    for (i = 0; i < 3; i++) {
        printCustomer(&customers[i]); // Print customer information
    }

    return 0;
}

// Function to get customer name
void getCustomerName(customer *cptr) {
    printf("Enter customer name: ");
    fgets(cptr->name, 50, stdin); // Read customer name from user input

    // Remove newline character if present
    size_t len = strlen(cptr->name);
    if (cptr->name[len - 1] == '\n')
        cptr->name[len - 1] = '\0';
}

// Function to get last transaction date
void getLastTransDate(customer *cptr) {
    printf("Enter last transaction date in format DD/MM/YYYY: ");
    int day, month, year;
    int result = scanf("%d/%d/%d", &day, &month, &year); // Read date from user input

    // Validate input date
    while (result != 3 || getchar() != '\n' || day < 1 || day > 31 || month < 1 || month > 12 || year < 1900 ||
           year > 9999) {
        printf("Invalid input. Please enter date in format DD/MM/YYYY: ");
        while (getchar() != '\n'); // Clear input buffer
        result = scanf("%d/%d/%d", &day, &month, &year); // Read date again
    }
    cptr->lastTrans.day = day;
    cptr->lastTrans.month = month;
    cptr->lastTrans.year = year;
}

// Function to get account number
void getAccountNumber(customer *cptr) {
    printf("Enter account number: ");
    scanf("%d", &(cptr->accountNumber)); // Read account number from user input
    while (getchar() != '\n'); // Clear input buffer
}

// Function to get balance
void getBalance(customer *cptr) {
    printf("Enter balance: ");
    scanf("%lf", &(cptr->balance)); // Read balance from user input
    while (getchar() != '\n'); // Clear input buffer
}

// Function to print customer information
void printCustomer(customer *cptr) {
    printf("%25s\t%13d\t%12.2lf\t%02d/%02d/%d\n\n", cptr->name, cptr->accountNumber, cptr->balance, cptr->lastTrans.day,
           cptr->lastTrans.month, cptr->lastTrans.year);
}