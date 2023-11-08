#include <stdio.h>

#define SIZE 21 // Number of ratings

float averageRating(int rating[SIZE]) {
    //Calculate avarage rating
    int sum = 0;
    for (int i = 0; i < SIZE; i++) {
        sum += rating[i];
    }
    float avarage = (float) sum / SIZE; // Calculate avarage
    return avarage;
}

int maxValue(int arr[5]) {
    //Find max value
    int max = arr[0];
    for (int i = 0; i < 5; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

int main() {

    int rating[SIZE];
    printf("Enter ratings from 1 to 5.\n");
    for (int i = 0; i < SIZE; i++) {
        printf("Enter rating number %d: ", i + 1);
        scanf_s("%d", &rating[i]); // Input rating
    }
    printf("Avarage rating = %.1f", averageRating(rating));

    int ratingFrequency[5] = {0, 0, 0, 0, 0}; // Array for rating frequency
    for (int i = 0; i < SIZE; i++) {
        ratingFrequency[rating[i] - 1]++; // Count rating frequency
    }

    printf("\n-------------\nRating frequency:\n-------------\n\n");
    int max = maxValue(ratingFrequency);
    for (int i = 0; i < 5; i++) {
        printf("%d star:  ", i + 1);
        for (int j = 0; j < ratingFrequency[i]; j++) { // Print stars
            printf("*");
        }
        for (int j = 0; j < max - ratingFrequency[i] + 2; j++) { // Print spaces
            printf(" ");
        }
        printf("%d", ratingFrequency[i]); // Print rating frequency
        printf("\n");
    }

    float ratingPercent[5]; // Array for rating percent
    int tempRatingFrequency[5] = {0, 0, 0, 0, 0}; //Array strictly for print correct amount of spaces
    for (int i = 0; i < 5; i++) {
        ratingPercent[i] = (float) ratingFrequency[i] / SIZE * 100; // Calculate rating percent
        tempRatingFrequency[i] = ratingFrequency[i] * 100 / SIZE;
    }
    printf("-------------\nRating percent:\n-------------\n\n");
    max = maxValue(tempRatingFrequency);
    for (int i = 0; i < 5; i++) {
        printf("%d star:   ", i + 1);

        for (int j = 0; j < tempRatingFrequency[i] + 1; j++) {
            printf("*"); // Print stars
        }
        for (int j = 0; j < max - tempRatingFrequency[i] + 2; j++) {
            printf(" "); // Print spaces
        }
        printf("%.1f %%", ratingPercent[i]);
        printf("\n");
    }
    printf("-------------");
    return 0;
}
