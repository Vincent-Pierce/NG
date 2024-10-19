#include "uniq.hpp"

int main(int argc, char* argv[]) {
    int c;
    FILE *inFile = stdin;
    FILE *outFile = stdout;
    inFile = safe_open(argv[1]);
    outFile = safe_write(argv[2]);
    char* oldLine, *newLine;
    oldLine = read_long_line(inFile); /* first line */
    fputs(oldLine, outFile);          /* or use puts(oldLine) automatically opens stream stdout */
    newLine = read_long_line(inFile);
    while(newLine != NULL) {
        if(strcmp(oldLine, newLine)) {     /* print if not equal */
            fputs(newLine, outFile);
            oldLine = newLine;
        }
        newLine = read_long_line(inFile);
    }

    if (fclose(inFile)) {
        printf("Error closing fin");
    }
    if (fclose(outFile)) {
        printf("Error closing fout");
    }
    return 0;
}
