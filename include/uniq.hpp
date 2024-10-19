#ifndef HEADER_UNIQ
#define HEADER_UNIQ

#include <iostream>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctype.h>
#include <stdio.h>

void *safe_malloc(int size);
void *safe_realloc(char* ptr, int size);
char *read_long_line(FILE *file);
FILE* safe_open(char* fileName);
FILE* safe_write(char* fileName);
#endif