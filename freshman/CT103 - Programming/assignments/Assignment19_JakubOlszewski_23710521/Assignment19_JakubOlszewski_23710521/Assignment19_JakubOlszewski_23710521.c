#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    char make[20];
    char model[20];
    int year;
} car;

car garage[10];

void readCars(char myfilePath[], int numCars);

void displayGarage(int numCars);

int checkYear(int numCars, int year);


int main() {
    char myfilePath[] = "C:\\Users\\jolsz\\uni\\freshman\\CT103 - Programming\\assignments\\Assignment19_JakubOlszewski_23710521\\carsYear.csv";
    readCars(myfilePath, 10);
    displayGarage(10);
    int ans = checkYear(10, 2016);
    printf("There are %d cars with year %d in the garage.\n", ans, 2016);
    return 0;
}

void readCars(char myfilePath[], int numCars) {
    FILE *file = fopen(myfilePath, "r");
    if (file == NULL) {
        printf("Error opening file!\n");
        return;
    }

    char line[200];
    int count = 0;

    while (fgets(line, sizeof(line), file) != NULL && count < numCars) {
        char *token = strtok(line, " ");
        if (token != NULL) { // check if the line is not empty
            strcpy(garage[count].make, token); // copy the make to the struct
            token = strtok(NULL, ","); // get the next token
            if (token != NULL) { // check if the token is not empty
                strcpy(garage[count].model, token); // copy the model to the struct
                token = strtok(NULL, ","); // get the next token
                if (token != NULL) { // check if the token is not empty
                    garage[count].year = atoi(token); // copy the year to the struct
                    count++; // increment the count
                }
            }
        }
    }

    fclose(file);
}


void displayGarage(int numCars) {
    printf("------- Cars in the garage -------\n");
    for (int i = 0; i < numCars; ++i) {
        printf("Car %d\n", i + 1);
        printf("Car make =  %s\n", garage[i].make);
        printf("Car model =  %s\n", garage[i].model);
        printf("Car Year =  %d\n", garage[i].year);
    }
}

int checkYear(int numCars, int year) {
    int count = 0;
    for (int i = 0; i < numCars; ++i) {
        if (garage[i].year == year) {
            count++;
        }
    }
    return count;
}
