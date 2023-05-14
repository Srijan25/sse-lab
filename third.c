#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000

int main() {
    // Open the file for reading
    FILE *file = fopen("my_program.txt", "r");

    if (file == NULL) {
        fprintf(stderr, "Error: Unable to open file\n");
        exit(1);
    }

    // Parse the file for variable declarations
    char line[MAX_LINE_LENGTH];
    int count = 0;  // Initialize variable count to 0
    while (fgets(line, MAX_LINE_LENGTH, file)) {
        // Split the line into words using strtok
        char *word = strtok(line, " \t\n");
        while (word != NULL) {
            // Check if the word is a variable type (e.g. "int")
            if (strcmp(word, "int") == 0 || strcmp(word, "float") == 0 || strcmp(word, "char") == 0) {
                // Print the variable type
                printf("%s ", word);

                // Get the next word
                word = strtok(NULL, " \t\n");

                // Print the variable name (if it exists)
                if (word != NULL && word[strlen(word)-1] != ':') {
                    printf("%s\n", word);
                    count++;  // Increment the variable count
                }
            }

            // Get the next word
            word = strtok(NULL, " \t\n");
        }
    }

    // Print the total number of variables
    printf("Total number of variables: %d\n", count);

    // Close the file
    fclose(file);

    return 0;
}