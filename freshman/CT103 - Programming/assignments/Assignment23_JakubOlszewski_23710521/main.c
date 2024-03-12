#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int is_leap(int year);

int new_years_day(int year);

/**
 * @brief This function calculates the number of days in a given month of a given year.
 *
 * The function takes into account the possibility of a leap year when calculating the number of days in February.
 *
 * @param year The year as an integer.
 * @param month The month as an integer (1 for January, 2 for February, ..., 12 for December).
 *
 * @return The number of days in the given month of the given year.
 */
int no_of_days(int year, int month);

/**
 * @brief This function calculates the day of the week for the first day of a given month of a given year.
 *
 * The function uses Zeller's Congruence algorithm to calculate the day of the week.
 *
 * @param year The year as an integer.
 * @param month The month as an integer (1 for January, 2 for February, ..., 12 for December).
 *
 * @return The day of the week for the first day of the given month of the given year (0 for Sunday, 1 for Monday, ..., 6 for Saturday).
 */
int first_day(int year, int month);

/**
 * @brief This function prints the calendar for a given month of a given year.
 *
 * The function prints the days of the month in a grid format, with the days of the week as column headers.
 *
 * @param firstDay The day of the week for the first day of the month (0 for Sunday, 1 for Monday, ..., 6 for Saturday).
 * @param noOfDays The number of days in the month.
 */
void print_month(int firstday, int noOfDays);

/**
 * @brief This function executes the calendar for a given month of a given year.
 *
 * The function prints the month and year as a header, and then calls the print_month function to print the calendar.
 *
 * @param year The year as an integer.
 * @param month The month as an integer (1 for January, 2 for February, ..., 12 for December).
 */
void execute_calendar(int year, int month);

int main(int argc, char *argv[]) {
    // Check for the correct number of arguments
    if (argc < 3) {
        printf("Usage: %s year month [month...]\n", argv[0]);
        return 1;
    }
    // Check for the correct year
    int year = atoi(argv[1]);
    if (year < 1) {
        printf("Invalid year: %s\n", argv[1]);
        return 1;
    }
    // Check for the correct month
    for (int i = 2; i < argc; i++) {
        int month = atoi(argv[i]);
        if (month < 1 || month > 12) {
            printf("Invalid month: %s\n", argv[i]);
            return 1;
        }
        // Execute the calendar for the given year and month
        execute_calendar(year, month);
    }
}

// Check for leap year
int is_leap(int year) {
    if (year % 400 == 0)
        return 1;
    if (year % 100 == 0)
        return 0;
    if (year % 4 == 0)
        return 1;
    return 0;
}

// Calculate the day of the week for January 1st
int new_years_day(int year) {
// Gauss' algorithm for finding the day of the week for January 1st of a given year
    int day = (year + (year - 1) / 4 - (year - 1) / 100 + (year - 1) / 400) % 7;
    // Adjust for Sunday being represented as 0
    if (day < 0) {
        day += 7;
    }
    return day;
}

int no_of_days(int year, int month) {
    if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) {
        return 31;
    } else if (month == 2) {
        // Check for leap year
        if (is_leap(year)) {
            return 29;
        } else {
            return 28;
        }
    } else {
        return 30;
    }
}

// Calculate the day of the week for the first day of the month
int first_day(int year, int month) {
    int doy = 1;  // Day of the year (1 for the first day)

    // Adjust month and year for Zeller's Congruence algorithm
    if (month < 3) {
        month += 12;
        year--;
    }

    // Zeller's Congruence calculation
    int K = year % 100;  // Year of the century
    int J = year / 100;   // Zero-based century
    int h = (doy + (13 * (month + 1)) / 5 + K + K / 4 + J / 4 - 2 * J) % 7; // Day of the week

    // Convert the result to match the desired day of the week numbering
    int dayOfWeek = (h + 6) % 7;  // 0 for Sunday, 1 for Monday, ...

    return dayOfWeek;
}


void print_month(int firstDay, int noOfDays) {
//    printf("\n Sun Mon Tue Wed Thu Fri Sat\n");
    printf("Sun Mon Tue Wed Thu Fri Sat\n");

    // Print the days with leading spaces for alignment
    for (int i = 0; i < firstDay; i++) {
        printf("    ");
    }

    int day = 1;
    while (day <= noOfDays) {
        printf("%3d ", day);
        if ((day + firstDay) % 7 == 0) {
            printf("\n"); // New line after every week
        }
        day++;
    }

    printf("\n");

}

void execute_calendar(int year, int month) {
    int firstDay = first_day(year, month);
    int noOfDays = no_of_days(year, month);
    printf("%d/%d\n\n", month, year);
    print_month(firstDay, noOfDays);
    printf("\n");
}
