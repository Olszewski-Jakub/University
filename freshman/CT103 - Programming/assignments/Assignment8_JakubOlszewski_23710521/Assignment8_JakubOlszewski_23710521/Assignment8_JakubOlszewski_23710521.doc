#include <stdio.h>
#include <ctype.h>

int main() {
    printf("Enter car manufacturers\n");
    char carManufacturer[5][20];
    for (int i = 0; i < 5; i++) {
        scanf("%s", carManufacturer[i]);
    }


    //Printing all Uppercase letters in array of strings
    for (int i = 0; i < 5; i++) { //Looping through all strings
        for (int j = 0; carManufacturer[i][j] != '\0'; j++) { //Nested loop to loop through all characters in string
            if (isupper(carManufacturer[i][j])) { //Checking if character is uppercase
                printf(" Uppercase letter found: %c \n", carManufacturer[i][j]); //Printing uppercase letter
            }
        }
    }

    //Converting all string to Uppercase
    printf("\nChecking for uppercase letters");
    for (int i = 0; i < 5; i++) {  //Looping through all strings
        for (int j = 0; carManufacturer[i][j] != '\0'; j++) { //Nested loop to loop through all characters in string
            carManufacturer[i][j] = toupper(carManufacturer[i][j]); //Converting character to uppercase
        }
    }

    //Printing all strings in array of strings
    printf("\nFinal list\n");
    for (int i = 0; i < 5; i++) { //Looping through all strings
        printf("%s\n", carManufacturer[i]); //Printing string
    }

    return 0;
}
