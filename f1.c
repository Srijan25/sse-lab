#include <stdio.h>

int main() {
    FILE *input_file, *output_file;
    int prev_char = EOF, curr_char;

    // Open the input and output files
    input_file = fopen("f1.c", "r");
    output_file = fopen("f2.c", "w");

    // Read the input file character by character
    while ((curr_char = fgetc(input_file)) != EOF) {
        // Check for start of a multiline comment 
        if (curr_char == '/' && prev_char == '*') {
            // Keep reading until end of multiline comment 
            while ((curr_char = fgetc(input_file)) != EOF) {
                if (curr_char == '/' && prev_char == '*') {
                    break;
                }
                prev_char = curr_char;
            }
            continue;
        }

        // Check for start of a single-line comment 
        if (curr_char == '/' ) {
            // Keep reading until end of line 
            while ((curr_char = fgetc(input_file)) != EOF) {
                if (curr_char == '\n') {
                    break;
                }
                prev_char = curr_char;
            }
            continue;
        }

        // Write non-comment characters to the output file
        fputc(curr_char, output_file);
        prev_char = curr_char;
    }

    // Close the input and output files
    fclose(input_file);
    fclose(output_file);

    return 0;
}