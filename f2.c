#include <stdio.h>

int main() {
    FILE *input_file, *output_file;
    int prev_char = EOF, curr_char;

        input_file = fopen("f1.c", "r");
    output_file = fopen("f2.c", "w");

        while ((curr_char = fgetc(input_file)) != EOF) {
                if (curr_char == '                        while ((curr_char = fgetc(input_file)) != EOF) {
                if (curr_char == '                    break;
                }
                prev_char = curr_char;
            }
            continue;
        }

                if (curr_char == '                        while ((curr_char = fgetc(input_file)) != EOF) {
                if (curr_char == '\n') {
                    break;
                }
                prev_char = curr_char;
            }
            continue;
        }

                fputc(curr_char, output_file);
        prev_char = curr_char;
    }

        fclose(input_file);
    fclose(output_file);

    return 0;
}