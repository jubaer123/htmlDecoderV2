#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "helper.h"

#define MAX_CHAR 100001

void loadChar(char* fileChar,FILE* f){
    int max_char=MAX_CHAR;
    char * buffer=fileChar;
    while (fgets(buffer, max_char, f) != NULL){
        buffer=(fileChar+strlen(fileChar));
        max_char=MAX_CHAR-strlen(fileChar);
    }
}

int main(int argc, char** argv){
    if(argc<2){
        printf("File name not given\n");
        return EXIT_FAILURE;
    }
    FILE* f;
    f=fopen(argv[1],"r");
    if(f==NULL){
        printf("File can not be opened\n");
        return EXIT_FAILURE;
    }
    char* fileChar=(char*) malloc(MAX_CHAR);
    loadChar(fileChar,f);
    char** tags=(char**)malloc(100001);
    int* count=(int*)calloc(100,sizeof(int));
    int size=0;
    doProcess(fileChar, &size,tags,count);
    free(fileChar);
    for(int i=0; i<size; i++)
        printf("%s\t\t\t%d\n",*(tags+i),*(count+i));
    free(tags);
    free(count);
    return EXIT_SUCCESS;
}