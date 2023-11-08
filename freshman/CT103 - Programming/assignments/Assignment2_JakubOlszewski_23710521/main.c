/*
 * Jakub Olszewski
 * Student ID: 23710521
 * Date: 26.09.2023
 */

#include <stdio.h>

int convertCelciusToFahrenheit(int degC){
    int degF = 0;
     degF = 32 + (degC*9)/5; // Converts Celcuis to Fahrenheit using given formula
     return degF; //returns degrees in Fahrentheit
}

int convertFahrenheitToCelcius(int degF){
    int degC = 0;
    degC = (degF-32)*5/9; // Converts Fahrenheit to Celcuis using given formula
    return degC; //returns degrees in Celcius
}

int main() {
    int inputDegree = 0;
    printf("Enter temperature in degrees Fahrenheit:");
    scanf_s("%d",&inputDegree); //Assigning integer given by user into varible
    int degC = convertFahrenheitToCelcius(inputDegree); // executes converting fuvtion
    printf("Degrees in Celcius = %d \n", degC); // Prints a result
    if (degC>32){ // Checking specified condition
        printf("Too hot!");
    }
    if (degC<0){// Checking specified condition
        printf("Too cold!");
    }
    return 0;
}

