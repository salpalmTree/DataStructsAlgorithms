#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b); 
void bubblesort(int *array, int size); 
int main(void) {

    int array[] = {6, 4, 5, 1, 8, 9, 2, 3, 7, 0}; 
    int size = sizeof(array) / sizeof(array[0]); 

    printf("Before bubblesort:\n"); 
    for(int i = 0; i < size; i++){
        printf("%d, ", array[i]); 
    }
    printf("\n\n"); 

    bubblesort(array, size); 

    printf("After bubblesort:\n"); 
    for(int i = 0; i < size; i++) {
        printf("%d, ", array[i]); 
    }


    return 0; 
}

void swap(int *a, int *b){
    int temp = *a; 
    *a = *b; 
    *b = temp; 
}

void bubblesort(int *array, int size){
    int *prev = &array[0];  
    int *next = &array[1]; 
    for(int i = 0; i < size; i++){
        for(int j = 1; j < size; j++){
            if (*prev > *next){
                swap(prev, next); 
            }
            prev++; 
            next++; 
        }
        prev = &array[0]; 
        next = &array[1]; 
    }
}

