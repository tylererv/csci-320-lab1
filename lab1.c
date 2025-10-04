#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lab1.h"

/*
 * readString - reads a line from a file given by
 * fileName and returns it as a c-string.  The line
 * return is removed from the string.
 * 
 * fileName is c-string representing the file to read.
 * 
 */
char* readString(char* fileName){
    
    // Open file
    char* charArrPtr;
    FILE* fp = fopen(fileName, "r");
    
    if (fp == NULL) {
        perror("File doesn't exist");
        exit(3);
    }

    // Allocate base memory of (char size) * 100 for char array
    charArrPtr = (char*)malloc(sizeof(char)*MAX_LINE_LEN);
    if (charArrPtr == NULL) {
        perror("Unable to allocate memory :(");
        exit(3);
    }
    // Read file for string and return char* to string and close file
    // Based off if fgets works or not

    if (fgets(charArrPtr, MAX_LINE_LEN, fp) != NULL) {
        fclose(fp);
        return charArrPtr;
        //printf("%s", charArrPtr);
    } else {
        fclose(fp);
        free(charArrPtr);
        return NULL;
    }
}

/*
 * mysteryExplode - takes a string of characters and explodes it
 * as follows:
 * 
 * A non-empty string such as "Code" is turned into "CCoCodCode".
 *
 *   Return a new string similar to the string given above.
 *
 *  Example:
 *   mysteryExplosion("Code") --> "CCoCodCode"
 *   mysteryExplosion("abc") --> "aababc"
 *   mysteryExplosion(":)") --> "::)"
 * 
 */
char* mysteryExplode(const char* str){
    
    size_t len = strlen(str);

    // Creates a new string with exact length needed for 
    char* concatStr = (char*)malloc(((sizeof(char)) * ((len*(len+1))) / 2) + 1);
    if (concatStr == NULL) {
        perror("Failed to allocate memory");
        exit(3);
    }

    char* p = concatStr;
    for (size_t i = 1; i <= len; i++) {

        for (size_t j = 0; j < i; j++) {
            *p = str[j];
            p++; 
        }
    }
    
    *p = '\0';
    return concatStr;
}