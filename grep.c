#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>


void readFile(char* searchable, FILE *f){
    char line[256];
    int i = 1;
    bool match = false;
    line[strcspn(line, "\n")] = '\0';
    while(fgets(line, sizeof(line), f) != NULL){ 
        if(strstr(line, searchable) != NULL){
            printf("Found \"%s\" in line: %d\n", searchable, i);
            if(!match){
                match = true;
            }
        }
        i++;
    }
    if(!match){
        printf("\"%s\" not found in file", searchable);
    }

}

int main(int argc, char *argv[]){
    if(argc != 5) perror("Usage: ./search -f \"<PATH TO FILE>\" -s \"<SEARCH STRING>\"");
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