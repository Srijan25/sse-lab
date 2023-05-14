#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SYMBOLS 1000
#define MAX_IDENTIFIER_LENGTH 100

typedef struct {
    char name[MAX_IDENTIFIER_LENGTH];
    int is_function;
} symbol_t;

int num_symbols = 0;
symbol_t symbol_table[MAX_SYMBOLS];

void add_symbol(char *name, int is_function) {
    if (num_symbols == MAX_SYMBOLS) {
        fprintf(stderr, "Symbol table full\n");
        exit(1);
    }
    strcpy(symbol_table[num_symbols].name, name);
    symbol_table[num_symbols].is_function = is_function;
    num_symbols++;
}

int is_keyword(char *word) {
    static char *keywords[] = {"auto", "break", "case", "char", "const", "continue", "default", "do", "double", "else", "enum", "extern", "float", "for", "goto", "if", "int", "long", "register", "return", "short", "signed", "sizeof", "static", "struct", "switch", "typedef", "union", "unsigned", "void", "volatile", "while", NULL};
    char **keyword = keywords;
    while (*keyword != NULL) {
        if (strcmp(word, *keyword) == 0) {
            return 1;
        }
        keyword++;
    }
    return 0;
}

int is_identifier(char *word) {
    if (!isalpha(word[0]) && word[0] != '_') {
        return 0;
    }
    for (int i = 1; word[i] != '\0'; i++) {
        if (!isalnum(word[i]) && word[i] != '_') {
            return 0;
        }
    }
    return 1;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <input.c>\n", argv[0]);
        exit(1);
    }
    char *filename = argv[1];
    FILE *file = fopen("input.c", "r");
    if (file == NULL) {
        fprintf(stderr, "Cannot open file: %s\n", filename);
        exit(1);
    }
    char word[MAX_IDENTIFIER_LENGTH];
    while (fscanf(file, "%s", word) == 1) {
        if (is_keyword(word)) {
            continue;
        }
        if (is_identifier(word)) {
            add_symbol(word, 0);
            continue;
        }
        if (word[0] == '(' && is_identifier(word + 1)) {
            char *function_name = word + 1;
            function_name[strlen(function_name) - 1] = '\0';
            add_symbol(function_name, 1);
            continue;
        }
    }
    fclose(file);
    printf("Symbol table:\n");
    for (int i = 0; i < num_symbols; i++) {
        printf("%s %s\n", symbol_table[i].is_function ? "Function" : "Identifier", symbol_table[i].name);
    }
    return 0;
}


// running command
// ./lexical_analyzer six.c  