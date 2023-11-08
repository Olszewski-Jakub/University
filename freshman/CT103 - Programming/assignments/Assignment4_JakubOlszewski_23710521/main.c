#include <stdio.h>

int main() {
    int numberOfChildren = 0;
    int ageSum = 0;
    int currentAge = 0; // Current age is used to check for conditions and rest of calculations, so it can not be short int , because it is not limited by condition
    short int minAge = 18; // We can user short int, because age is always positive and we have condition limiting age to 18
    short int maxAge = 0;// We can user short int, because age is always positive and we have condition limiting age to 18
    while (currentAge >= 0) {
        printf("Enter age of children %d : ", numberOfChildren + 1);
        scanf_s("%d", &currentAge);
        if (currentAge >= 0 && currentAge < 18) {
            ageSum += currentAge;
            numberOfChildren++;
            if (currentAge < minAge) // Checking for min age
                minAge = currentAge;

            if (currentAge > maxAge) // Checking for max age
                maxAge = currentAge;
        }
        if (currentAge < 0) { // If current age is negative, we end the loop
            printf("Ending while loop\n");
        }
        // If current age is 18 or more, we print that it is not a child and ignore imputed value
        if (currentAge >= 18) {
            printf("Not a child\n");
        }
    }
    printf("There are %d children\n", numberOfChildren);
    float avarageAge = (float) ageSum /
                       (float) numberOfChildren; // We need to cast to float, because we want to get float result.
    printf("Average age of children is: %.2f\n", avarageAge);
    printf("Min age is: %d\n", minAge);
    printf("Max age is: %d\n", maxAge);
    return 0;
}
