#include <stdio.h>
#include <stdlib.h>

void input(int *arr, int start_index, int end_index) {
    for (int i = start_index; i < end_index; i++) {
        printf("Enter element #%d: ", i + 1);
        scanf("%d", &arr[i]);
    }
}


void display(int *arr, int count) {
    printf("\nCurrent Array (%d elements): [ ", count);
    for (int i = 0; i < count; i++) {
        printf("%d", arr[i]);
        if (i < count - 1) {
            printf(", ");
        }
    }
    printf(" ]\n");
}

int main() {
    int currentSize;
    int choice;
    int *arr = NULL;
    
    printf("--- INITIAL ALLOCATION ---\n");
    printf("Enter the initial number of integers to store: ");
    if (scanf("%d", &currentSize) != 1 || currentSize <= 0) {
        printf("Invalid size entered. Exiting.\n");
        return 1;
    }

    arr = (int *)calloc(currentSize, sizeof(int));
    if (arr == NULL) { 
        printf("ERROR! Initial memory allocation failed. Exiting.\n");
        return 1;
    }
    
    printf("\nMemory allocated successfully using calloc(). Initial values:\n");
    display(arr, currentSize);
    
    printf("\nNow, enter values for the initial %d elements:\n", currentSize);
    input(arr, 0, currentSize);
    display(arr, currentSize);


    printf("\n----------------------------------------\n");
    printf("Do you want to enlarge the array? (1=Yes, 0=No): ");
    scanf("%d", &choice);

    if (choice == 1) {
        int newSize;
        printf("Enter the new total size (must be > %d): ", currentSize);
        if (scanf("%d", &newSize) != 1 || newSize <= currentSize) {
            printf("Invalid or smaller/same size entered. Keeping original array.\n");
        } else {
           
            int oldSize = currentSize; 
            
            // Use realloc() to resize the memory block
            int *temp = (int *)realloc(arr, newSize * sizeof(int));

            // Check if reallocation was successful
            if (temp != NULL) {
                arr = temp; // Update the pointer to the new memory block
                currentSize = newSize; 

                printf("\n[SUCCESS] Array successfully resized from %d to %d elements.\n", oldSize, currentSize);
                
                printf("Enter values for the newly added %d elements (starting at index %d):\n", 
                       currentSize - oldSize, oldSize);
                

                input(arr, oldSize, currentSize); 
                
                printf("\n--- UPDATED ARRAY ---\n");
                display(arr, currentSize);
            } else {
                // If realloc fails
                printf("\n[ERROR] Memory reallocation failed. Array remains at %d elements.\n", currentSize);
            }
        }
    } else {
        printf("Array size remains unchanged.\n");
    }

    printf("\n----------------------------------------\n");
    printf("Freeing %d bytes of dynamically allocated memory.\n", currentSize * sizeof(int));
    free(arr); // Release the memory block
    arr = NULL;
    
    return 0;
}