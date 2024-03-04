#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define filePath "C:\\Users\\jolsz\\uni\\freshman\\CT103 - Programming\\assignments\\Assignment22_JakubOlszewski_23710521\\article-irish-times.txt"

char alltext[200000];
char oneline[1000];


int countSyllablesInAWord(char *word) {
    int syllableCount = 0;
    int len = strlen(word);
    int i;
    for (i = 0; i < len; i++) {
        char c = tolower(word[i]);
        if (strchr("aeiouy", c) != NULL) {
            syllableCount++;
            while (i < len && strchr("aeiouy", tolower(word[i])) != NULL) {
                i++;
            }
        }
    }

    if (len > 0 && tolower(word[len - 1]) == 'e') {
        syllableCount--;
    }
    if (syllableCount == 0) {
        syllableCount = 1;
    }

    return syllableCount;
}

int countSentences(char *text) {
    int sentenceCount = 0;
    int i = 0;
    while (text[i] != '\0') {
        if (strchr(".:;?!", text[i]) != NULL) {
            sentenceCount++;
        }
        i++;
    }
    return sentenceCount;
}

double calculateIndex(char *text){

    double index;
    int syllableCount = 0;
    int sentenceCount = countSentences(text);
    int wordCount = 0;

    char word[100]; // Temporary variable to store each word
    int word_index = 0; // Index for the temporary word variable
    while (*text != '\0') {
        if (isspace(*text)) {
            if (word_index > 0) {
                word[word_index] = '\0'; // Null-terminate the word
                wordCount++; // Increment the word count
                syllableCount += countSyllablesInAWord(word); // Add the syllable count of the word to the total syllable count
                word_index = 0; // Reset the index for the next word
            }
        } else if (isalnum(*text)) {
            word[word_index++] = *text; // Add character to the word
        }
        text++;
    }
    if (word_index > 0) {
        word[word_index] = '\0'; // Null-terminate the last word
        printf("%s\n", word); // Print the last word
        wordCount++; // Increment the word count
        syllableCount += countSyllablesInAWord(word); // Add the syllable count of the word to the total syllable count
    }
    index =  206.835 -84.6*((double)syllableCount/(double)wordCount) - 1.015*((double)wordCount/(double)sentenceCount);
    return index;
}

int main() {
    FILE *file_ptr;
    file_ptr = fopen(filePath, "r"); // open for reading
    if (file_ptr == NULL) {
        printf("Could not open article\n");
    } else {
        alltext[0] = '\0'; // make sure this string is empty
        while (fgets(oneline, 999, file_ptr) != NULL) {
            // read the next line and append it (with \n intact)
            strcat(alltext, oneline);
        }
        printf("%s", alltext);
        double index = calculateIndex(alltext);
        printf("The index of the article is %.2f\n", index);
        fclose(file_ptr);
    }

    return 0;
}
