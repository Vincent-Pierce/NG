#include "uniq.hpp"

int main(int argc, char* argv[]) {
    int c;
    FILE *inFile = stdin;
    FILE *outFile = stdout;
    //char *in, *out;
    //char* inFilePath = "C:Users/vinhp/Documents/NG/repos/Uniq/src/";
    //printf("0: %s 1: %s 2: %s argc: %i %s\n", argv[0], argv[1], argv[2], argc, inFilePath);
    //switch(argc){
    //    case(1):           /* no input or output .txt files default to stdin & stdout */
    //        break;
    //    case(3):            
    //        strcat(inFilePath, argv[2]); // in is bad inFilePath has the final string
    //        printf("filePath: %s\n", inFilePath);
    //        inFile = fopen(inFilePath, "r");
    //        
    //        if(!strcmp(argv[1], "-o")) {
    //            outFile = fopen(argv[2], "w");
    //        }
    //        break;
    //    case(4):
    //        if(argv[1] == "-i") {
    //            if((inFile = fopen(argv[2], "r")) == NULL) {
    //                printf("Can't open file\n");
    //                return 1;
    //            }
    //        }
    //        if(argv[3] == "-o") {
    //            outFile = fopen(argv[3], "w");
    //        }
    //        break;
    //    default:
    //        printf("Should not be in default \n");
    //}


    //printf("HEREEEEEE\n");
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
    return 0;
}