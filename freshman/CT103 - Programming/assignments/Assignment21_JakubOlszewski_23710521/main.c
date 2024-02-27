#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

// Defining the constants

#define MAX_STRING 100 // Adjust the maximum length of the string as per your requirements
#define MAX_WORDS 100000  // Maximum number of words to be stored
#define MIN_LENGTH 4 // Minimum length of the word
#define MAX_LENGTH 7 // Maximum length of the word
#define FILE_PATH "C:\\Users\\jolsz\\uni\\freshman\\CT103 - Programming\\assignments\\Assignment21_JakubOlszewski_23710521\\dictionary.txt"

// Defining the global variables to avoid stack overflow
char words[MAX_WORDS][MAX_STRING]; // Array to store words

// Function prototypes

int readWordsFromFile(FILE *file_ptr, char (*words)[MAX_STRING]);

int rnd(int lower, int upper);

char *getRandomWord(char (*words)[MAX_STRING], int word_count);

void printArray(char *array, int length);

int checkGuess(const char *toGuess, int length);

void clearBuffer();

void startGame(char *word);

int main() {
    srand(time(NULL)); // Seed the random number generator

    // Open the file
    FILE *file_ptr;
    file_ptr = fopen(FILE_PATH, "r");

    if (file_ptr == NULL)
        printf("Could not open dictionary.txt");
    else {
        // Read the words from the file
        int word_count = readWordsFromFile(file_ptr, words);
        printf("Loaded %d suitable words from the dictionary\n", word_count);
        char *word = getRandomWord(words, word_count); // Get a random word
        startGame(word); // Start the game
        fclose(file_ptr); // Close the file
    }

    return 0;
}


/***
    * Function to read the words from the file
    * @param file_ptr: Pointer to the file
    * @param words: Array to store the words
    * @return word_count: Number of words read from the file
 */
int readWordsFromFile(FILE *file_ptr, char (*words)[MAX_STRING]) {
    int word_count = 0;
    char txt[MAX_STRING];

    while (fgets(txt, MAX_STRING - 1, file_ptr) != NULL) { // Read the words from the file
        txt[strlen(txt) - 1] = '\0'; // Remove the newline character
        if (strlen(txt) >= MIN_LENGTH && strlen(txt) <= MAX_LENGTH) { // Check the length of the word
            strcpy(words[word_count], txt); // Copy the word to the array
            word_count++; // Increment the word count
        }
    }

    return word_count;
}

/**
 * Function to generate a random number
 * @param lower: Lower limit of the random number
 * @param upper: Upper limit of the random number
 * @return: Random number
 */
int rnd(int lower, int upper) {
    int range = (upper - lower) + 1;
    return (rand() % range) + lower;
}

/**
 * Function to get a random word from the array
 * @param words: Array of words
 * @param word_count: Number of words in the array
 * @return: Random word
 */
char *getRandomWord(char (*words)[MAX_STRING], int word_count) {
    return words[rnd(0, word_count) - 1];
}

/**
 * Function to check if the word has been guessed
 * @param toGuess: Word to be guessed
 * @param length: Length of the word
 * @return: 1 if the word has been guessed, 0 otherwise
 */
int checkGuess(const char *toGuess, int length) {
    for (int i = 0; i < length; i++) {
        if (toGuess[i] == '-') {
            return 0;
        }
    }
    return 1;
}

/**
 * Function to print the array
 * @param array: Array to be printed
 * @param length: Length of the array
 */
void printArray(char *array, int length) {
    for (int i = 0; i < length; i++) {
        printf("%c", array[i]);
    }
    printf("\n");
}

/**
 * Function to clear the input buffer
 */
void clearBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

/**
 * Function to start the game
 * @param word: Word to be guessed
 */
void startGame(char *word) {
    int wordLength = strlen(word); // Get the length of the word
    int guessCount = 0; // Initialize the guess count
    char toGuess[wordLength]; // Array to store the word to be guessed
    // Initialize the array
    for (int i = 0; i < wordLength; i++) {
        toGuess[i] = '-';
    }
    // Start the game
    // Using checkGuess function to check if the word has been guessed
    while (!checkGuess(toGuess, wordLength)) {
        char guess;

        // Print the status of the game
        printf("Guess %d.\n", guessCount + 1);\
        printArray(toGuess, wordLength);
        printf("Guess a letter >");
        scanf("%c", &guess);
        printf("\n");

        clearBuffer(); // Clear the input buffer

        // Check if the guess is correct
        for (int i = 0; i < wordLength; i++) {
            if (word[i] == guess) {
                toGuess[i] = guess;
            }
        }

                guessCount++; // Increment the guess count
    }

    printf("Well done, that took you %d guesses to find %s\n", guessCount, word);
}