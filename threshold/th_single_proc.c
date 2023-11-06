#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    FILE *inputFile, *outputFile;
    int N;

    // Check the args
    if (argc != 2) {
        printf("Usage: %s <Input File Name>\n", argv[0]);
        exit(1);
    }

    // Open the input file for reading
    inputFile = fopen(argv[1], "r");
    if (inputFile == NULL) {
        perror("Error opening input file");
        return 1;
    }

    // Read the size N of the image from the first line
    if (fscanf(inputFile, "%d", &N) != 1) {
        fprintf(stderr, "Error reading N from input file");
        fclose(inputFile);
        return 1;
    }

    // Create a two-dimensional NxN array
    int **matrix = (int **)malloc(N * sizeof(int *));
    for (int i = 0; i < N; i++) {
        matrix[i] = (int *)malloc(N * sizeof(int));
    }

    // Read the remaining lines and fill the matrix
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (fscanf(inputFile, "%d", &matrix[i][j]) != 1) {
                fprintf(stderr, "Error reading matrix element at (%d, %d)", i, j);
                fclose(inputFile);
                return 1;
            }
        }
    }

    // Close the input file
    fclose(inputFile);

    // Thresholding operation
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (matrix[i][j] <= 127) {
                matrix[i][j] = 0;
            } else {
                matrix[i][j] = 255;
            }
        }
    }

    // Open the output file for writing
    outputFile = fopen("output.txt", "w");
    if (outputFile == NULL) {
        perror("Error opening output file");
        return 1;
    }

    // Write the contents of the matrix to the output file
    fprintf(outputFile, "%d\n", N);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            fprintf(outputFile, "%d ", matrix[i][j]);
        }
        fprintf(outputFile, "\n");
    }

    // Close the output file
    fclose(outputFile);

    // Free allocated memory
    for (int i = 0; i < N; i++) {
        free(matrix[i]);
    }
    free(matrix);

    return 0;
}
