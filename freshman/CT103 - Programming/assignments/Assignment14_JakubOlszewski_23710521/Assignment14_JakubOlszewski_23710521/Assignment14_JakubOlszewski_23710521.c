/*
 * Jakub Olszewski
 * 23710521
 * 16.01.2024
 * */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define GRID_SIZE 12
#define GRID_SIZE_FROM_ID 9


/**
 * Function to initialize the ship coordinates randomly
 * @param gridSize - size of the grid
 * @return void
*/
void initializeShipCoordinates(int gridSize);

/**
 * Function to search randomly for ship coordinates and count the number of attempts
 * @param gridSize - size of the grid
 * @return void
*/
void randomSearch(int gridSize);

/**
 * Function to sequentially search the grid for ship coordinates using recursion
 * @param gridSize - size of the grid
 * @param locationsTried - the number of locations tried
 * @return void
 */
void gridSearch(int gridSize, int locationsTried);

/**
 * Function to print the result of the search in similar formatting as the example
 * @param message - Search type
 * @param locationsTried - the number of locations tried
 * @param x - x coordinate
 * @param y - y coordinate
 */
void printResult(char *message, int locationsTried, int x, int y);

// Global variables for ship coordinates
int shipX;
int shipY;

int main() {
    // Seed the random number generator with the current time
    srand(time(NULL));
    // Initialize ship coordinates within main
    initializeShipCoordinates(GRID_SIZE);
    randomSearch(GRID_SIZE);
    gridSearch(GRID_SIZE, 0);
    printf("============= New Grid =============\n");
    initializeShipCoordinates(GRID_SIZE_FROM_ID);
    randomSearch(GRID_SIZE_FROM_ID);
    gridSearch(GRID_SIZE_FROM_ID, 0);
    return 0;
}

// Function to initialize the ship coordinates randomly
void initializeShipCoordinates(int gridSize) {
    shipX = rand() % gridSize;  // Random number between 0 and gridSize
    shipY = rand() % gridSize;  // Random number between 0 and gridSize
}

//Search randomly for ship coordinates and count the number of attempts
void randomSearch(int gridSize) {
    int attempts = 0;
    int found = 0;
    int x, y;

    while (!found) {
        x = rand() % gridSize; // Generating random coordinate for x, where x is between 0 and gridSize
        y = rand() % gridSize; // Generating random coordinate for y, where y is between 0 and gridSize
        attempts++;
        // Check if the current coordinates match the ship's coordinates
        if (x == shipX && y == shipY) {
            found = 1;
        }
    }
    printResult("Random Search", attempts, x, y);
}

// Sequentially search the grid for ship coordinates using recursion
void gridSearch(int gridSize, int locationsTried) {
    int currentX = locationsTried % gridSize; // Modulo operator to get the remainder of locationsTried / gridSize
    int currentY = locationsTried / gridSize; // Integer division to get the quotient of locationsTried / gridSize

    // Check if the current coordinates match the ship's coordinates
    if (currentX == shipX && currentY == shipY) {
        printResult("Grid Search", ++locationsTried, currentX, currentY);
        return;
    }

    // Move to the next position
    if (locationsTried + 1 < gridSize * gridSize) {
        // Recursively call gridSearch with the next position
        gridSearch(gridSize, locationsTried + 1);
    } else {
        // All positions searched, print a message
        printf("Ship not found after %d attempts.\n", locationsTried);
    }
}

void printResult(char *message, int locationsTried, int x, int y) {
    printf("--------- %s ---------\n", message);
    printf("Ship found after %d locations!\n", locationsTried);
    printf("Ship coordinates - x: %d, y: %d.\n", x, y);
}