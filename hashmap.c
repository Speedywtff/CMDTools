#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "hashmap.h"


hashmap* makeMap(){
    hashmap *m = malloc(sizeof(hashmap));
    if(m == NULL) return NULL;

    m->numOfElements = 0;
    m->capacity = 100;
    m->arr = (node**) malloc(m->capacity * sizeof(node));
    if(m->arr == NULL) return NULL;
    return m;
}

node* setNode(char* key, char* value){
    node *n = malloc(sizeof(node));
    if(n == NULL) return NULL;

    n->key = key;
    n->value = value; 
    n->next = NULL;
    return n; 
}

unsigned long hash_str(const char *str) {
    unsigned long hash = 50;
    int c;
    while ((c = *str++))
        hash = ((hash << 5) + hash) + c; // hash * 33 + c
    return hash;
}

int hash(hashmap *map, char *key) {
    return hash_str(key) % map->capacity;
}

void insertNode(hashmap* map, node* n){
    if(map->numOfElements < map->capacity){
        int bucket = hash(map, n->key);
        if(map->arr[bucket - 1] == NULL){
            map->arr[bucket - 1] = n;
        } else {
            node* curr = map->arr[bucket - 1];
            node* prev;
            while(curr != NULL){
                prev = curr;
                curr = curr->next;
            }
            prev->next = n;
        }
        map->numOfElements++;
    } else{
        map->capacity *= 2;
        map = (node**)realloc(map, map->capacity * sizeof(node));
    }

}

char* search(hashmap* map, char* key){
    int bucket = hash(map, key);
    if(map->arr[bucket - 1] == NULL){
        return NULL;
    } else{
        node* curr = map->arr[bucket - 1];
        while(curr->key != key){
            curr = curr->next;
            if(curr == NULL){
                return NULL;
            }
        }
        return curr->value;
    }
}

void deleteNode(hashmap* map, node* n){
    int bucket = hash(map, n->key);
    if(map->arr[bucket - 1] == NULL){
        return NULL;
    } else{
        node* curr = map->arr[bucket - 1];
        node* prev;
        while(curr->key != n->key){
            prev = curr;
            curr = curr->next;
            if(curr == NULL){
                return NULL;
            }
        }
        if(curr->next != NULL){
            prev->next = curr->next;
        }else{
            prev->next = NULL;
        }
        free(n);
}

int main(){
    hashmap* m = makeMap();
    node* n = setNode("Hi", "true");
    node* ntwo = setNode("iH", "false");
    insertNode(m, ntwo);
    insertNode(m, n);
    char* val = search(m, "Hi");
    printf("%s", val);
}