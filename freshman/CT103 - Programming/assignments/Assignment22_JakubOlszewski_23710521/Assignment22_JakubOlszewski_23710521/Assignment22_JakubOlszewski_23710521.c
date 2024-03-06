#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define filePath "C:\\Users\\jolsz\\uni\\freshman\\CT103 - Programming\\assignments\\Assignment22_JakubOlszewski_23710521\\article-irish-times.txt"

char alltext[200000]; // Array to store the entire text from the file
char oneline[1000]; // Buffer to store each line read from the file

// Function prototypes
int countSyllablesInAWord(char *word);

int countSentences(char *text);

double calculateIndex(char *text);

int main() {
    FILE *file_ptr;
    file_ptr = fopen(filePath, "r"); // Open the file for reading
    if (file_ptr == NULL) {
        printf("Could not open article\n"); // Print error message if file couldn't be opened
    } else {
        alltext[0] = '\0'; // Initialize alltext to an empty string
        // Read each line from the file and append it to alltext
        while (fgets(oneline, 999, file_ptr) != NULL) {
            strcat(alltext, oneline);
        }
        double index = calculateIndex(alltext); // Calculate the index of the article
        printf("The index of the article is %.2f\n", index); // Print the calculated index
        fclose(file_ptr); // Close the file
    }

    return 0;
}

// Function to count the number of syllables in a word
int countSyllablesInAWord(char *word) {
    int syllableCount = 0;
    int len = strlen(word);
    int i;
    for (i = 0; i < len; i++) {
        char c = tolower(word[i]);
        if (strchr("aeiouy", c) != NULL) { // Check if the character is a vowel
            syllableCount++;
            // Skip consecutive vowels
            while (i < len && strchr("aeiouy", tolower(word[i])) != NULL) {
                i++;
            }
        }
    }

    // Adjust syllable count if word ends with 'e'
    if (len > 0 && tolower(word[len - 1]) == 'e') {
        syllableCount--;
    }
    // If no syllable is counted, consider at least one syllable
    if (syllableCount == 0) {
        syllableCount = 1;
    }

    return syllableCount;
}

// Function to count the number of sentences in the text
int countSentences(char *text) {
    int sentenceCount = 0;
    int i = 0;
    // Iterate through each character in the text
    while (text[i] != '\0') {
        // Count sentence endings: '.', ':', ';', '?', '!'
        if (strchr(".:;?!", text[i]) != NULL) {
            sentenceCount++;
        }
        i++;
    }
    return sentenceCount;
}

// Function to calculate the Flesch-Kincaid Grade Level index
double calculateIndex(char *text) {

    double index;
    int syllableCount = 0;
    int sentenceCount = countSentences(text);
    int wordCount = 0;

    char word[100]; // Temporary variable to store each word
    int word_index = 0; // Index for the temporary word variable
    // Iterate through each character in the text
    while (*text != '\0') {
        if (isspace(*text)) {
            if (word_index > 0) {
                word[word_index] = '\0'; // Null-terminate the word
                wordCount++; // Increment the word count
                syllableCount += countSyllablesInAWord(
                        word); // Add the syllable count of the word to the total syllable count
                word_index = 0; // Reset the index for the next word
            }
        } else if (isalnum(*text)) {
            word[word_index++] = *text; // Add character to the word
        }
        text++;
    }
    // Process the last word
    if (word_index > 0) {
        word[word_index] = '\0'; // Null-terminate the last word
        wordCount++; // Increment the word count
        syllableCount += countSyllablesInAWord(word); // Add the syllable count of the word to the total syllable count
    }
    // Calculate the Flesch-Kincaid Grade Level index
    index = 206.835 - 84.6 * ((double) syllableCount / (double) wordCount) -
            1.015 * ((double) wordCount / (double) sentenceCount);
    return index;
}
