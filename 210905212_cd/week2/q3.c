#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char keywords[32][10] = {
    "auto", "double", "int", "struct",
    "break", "else", "long", "switch", "case", "enum", "register",
    "typedef", "char", "extern", "return", "union", "const", "float",
    "short", "unsigned", "continue", "for", "signed", "void",
    "default", "goto", "sizeof", "voltile", "do", "if", "static",
    "while"
};

int compare(const char *buffer) {
    for (int i = 0; i < 32; i++) {
        if (strcmp(buffer, keywords[i]) == 0) {
            return 1;
        }
    }
    return 0;
}

int main() {
    FILE* fin = fopen("q3_sample.c", "r");
    if (fin == NULL) {
        printf("Cannot find file!\n");
        exit(1);
    }

    int c = 0;
    char buffer[100];
    int i = 0;

    while ((c = fgetc(fin)) != EOF) {
        if (isalpha(c)) {
            while (isalpha(c)) {
                buffer[i++] = c;
                c = fgetc(fin);
            }
            buffer[i] = '\0';
            if (compare(buffer)) {
                for (int j = 0; buffer[j] != '\0'; j++) {
                    putchar(toupper(buffer[j]));
                }
                printf("\n");
            }
            i = 0;
        } else {
            putc(c,fin);
        }
    }

    fclose(fin);
    return 0;
}
