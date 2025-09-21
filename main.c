#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h> // For open()

int main()
{
    int fd1;
    char *line;

    // --- Test 1: Reading from a standard text file ---
    printf("--- Test 1: Reading a file line by line ---\n");
    fd1 = open("test.txt", O_RDONLY);
    if (fd1 == -1)
    {
        perror("Error opening test.txt");
        return 1;
    }

    int i = 1;
    while ((line = get_next_line(fd1)) != NULL)
    {
        printf("Line %d: %s", i++, line);
        free(line);
    }
    close(fd1);
    printf("--- Test 1 Finished ---\n\n");


    // --- Test 2: Reading from an empty file ---
    printf("--- Test 2: Reading from an empty file ---\n");
    fd1 = open("empty.txt", O_RDONLY | O_CREAT, 0644); // Create an empty file
    if (fd1 == -1)
    {
        perror("Error creating/opening empty.txt");
        return 1;
    }
    line = get_next_line(fd1);
    if (line == NULL)
        printf("Correctly returned NULL for an empty file.\n");
    else
        printf("Incorrectly returned a line for an empty file.\n");
    free(line);
    close(fd1);
    printf("--- Test 2 Finished ---\n\n");
    unlink("empty.txt"); // Clean up the empty file


    // --- Test 3: Reading a file without a newline at the end ---
    printf("--- Test 3: File without final newline ---\n");
    fd1 = open("no_newline.txt", O_RDONLY); // You need to create this file
    if (fd1 == -1)
    {
        perror("Error opening no_newline.txt");
        return 1;
    }
    while ((line = get_next_line(fd1)) != NULL)
    {
        printf("Line: %s\n", line); // Note: manual newline for formatting
        free(line);
    }
    close(fd1);
    printf("--- Test 3 Finished ---\n\n");

    return 0;
}
