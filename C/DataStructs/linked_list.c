#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    char data; 
    struct Node *next; 
}Node; 

void add_node(Node **head, const char value){
    if(!head) {
        printf("Head is not valid.\n"); 
        return; 
    } 
    Node *new_node = (Node*)malloc(sizeof(Node)); 
    if(!new_node){
        printf("Could not create new node"); 
        return; 
    } 
    new_node->data = value; 
    new_node->next = *head; 
    *head = new_node; 
}

Node *remove_node(Node **head, const char value){
    if (!*head) return NULL; 
    if ((*head)->data == value) {
        // head node is the one to remove
        Node *to_return = *head; 
        *head = (*head)->next; 
        return to_return; 
    }
    // traverse list to find node to remove
    Node *prev = NULL; 
    Node *curr = (*head); 
    while (curr != NULL) {
        prev = curr; 
        curr = curr->next; 
        if (curr != NULL && curr->data == value){
            Node *to_return = curr; 
            prev->next = curr->next; 
            return to_return; 
        }
    }
    printf("%c was not found.\n", value); 
    return NULL; 
}

void add_node_after(Node **head, const char after_value, const char value){
    if (!*head){
        printf("Head is not valid.\n"); 
        return; 
    } 
    Node *to_add = (Node *)malloc(sizeof(Node)); 
    if (!to_add) {
        printf("Could not create new node.\n"); 
        return; 
    }
    to_add->next = NULL; 
    to_add->data = value; 

    if (after_value == (*head)->data) {
        // after head node
        to_add->next = (*head)->next; 
        (*head)->next = to_add; 
        return; 
    }
    Node *curr = *head; 
    while (curr != NULL && curr->data != after_value) {
        curr = curr->next; 
    }
    if(!curr) {
        printf("Could not find node to place new node after.\n"); 
        free(to_add); 
        return; 
    }
    to_add->next = curr->next; 
    curr->next = to_add; 
}

void print_list(Node *head){
    while(head != NULL){
        printf("%c -> ", head->data); 
        head = head->next; 
    }
    printf("\n"); 
}

int length_list(Node *head) {
    if (!head) return 0; 
    int count = 0; 
    while(head != NULL) {
        head = head->next;
        count++; 
    }
    return count; 
}




int main(void) {

    Node *head = NULL; 
    Node *test = NULL; // will remain empty 

    add_node(&head, 'A'); 
    add_node(&head, 'B');
    add_node(&head, 'C'); 

    print_list(head); 
    
    Node *removed = remove_node(&head, 'C'); 

    if (removed != NULL){
        printf("Successfully removed node: "); 
        printf("%c\n", removed->data); 
    }

    print_list(head); 
    
    printf("Length of list is: %d\n", length_list(head)); 

    
    add_node_after(&head, 'B', 'Z'); 
    printf("Now adding node Z after B.\n"); 

    print_list(head); 


    return 0; 
}
