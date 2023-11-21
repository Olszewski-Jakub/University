/*
 * Jakub Olszewski
 * 23710521
 * */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

void executePasscode(int N);

int setPasscode(int N);

void randomPasscodeSearch(int passcode, int N);

/*
 * orderedPasscodeSearchEnterDigits is a function that takes in a passcode and the number of digits in the passcode.It is an ulternative version of orderedPasscodeSearch.
 * I wasn't sure about the Q.4 of the assignment, so I made this function to search for the passcode using the number of digits in the passcode.
 * I have also included the formula for the number of digits in a number.
 * Execution of this function is commented out in the executePasscode function.
 */
void orderedPasscodeSearchEnterDigits(int passcode, int numDigits);

void orderedPasscodeSearch(int passcode, int N);

int main() {
    srand(time(NULL));
    /* Parameters from Q.4 of the assignment
     * N1 = 9
     * N2 = 99
     * N3 = 999
     * N4 = 9999
     */
    executePasscode(9);
    executePasscode(99);
    executePasscode(999);
    executePasscode(9999);

    int passcodeFromStudentID = 521;
    printf("Final passcode = %d\n", passcodeFromStudentID);
    randomPasscodeSearch(passcodeFromStudentID, 999);
    orderedPasscodeSearch(passcodeFromStudentID, 999);

    return 0;
}
// executePasscode is a function that takes in a number N and executes the randomPasscodeSearch and orderedPasscodeSearch functions.
// Its main purpose is to get rid of code duplication.
// Commented section is the alternative function i mentioned earlier
void executePasscode(int N) {
    printf("Max passcode = %d\n", N);
    int passcode = setPasscode(N);
    printf("Passcode: %d\n", passcode);
    randomPasscodeSearch(passcode, N);
//    Formula for number of digits in a number
//    int digits =  floor(log10(abs(N))) + 1;
//    orderedPasscodeSearchEnterDigits(passcode, digits);
    orderedPasscodeSearch(passcode, N);
    printf("\n");
}

int setPasscode(int N) {
    // rand() % (N + 1) generates a random number between 0 and N
    return rand() % (N + 1);
}

void randomPasscodeSearch(int passcode, int N) {
    int count = 1;
// generating a random passcode
    int guess = setPasscode(N);
    // while loop to keep generating random passcodes until the passcode is found
    while (guess != passcode) {
        guess = setPasscode(N);
        // Increment the number of attempts
        count++;
    }
    printf("Random search. Passcode = %d. Found after %d attempts.\n", passcode, count);
}

void orderedPasscodeSearchEnterDigits(int passcode, int numDigits) {
    int attempts = 0;
    int currentPasscode = 0;
    //form
    int maxPasscode = (int) pow(10, (numDigits)) - 1;
    while (currentPasscode <= maxPasscode) {
        // Increment the number of attempts
        attempts++;
        // Check if the current passcode matches the target passcode
        if (currentPasscode == passcode) {
            // Print the found passcode and the number of attempts
            printf("Ordered search. Passcode = %d. Found after %d attempts.\n", passcode, attempts);
            return;
        }
        // Move on to the next passcode
        currentPasscode++;
    }
    // If the loop completes and the passcode is not found, print an error message
    printf("Ordered search. Error: Passcode not found.\n");
}

void orderedPasscodeSearch(int passcode, int N) {
    int attempts = 0;
    int currentPasscode = 0;
    while (currentPasscode <= N) {
        // Increment the number of attempts
        attempts++;
        // Check if the current passcode matches the target passcode
        if (currentPasscode == passcode) {
            // Print the found passcode and the number of attempts
            printf("Ordered search. Passcode = %d. Found after %d attempts.\n", passcode, attempts);
            return;
        }
        // Move on to the next passcode
        currentPasscode++;
    }
    // If the loop completes and the passcode is not found, print an error message
    printf("Ordered search. Error: Passcode not found.\n");
}
