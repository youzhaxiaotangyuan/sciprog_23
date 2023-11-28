#include <stdio.h>
#include <stdlib.h>
#define MAX_FILE_NAME 100
#include "magic_square_stub.h"

int getlines(char filename[MAX_FILE_NAME]);

int main() {  
    // Define our file variable
    FILE *f;  
    char filename[MAX_FILE_NAME];
    printf("Enter file name: ");
    scanf("%s", filename);
    
    // Get the number of lines in the file
    int n = getlines(filename);

    // Open the file 
    f = fopen(filename, "r");
    if (f == NULL) {
        fprintf(stderr, "Error opening file\n");
        exit(1);
    }

    // Allocating a matrix for storing the magic square
    // as an array of pointers, where each pointer is a row 
    int **matrix = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) {
        matrix[i] = (int *)malloc(n * sizeof(int));
    }

    // Inputting integer data into the matrix;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (fscanf(f, "%d", &matrix[i][j]) != 1) {
                fprintf(stderr, "Error reading matrix data\n");
                exit(1);
            }
        }
    }

    // Freeing each row separately before freeing the array of pointers
    for (int i = 0; i < n; i++) {
        free(matrix[i]);
    }
    free(matrix);

    // Close the file
    fclose(f);

    return 0;
}  

int getlines(char filename[MAX_FILE_NAME]) {
    FILE *fp;
    fp = fopen(filename, "r");
    
    int ch_read;
    int count = 0;

    while ((ch_read = fgetc(fp)) != EOF) {
        if (ch_read == '\n') {
            count++;
        }
    }

    printf("No. lines, %d\n", count);
    fclose(fp); 
    return count;
}
