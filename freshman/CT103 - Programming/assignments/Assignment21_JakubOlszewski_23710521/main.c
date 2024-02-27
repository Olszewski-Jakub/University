#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define MAX_STRING 100 // Adjust the maximum length of the string as per your requirements
#define MAX_WORDS 100000  // Maximum number of words to be stored
#define MIN_LENGTH 4 // Minimum length of the word
#define MAX_LENGTH 7 // Maximum length of the word
#define FILE_PATH "C:\\Users\\jolsz\\uni\\freshman\\CT103 - Programming\\assignments\\Assignment21_JakubOlszewski_23710521\\dictionary.txt"

char words[MAX_WORDS][MAX_STRING]; // Array to store words

int readWordsFromFile(FILE *file_ptr, char (*words)[MAX_STRING]);

int rnd(int lower, int upper);

char *getRandomWord(char (*words)[MAX_STRING], int word_count);

void printArray(char *array, int length);

int checkGuess(const char *toGuess, int length);

void clearBuffer();

void startGame(char *word);

int main() {
    FILE *file_ptr;
    file_ptr = fopen(
            FILE_PATH,
            "r");

    if (file_ptr == NULL)
        printf("Could not open dictionary.txt");
    else {
        int word_count = readWordsFromFile(file_ptr, words);
        printf("Loaded %d suitable words from the dictionary\n", word_count);
        char *word = getRandomWord(words, word_count);
        startGame(word);
        fclose(file_ptr);
    }

    return 0;
}

int readWordsFromFile(FILE *file_ptr, char (*words)[MAX_STRING]) {
    int word_count = 0;
    char txt[MAX_STRING];

    srand(time(NULL));

    while (fgets(txt, MAX_STRING - 1, file_ptr) != NULL) {
        txt[strlen(txt) - 1] = '\0';
        if (strlen(txt) >= MIN_LENGTH && strlen(txt) <= MAX_LENGTH) {
            strcpy(words[word_count], txt);
            word_count++;
        }
    }

    return word_count;
}

int rnd(int lower, int upper) {
    int range = (upper - lower) + 1;
    return (rand() % range) + lower;
}

char *getRandomWord(char (*words)[MAX_STRING], int word_count) {
    return words[rnd(0, word_count) - 1];
}

int checkGuess(const char *toGuess, int length) {
    int correct = 0;
    for (int i = 0; i < length; i++) {
        if (toGuess[i] == '-') {
            return 0;
        }
    }
    return 1;
}


void printArray(char *array, int length) {
    for (int i = 0; i < length; i++) {
        printf("%c", array[i]);
    }
    printf("\n");
}

void clearBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void startGame(char *word) {
    int wordLength = strlen(word);
    int guessCount = 0;
    char toGuess[wordLength];
    for (int i = 0; i < wordLength; i++) {
        toGuess[i] = '-';
    }
    int status = 0;
    while (status == 0) {
        printf("Guess %d.\n", guessCount + 1);\
        printArray(toGuess, wordLength);
        printf("Guess a letter >");
        char guess;
        scanf("%c", &guess);
        printf("\n");
        clearBuffer(); // Clear the input buffer

        for (int i = 0; i < wordLength; i++) {
            if (word[i] == guess) {
                toGuess[i] = guess;
            }
        }

        status = checkGuess(toGuess, wordLength);
        guessCount++;
    }

    printf("Well done, that took you %d guesses to find %s\n", guessCount, word);

}