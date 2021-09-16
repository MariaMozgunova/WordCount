#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int B = 0, L = 0, W = 0;

void parse_args(int argc, char* argv[]) {
    if (argc == 2) {
        B = 1;
        L = 1;
        W = 1;
        return;
    }

    for (int i = 1; i < argc - 1; i++) {
        if (argv[i][0] == '-' && argv[i][1] == '-') {
            if (strcmp(argv[i], "--bytes") == 0) {
                B = 1;
            } else if (strcmp(argv[i], "--lines") == 0) {
                L = 1;
            } else if (strcmp(argv[i], "--words") == 0) {
                W = 1;
            }
        } else {
            if (strchr(argv[i], 'b') != 0) {
                B = 1;
            } 
            if (strchr(argv[i], 'l') != 0) {
                L = 1;
            } 
            if (strchr(argv[i], 'w') != 0) {
                W = 1;
            }
        }
    }    
}

int main(int argc, char* argv[]) {
    parse_args(argc, argv);
    const char* fname = argv[argc - 1];
    FILE* fp = fopen(fname, "r");
 
    int bytes = 0;
    int lines = 0;
    int words = 0;

    char cur = '\0';
    char prev = '\n';
    while ((cur = fgetc(fp)) != EOF) {
        bytes++;
        if (isspace(prev) == 0 && isspace(cur) != 0) {
            words++;
        } 
        if (cur == '\n') {
            lines++;
        }
        prev = cur;
    }

    if (isspace(prev) == 0) {
        lines++;
        words++;
    }
    printf("%d %d %d", B, L, W);
    if (B == 1) {
        printf("Number of bytes: %d\n", bytes);
    } 
    if (L == 1) {
        printf("Number of lines: %d\n", lines);
    } 
    if (W == 1) {
        printf("Number of words: %d\n", words);
    }
    
    fclose(fp);
    return 0;
}