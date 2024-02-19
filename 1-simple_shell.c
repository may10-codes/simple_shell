#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "main.h"
#include "main.c"
int main(void) {
    char *buff = NULL;
    size_t count = 0;
    ssize_t tread;

    while (1) {
        write(STDOUT_FILENO, "magic_simpleshell# ", 18);


        tread = getline(&buff, &count, stdin);

        if (tread == -1) {
            perror("Exiting shell");
            free(buff); // Free allocated memory
            exit(EXIT_FAILURE);
        } else if (tread == 0) {
            printf("End of file reached. Exiting shell.\n");
            free(buff); // Free allocated memory
            exit(EXIT_SUCCESS);
        } else {
            printf("%s", buff);
        }

        free(buff); // Free allocated memory
        buff = NULL; // Reset buffer pointer
    }

    return 0;
}

