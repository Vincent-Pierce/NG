#include "uniq.hpp"

char *read_long_line(FILE *file) {
    uint32_t arraySize = 5;
    uint32_t count = 0;
    char character;
    char* buffer;
    buffer = (char*)safe_malloc(sizeof(char)*arraySize);   /* initially allocates array[5] chars */
    
    character = fgetc(file);                            /* first character */
    while((character != EOF) && (character != '\n')) {
        if(count > arraySize) {
            arraySize*=2;
            buffer = (char*)safe_realloc(buffer, sizeof(char)*arraySize);
        }
        buffer[count] = character;
        count++;
        character = fgetc(file);
    }
    buffer[count] = '\0'; 
    char* line = (char*) safe_malloc(sizeof(char)*(count+1));
    strncpy(line, buffer, (count+1));       /* include null byte */
    //free(buffer);
    return line;
}

void *safe_malloc(int size) {       /* returns array or exits function */                      
    void* temp;
    temp = malloc(size);
    if (temp == NULL) {
        std::cout << "malloc failed\n";
        perror(__FUNCTION__);
        exit(-1);
    }
    return temp;
}

void * safe_realloc(char* ptr, int size) {
    ptr = (char*)realloc(ptr, size);
    if(ptr == NULL) {
        perror("realloc");
        exit(2);
    }
    return ptr;
}

FILE *safe_open(char* fileName) {
    FILE* inFile = fopen(fileName, "r");
    if (!inFile) {
        perror("bad open\n");

    }
    return inFile;
}

