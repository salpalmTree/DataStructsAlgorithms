#include <stdio.h>

int binary_search(int *array, int size, int target){
    int left_p = 0; 
    int right_p = size; 

    while(left_p < right_p){
        int mid_idx = (right_p + left_p) / 2; 
        int mid_val = array[mid_idx]; 

        if(target == mid_val){
            return mid_idx; 
        }
        if(target < mid_val){
            right_p = mid_idx; 
        }
        if(target > mid_val) {
            left_p = mid_idx + 1; 
        }
    }
    return -1; 
}

int binary_search_rec(int *array, int left_p, int right_p, int target){
    if(left_p >= right_p){
        return -1; 
    }
    int mid_idx = (left_p + right_p) / 2; 
    int mid_val = array[mid_idx]; 

    if(mid_val == target){
        return mid_idx; 
    }
    if(mid_val < target) {
        return binary_search_rec(array, mid_idx + 1, right_p, target); 
    }
    if(mid_val > target) {
        return binary_search_rec(array, left_p, mid_idx, target); 
    }
    return -1; 
}

int main(void) {

    int my_array[] = {2, 4, 6, 8, 10, 12, 14, 16, 18, 20}; 
    int size = (sizeof(my_array) / sizeof(my_array[0])); 
    int target = 18; 

    int item = binary_search(my_array, size, target); 

    if (item < 0) {
        printf("Target: %d not found.\n", target); 
    }
    else{
        printf("Target %d found at index %d.\n", target, item); 
    }
    printf("\n\n"); 
    printf("Recursion:"); 
    int result = binary_search_rec(my_array, 0, size, target); 
    if(result > 0){
        printf("Target: %d found at index %d using recursion.\n", target, result); 
    }
    else{
        printf("No target found.\n"); 
    }


    return 0; 
}
