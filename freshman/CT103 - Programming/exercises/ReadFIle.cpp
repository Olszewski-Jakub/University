#include <stdio.h>
#include <string.h>

#define MAXSTRING 100

int main()
{
    // fopen requests a file to be opened obtains a FILE pointer to access it
    FILE *file_ptr;
    file_ptr = fopen("dictionary.txt", "r"); // open for reading

    if (file_ptr == NULL)
        printf("Could not open dictionary.txt");
    else
    {
        char txt[MAXSTRING]; // string for reading each line into
        int lines = 0;
        while (fgets(txt, MAXSTRING - 1, file_ptr) != NULL)
        {
            lines++;
            txt[strlen(txt) - 1] = '\0'; // remove the \n which has also been read into the string!
            bool found = false;
            for (int i = 0; i < strlen(txt) && found == false; i++)
            {
                if (txt[i] == 's' )
                {
                    printf("%s\n", txt);
                    found = true;
                }
            }
            found = false;
        }
        printf("dictionary.txt contained %d lines.", lines);
        fclose(file_ptr); // don't forget to close the file
    }

    return 0;
}