#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

bool validate(char* filename){
    char* extension = strrchr(filename, '.');
    if(extension == NULL) return false;

    
    return true;

}

int main(int argc, char *argv[]){
    if(argc != 3) perror("Usage: ./search \"filename\" <PATH TO FILE>");
    char* searchable = argv[1];
    char* filename = argv[2];


    bool val = validate(filename);
    if(!val){
        perror("Cannot find file.");
        abort();
    } 
    FILE *fp;
    fp = fopen(filename, "r");
}