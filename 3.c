#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 100 // Size for temporary input buffer

int main()
{
    char *accumulator = NULL; // Holds the full concatenated string
    char *tempInput = (char *)malloc(BUFFER_SIZE * sizeof(char));

    if (tempInput == NULL)
    {
        printf("Initial memory allocation failed.\n");
        return 1;
    }

    // Initialize accumulator as an empty string
    accumulator = (char *)malloc(1 * sizeof(char));
    accumulator[0] = '\0';

    printf("Enter strings to concatenate (enter 'Q' to quit):\n");

    while (1)
    {
        printf("Input: ");
        // Read input
        if (fgets(tempInput, BUFFER_SIZE, stdin) == NULL)
            break;

        // Remove newline character from fgets
        tempInput[strcspn(tempInput, "\n")] = 0;

        // Check for 'Q' to stop
        if (strcmp(tempInput, "Q") == 0)
        {
            break;
        }

        // Calculate new size needed: current length + new part + 1 (null terminator)
        int currentLen = strlen(accumulator);
        int newPartLen = strlen(tempInput);
        int totalLen = currentLen + newPartLen + 1;

        // Reallocate memory
        char *ptr = (char *)realloc(accumulator, totalLen * sizeof(char));

        // Error handling for realloc
        if (ptr == NULL)
        {
            printf("Memory reallocation failed! Keeping previous data.\n");
            break;
        }
        else
        {
            accumulator = ptr; // Update accumulator to new address
        }

        // Concatenate
        strcat(accumulator, tempInput);

        // Output current state
        printf("Current Result: %s\n", accumulator);
    }

    printf("\nFinal Concatenated String: %s\n", accumulator);

    // Free memory
    free(tempInput);
    free(accumulator);

    return 0;
}