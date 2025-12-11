// Question 2: 
// (i) Malloc Calls Count
// 	Question: If m=5 and n=4 how many malloc calls are made?
// 	Answer: 6 calls.
// (ii) Error Checking
// 	Question: What error checking is missing?
// 	Answer: The code assumes malloc always succeeds.
// 	Check p:check if (p == NULL).
//	Check p[i]: Inside the loop, check if (p[i] == NULL). If a row fails, must free all previously allocated rows and p itself before returning to prevent leaks.
// (iii) Memory Leakage
// 	Question: The destroy_matrix function only has free(p). What is the fault?
// 	Answer: This causes a Memory Leak. free(p) only releases the array of pointers. The actual arrays of integers (the rows) allocated inside the loop are still in the heap.
// 	Correction: must free the inner arrays first.
void destroy_matrix(int **p, int m) {
    for(int i = 0; i < m; i++) {
        free(p[i]); 
    }
    free(p); 
}
// (iv) Optimization (2 Mallocs)
// 	Question: Rewrite to use only 2 malloc calls but keep **p syntax.
// 	Answer: Allocate the row pointers in one block, and all integer data in a second single contiguous block. Then, assign the row pointers to specific locations in the data block.

int** create_matrix_optimized(int m, int n) {
    // Call 1: Allocate pointers for rows
    int **p = (int **)malloc(m * sizeof(int *));

    // Call 2: Allocate ALL data in one flat block
    int *data = (int *)malloc(m * n * sizeof(int));

    // Link the pointers
    for (int i = 0; i < m; i++) {
        // Point row 'i' to the correct segment in 'data'
        p[i] = data + (i * n); 
    }

    return p;
}

