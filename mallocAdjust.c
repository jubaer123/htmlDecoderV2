#include <stdio.h> 
#include <string.h>
#include "Strings.h"

String mallocString(int stringsize){ 
String s=(String)malloc(sizeof(char)*stringsize); 
if(s==(String)NULL) 
return NULL; 
return s; 
} 

void freeString(String s){ 
free(s); 
} 

String duplicateString(String s){ 
String s2= mallocString(strlen(s)); 
if(s2==(String)NULL) 
return NULL; 
strcpy(s2,s); 
return s2; 
} 

int fputString(FILE* fpout, String s){ 
fprintf(fpout,"%d\n",strlen(s)); 
if(strlen(s)>0){ 
for(int i=0; i<strlen(s); i++) 
fprintf(fpout,"%c",*(s+i)); 
} 
return strlen(s); 
} 

String fgetString(FILE* pFin){ 
char c; 
int len; 
fscanf(pFin,"%d%c",&len,&c); 
if(len>0){ 
String ns=(String) malloc(len+10); 
int temp=0;
while ((c = fgetc(pFin)) != EOF){ 
*(ns+temp)= c; 
temp++; 
} 
*(ns+temp)= '\0'; 
return ns; 
} 
return NULL; 
}

String getString(FILE* pFin){ 
int max_char=100001; 
String fileChar=(String) malloc(100001); 
String buffer=fileChar; 
while (fgets(buffer, max_char, stdin) != NULL){ 
buffer=(fileChar+strlen(fileChar)); 
max_char=100001-strlen(fileChar); 
} 
return fileChar; 
}







