#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Node {
    char *data;
    struct Node *next; 
}Node; 

typedef struct HashMap {
    int size;
    Node **array; 
}HashMap; 

// -------- Helper functions -------------

void string_copy(char *to, const char *from){
    while(*from != '\0'){
        *to++ = *from++; 
    } 
    *to = '\0'; 
}

int string_len(const char *string){
    int len = 0; 
    while(*string++ != '\0'){
        len++; 
    } 
    return len; 
}

int same_string(const char *s1, const char *s2){
    while(*s1++ != '\0' && *s2++ != '\0'){
        if(*s1 != *s2){
            return 0; 
        }
    }
    return 1; 
}



// -------- Node Functions -------------

Node *create_node(const char *value){
    Node *new_node = (Node *)malloc(sizeof(Node)); 
    if(!new_node) return NULL; 
    new_node->data = (char*)malloc(string_len(value) + 1); 
    string_copy(new_node->data, value); 
    new_node->next = NULL; 
    return new_node; 
}

void insert_node(Node **head, const char *value){
    Node *new_node = create_node(value); 
    if(!new_node) return; 

    if(!*head) {
        *head = new_node; 
        return; 
    }
    Node *current = *head; 
    while(current) {
        if(!current->next) {
            current->next = new_node; 
            return; 
        }
        current = current->next; 
    }
}

char *get_value(Node *node){
    return node->data; 
}

// -------------- Hash map functions -------------------
HashMap *create_hash_map(int size){
    HashMap *new_map = (HashMap *)malloc(sizeof(HashMap)); 
    if(!new_map) return NULL; 

    new_map->size = size; 
    new_map->array = (Node **)malloc(sizeof(Node *) * new_map->size);
    for(int i = 0; i < new_map->size; i++){
        new_map->array[i] = NULL; 
    }
    return new_map; 
}

int hash(const char *value){
    int hash_code = 0; 
    int size = string_len(value); 

    for(int i = 0; i < size; i++){
        hash_code += (int)value[i]; 
    }
    return hash_code;  
}

int compress(int size, int hash_code){
    return hash_code % size;
}

void assign(HashMap *hm, const char *value){
    int array_idx = compress(hm->size, hash(value));
    // look for the place where the new node belongs
    insert_node(&hm->array[array_idx], value); 
}

Node *retrieve(HashMap *hm, const char *value){
    int array_idx = compress(hm->size, hash(value)); 
    // look for the node in a linked list
    Node *current = hm->array[array_idx]; 
    Node *prev = NULL; 
    while(current) {
        if(same_string(current->data, value)){
            if(!prev){
                hm->array[array_idx] = current->next; 
            }
            else{
                prev->next = current->next; 
            }
            return current; 
        }
        prev = current; 
        current = current->next; 
    }
    return NULL; 
}

int main(void){

    HashMap *my_hm = create_hash_map(5); 

    assign(my_hm, "Pineapple"); 
    assign(my_hm, "Strawberry");
    assign(my_hm, "Pear"); 
    assign(my_hm, "Kiwi"); 


    Node *target = retrieve(my_hm, "Kiwi"); 
    
    if(target) {
        printf("%s\n", target->data); 
    }
    else {
        printf("Invalid\n"); 
    }

    return 0; 
}
