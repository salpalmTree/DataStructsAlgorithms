#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int max_cap = 25; 

typedef struct max_heap {
    int count; 
    int *heap_list;
    int capacity; 
}max_heap; 

// swapping helper function
void swap(int *a, int *b){
    int temp = *a; 
    *a = *b; 
    *b = temp; 
}

// Heap helper functions
int parent_idx(int idx){
    return idx / 2; 
}

int right_child(int idx){
    return idx * 2; 
}

int left_child(int idx){
    return idx * 2 + 1; 
}

// Initialize a heap given a capacity
max_heap *init_max_heap(int max_capacity){
    max_heap *new_heap = (max_heap *)malloc(sizeof(max_heap)); 
    if(!new_heap) return NULL;

    new_heap->count = 0; 
    new_heap->heap_list = (int *)malloc(sizeof(int) * max_capacity); 
    if(!new_heap->heap_list) return NULL; 
    new_heap->capacity = max_capacity; 

    return new_heap; 
    
}

// Used after adding a new element into the heap
void heapify_up(max_heap *root){
    if(!root) return; 
    int idx = root->count; 
    while(parent_idx(idx) > 0){
        if(root->heap_list[idx] > root->heap_list[parent_idx(idx)]){
            swap(&root->heap_list[idx], &root->heap_list[parent_idx(idx)]); 
        }
        idx = parent_idx(idx); 
    }
    printf("Heap restored.\n"); 
} 

// Add element into heap
void add(max_heap *root, int element){
    if(!root) return; 
    printf("Adding %d to heap.\n", element);
    root->count++; 
    root->heap_list[root->count] = element; 
    // heapify up
    heapify_up(root); 
}

// Used when we extract the root
void heapify_down(max_heap *root){
    int idx = 1; 
    int greater = idx;
    while(1){
        int left = left_child(idx); 
        int right = right_child(idx); 
        if(left <= root->count && root->heap_list[left] > root->heap_list[greater]){
            greater = left; 
        }
        if(right <= root->count && root->heap_list[right] > root->heap_list[greater]){
            greater = right; 
        }
        if(greater != idx){
            swap(&root->heap_list[idx], &root->heap_list[greater]); 
            idx = greater; 
        }
        else {
            break; 
        }
    }
    printf("HEAP RESTORED!\n"); 
    for(int i = 1; i <= root->count; i++){
        printf("%d, ", root->heap_list[i]); 
    }
    printf("\n"); 
}

// Extracts root, and organizes the heap
int extract_root(max_heap *root){
    if(root->count == 0){
        printf("List is empty.\n"); 
        return INT16_MIN; 
    }
    int max = root->heap_list[1]; 
    root->heap_list[1] = root->heap_list[root->count]; 
    root->count--; 
    printf("Removed: %d\n", max); 
    heapify_down(root); 
    return max; 
}
int main(void) {

    max_heap *my_heap = init_max_heap(max_cap); 
    
    add(my_heap, 3); 
    add(my_heap, 6); 
    add(my_heap, 10); 
    add(my_heap, 8); 
    add(my_heap, 9); 
    add(my_heap, 12); 
    add(my_heap, 14); 
    add(my_heap, 4); 

    printf("Heap list: \n"); 
    for(int i = 1; i <= my_heap->count; i++) {
        printf("%d, ", my_heap->heap_list[i]); 
    }

    printf("\nHeap sort: \n"); 
    while(my_heap->count > 0){
        extract_root(my_heap); 
    }
    printf("\n");

    return 0; 
}

