#include "utils.c"

int main(int argc, char* argv[]) {
    parse_args(argc, argv);
    const char* fname = argv[argc - 1];
    FILE* fp = fopen(fname, "r");
    int res[3];
    solve(fp, res);

    if (B == 1) {
        printf("Number of bytes: %d\n", res[0]);
    } 
    if (L == 1) {
        printf("Number of lines: %d\n", res[1]);
    } 
    if (W == 1) {
        printf("Number of words: %d\n", res[2]);
    }
    
    fclose(fp);
    return 0;
}
