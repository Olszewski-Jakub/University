#include <stdio.h>
#include <string.h>
#include <stdlib.h>


typedef struct {
    char description[100];
    int n, s, e, w, in, out;
} location;
location locations[40];
int numLocations = 0;
char locationsFile[] = "..//adventure_locations.txt";

/**
 * @brief Opens a file for reading.
 *
 * This function opens a file with the given filename for reading. If the file cannot be opened, it prints an error message and returns NULL.
 *
 * @param filename The name of the file to open.
 * @return A pointer to the opened file, or NULL if the file could not be opened.
 */
FILE *openFileForReading(char *filename);

/**
 * @brief Reads location data from a file.
 *
 * This function reads location data from a file. The location data is stored in the global locations array.
 *
 * @return 1 if the locations were successfully read, or 0 if the file could not be opened.
 */
int readLocations();

/**
 * @brief Moves the player in a given direction.
 *
 * This function attempts to move the player in the given direction. If the move is valid (i.e., there is a location in that direction), it updates the current location ID and calls the look function to describe the new location. If the move is not valid, it prints a message saying "You can't go that way".
 *
 * @param direction The direction to move in. This should be one of the direction fields (n, s, e, w, in, out) of the current location.
 * @param currentLocationId A pointer to the current location ID. This will be updated if the move is valid.
 */
void move(int direction, int *currentLocationId);

void move(int direction, int *currentLocationId);

/**
 * @brief Processes a command entered by the user.
 *
 * This function processes a command entered by the user. The command can be a direction (n, s, e, w, in, out), or one of the commands look, help, or quit.
 *
 * @param command The command entered by the user.
 * @param currentLocationId A pointer to the current location ID. This will be updated if the user moves to a new location.
 */
void processCommand(char *command, int *currentLocationId);

/**
 * @brief Prints the description of the current location.
 *
 * This function prints the description of the current location.
 *
 * @param locationId The ID of the location to look at.
 */
void look(int locationId);

/**
 * @brief Prints a help message.
 *
 * This function prints a help message, listing the commands that the user can enter.
 */
void help();

/**
 * @brief Quits the game.
 *
 * This function quits the game by calling exit(0).
 */
void quit();

int main() {
    if (readLocations()) {
        printf("Successfully read %d locations from file\n", numLocations);
    }

    int currentLocationId = 1;

    printf("Welcome to Galway Adventure. Type 'help' for help\n");
    printf("%s", locations[currentLocationId].description);
    printf("warning: this programs uses gets(), which is unsafe\n");

    /**
 * @brief Main game loop.
 *
 * This is the main game loop. It runs indefinitely until the user enters the 'quit' command.
 * In each iteration of the loop, it prompts the user for a command, reads the command using gets(),
 * and then processes the command using the processCommand() function.
 */
    while (1) {
        // The command entered by the user.
        char command[100];

        // Prompt the user for a command.
        printf("> ");

        // Read the command from the user. Note: gets() is unsafe and should be replaced with fgets().
        gets(command);

        // Process the command entered by the user.
        processCommand(command, &currentLocationId);
    }

}

FILE *openFileForReading(char *filename) {
    FILE *file_ptr = fopen(filename, "r");
    if (file_ptr == NULL)
        printf("Could not open %s\n", filename);
    return file_ptr;
}

int readLocations() {
    FILE *file_ptr = openFileForReading(locationsFile);
    if (file_ptr == NULL)
        return 0;
    numLocations = 0;
    int readHeaderLines = 0;
    char line[200];
    while (fgets(line, 99, file_ptr) != NULL) {
        if (readHeaderLines < 2)
            readHeaderLines++;
        else {
            numLocations++;
            location l;
            int locNum;
            sscanf(line, "%d\t%d\t%d\t%d\t%d\t%d\t%d\t%[^\t]\n", &locNum, &l.n,
                   &l.s, &l.e, &l.w, &l.in, &l.out, l.description);
            locations[numLocations] = l; // the 1st location is 1 (not 0) so we can use 0 to mean 'nothing' in adventure_locations.txt
        }
    }
    return 1;
}

void move(int direction, int *currentLocationId) {
    if (direction != 0) {
        *currentLocationId = direction;
        look(*currentLocationId);
    } else {
        printf("You can't go that way\n");
    }
}


void processCommand(char *command, int *currentLocationId) {
    if (strcmp(command, "look") == 0) {
        look(*currentLocationId);
    } else if (strcmp(command, "help") == 0) {
        help();
    } else if (strcmp(command, "quit") == 0) {
        quit();
    } else if (strcmp(command, "n") == 0) {
        move(locations[*currentLocationId].n, currentLocationId);
    } else if (strcmp(command, "s") == 0) {
        move(locations[*currentLocationId].s, currentLocationId);
    } else if (strcmp(command, "e") == 0) {
        move(locations[*currentLocationId].e, currentLocationId);
    } else if (strcmp(command, "w") == 0) {
        move(locations[*currentLocationId].w, currentLocationId);
    } else if (strcmp(command, "in") == 0) {
        move(locations[*currentLocationId].in, currentLocationId);
    } else if (strcmp(command, "out") == 0) {
        move(locations[*currentLocationId].out, currentLocationId);
    } else {
        printf("I don't understand %s\n", command);
    }
}

void look(int locationId) {
    printf("\n%s", locations[locationId].description);
}

void help() {
    printf("I know these commands:\n");
    printf("n, s, e, w, in, out, look, help, quit\n");
}

void quit() {
    printf("Goodbye\n");
    exit(0);
}

