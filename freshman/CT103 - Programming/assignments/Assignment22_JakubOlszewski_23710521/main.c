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
        printf("The number of words in the article is %d\n", countWords(alltext));
        fclose(file_ptr);
    }
}
