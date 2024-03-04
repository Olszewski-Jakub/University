#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define filePath "C:\\Users\\jolsz\\uni\\freshman\\CT103 - Programming\\assignments\\Assignment22_JakubOlszewski_23710521\\article-irish-times.txt"

char alltext[200000];
char oneline[1000];

int countWords(char *text) {
    int wordCount = 0;
    int i = 0;
    int inWord = 0;
    while (text[i] != '\0') {
        if (isalpha(text[i])) {
            if (!inWord) {
                inWord = 1;
                wordCount++;
            }
        } else {
            inWord = 0;
        }
        i++;
    }
    return wordCount;
}

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
        printf("\nThe number of words in the article is %d\n", countWords(alltext));
        fclose(file_ptr);
    }

    //Add testcase for countSyllablesInAWord
//    printf("The number of syllables in the word 'hello' is %d\n", countSyllablesInAWord("hello"));
//    printf("The number of syllables in the word 'world' is %d\n", countSyllablesInAWord("world"));
//    printf("The number of syllables in the word 'syllable' is %d\n", countSyllablesInAWord("syllable"));
//    printf("The number of syllables in the word 'count' is %d\n", countSyllablesInAWord("count"));
//    printf("The number of syllables in the word 'real' is %d\n", countSyllablesInAWord("real"));
//    printf("The number of syllables in the word 'regal' is %d\n", countSyllablesInAWord("regal"));

    //Add testcase for countSentences
//    printf("The number of sentences in the article is %d\n", countSentences("The index is computed by the following formula:"));
//    printf("The number of sentences in the article is %d\n", countSentences("Count all sentences. A sentence is ended by a full stop, colon, semicolon, question mark, or exclamation mark."));

}
