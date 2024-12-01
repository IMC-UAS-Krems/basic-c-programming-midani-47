#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    // initialize random number generator
    srand(time(NULL));
    int minrand = 1;
    int maxrand = 100;

    // WRITE YOUR CODE HERE


     if (argc != 3) { //condition to restrict the args to 2 (+ 1 for the program name)
        printf("Incorrect usage. You provided %d arguments. The correct number of arguments is 2\n", argc - 1);
        return 0;}


    int rows= atoi(argv[1]); 
    int cols= atoi(argv[2]); 
    if (rows <= 0 || cols <= 0) //# argument validation
    {printf("Incorrect usage. The parameters you provided are not positive integers\n");
    return 0;}




    int **matrix = malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++) {
        matrix[i] = malloc(cols * sizeof(int));
        for (int j = 0; j < cols; j++) {matrix[i][j] = minrand + rand() % (maxrand - minrand + 1);}}

    FILE *file = fopen("matrix.txt", "ab+");
    if (file == NULL) {perror("Failed to open file");
        return 0;}

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++)
        {fprintf(file, "%d", matrix[i][j]);
            if (j < cols - 1)
                {fprintf(file, " "); }}
        if(i == rows - 1)
            {fprintf(file, "\r");} // logic for the last row to print the carriage thingy
        else
            {fprintf(file, "\n");}}

    fclose(file);

    for (int i = 0; i < rows; i++) 
        {free(matrix[i]);}
    free(matrix);

    return 0;}
