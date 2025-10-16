#include <stdlib.h>
#include <string.h>
#include "hashmap.h"


hashmap* makeMap(){
    hashmap *m = malloc(sizeof(hashmap));
    if(m == NULL) return NULL;

    m->numOfElements = 0;
    m->capacity = 0;
    m->arr = NULL;
    return m;
}

node* setNode(char* key, char* value){
    node *n = malloc(sizeof(node));
    if(n == NULL) return NULL;

    n->key = key;
    n->value = value; 
    n->next = NULL;
    
}

unsigned long hash_str(const char *str) {
    unsigned long hash = 5381;
    int c;
    while ((c = *str++))
        hash = ((hash << 5) + hash) + c; // hash * 33 + c
    return hash;
}

int hash(hashmap *map, char *key) {
    return hash_str(key) % map->capacity;
}