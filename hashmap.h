#ifndef HASHMAP_H
#define HASHMAP_H

typedef struct node* nodeptr;

typedef struct{
    char* key;
    char* value;
    nodeptr next; //Next hashbucket
} node;

typedef struct {
    int numOfElements;
    int capacity;
    nodeptr* arr;
} hashmap;


hashmap* makeMap();

node* setNode(char* key, char* value);

int hash(hashmap* map, char* key);

void insertNode(hashmap* map, node n);

void deleteNode(hashmap* map, node n);

char* search(hashmap* map, char* key);

#endif