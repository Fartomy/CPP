#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int N;
int **matrix;

// Child process function for thresholding operation
void thresholdRow(int row, int childNumber) {
    for (int j = 0; j < N; j++) {
        if (matrix[row][j] <= 127) {
            matrix[row][j] = 0;
        } else {
            matrix[row][j] = 255;
        }
    }

    // Dosyaya yaz
    char filename[20];
    snprintf(filename, sizeof(filename), "output_%d.txt", childNumber);
    FILE *outputFile = fopen(filename, "w");
    if (outputFile == NULL) {
        perror("Error opening output file");
        exit(1);
    }

    for (int j = 0; j < N; j++) {
        fprintf(outputFile, "%d ", matrix[row][j]);
    }

    fclose(outputFile);
}

int main(int argc, char **argv) {
    
    FILE *inputFile;

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
    matrix = (int **)malloc(N * sizeof(int *));
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

    // Create N child processes for thresholding
    for (int i = 0; i < N; i++) {
        pid_t child_pid = fork();

        if (child_pid == 0) {
            // Child process does the threshold operation
            thresholdRow(i, i + 1);
            exit(0);
        } else if (child_pid < 0) {
            perror("Error creating child process");
            return 1;
        }
    }

    // Main process waits for child processes to complete
    for (int i = 0; i < N; i++) {
        int status;
        wait(&status);
    }

    // The parent process reads the output files of child processes and creates an output file
    FILE *outputFile = fopen("output.txt", "w");
    if (outputFile == NULL) {
        perror("Error opening output file");
        return 1;
    }

    fprintf(outputFile, "%d\n", N);

    for (int i = 0; i < N; i++) {
        char filename[20];
        snprintf(filename, sizeof(filename), "output_%d.txt", i + 1);

        FILE *childFile = fopen(filename, "r");
        if (childFile == NULL) {
            perror("Error opening child output file");
            return 1;
        }

        int value;
        while (fscanf(childFile, "%d", &value) == 1) {
            fprintf(outputFile, "%d ", value);
        }

        fclose(childFile);
    }

    fclose(outputFile);

    // Free allocated memory
    for (int i = 0; i < N; i++) {
        free(matrix[i]);
    }
    free(matrix);

    return 0;
}
