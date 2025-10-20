#ifndef HASHMAP_H
#define HASHMAP_H

typedef struct node node; 

struct node{
    char* key;
    char* value;
    node* next; //Next hashbucket
};

typedef struct {
    int numOfElements;
    int capacity;
    node** arr;
} hashmap;


hashmap* makeMap();

node*  setNode(char* key, char* value);

int hash(hashmap* map, char* key);

void insertNode(hashmap* map, node* n);

void deleteNode(hashmap* map, node n);

char* search(hashmap* map, char* key);

#endif