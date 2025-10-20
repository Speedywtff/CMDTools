#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>


void readFile(char* searchable, FILE *f){
    char line[256];
    int i = 1;
    line[strcspn(line, "\n")] = '\0';
    while(fgets(line, sizeof(line), f) != NULL){  //DOES NOT WORK FOR SUBSTRINGS. 
        if(strcmp(line, searchable) == 0){
            printf("Found %s in line: %d\n", searchable, i);
        }
        i++;
    }

}

int main(int argc, char *argv[]){
    if(argc != 5) perror("Usage: ./search \"filename\" <PATH TO FILE> -s \"<SEARCH STRING>\"");
    char* search = argv[4];
    char* filename = argv[2];

    FILE *fp;
    fp = fopen(filename, "rb");
    if(fp == NULL){
        perror("Cannot find fine");
        abort();
    }

    readFile(search, fp);
}