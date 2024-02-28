#include "main.h"

void process_input(void);

int main(void)
{
    /* Declare variables*/
    char *user_input = NULL;
    size_t input_length = 0;
    int chars_read;

    /* String tokenization*/
    char *separators = " \n\r\t\a"; /* Set an empty string as a separator*/
    char *token;
    char *arguments[1024];
    int process_id;

    /*To handle signals */
    signal(SIGINT, signal_handler);

    while (1)
    {
        /* Prompt*/
        write(1, "Shell$ ", 7);

        /* Getting users input*/
        chars_read = getline(&user_input, &input_length, stdin);

        if (chars_read == -1)
        {
            /* When the user presses CTRL + D*/
            if (feof(stdin))
            {
                builtin_exit();
            }
            else
            {
                perror("Error reading input\n");
                return(-1);
            }
        }
        else if (chars_read == 1)
        {
            continue;
        }
        else 
        {
            int idx = 0;

            /* Process the input using string tokenization*/
            token = strtok(user_input, separators);

            /* We use a null terminating tokenization*/
            while(token != NULL)
            {
                arguments[idx] = token;
                token = strtok(NULL, separators);
                idx++;
            }
            arguments[idx] = NULL;

            /**
             * Here we can check if the token is a built-in command like (i.e, cd, exit)
             * And handle it separately  
             */

            if (strcmp(arguments[0], "cd") == 0)
            {
                /* Call for our function*/
                builtin_cd(arguments[1]);
            }
            else if(strcmp(arguments[0], "exit")== 0)
            {
                /* We want to exit*/
                builtin_exit();
            }
            else
            {
                process_id = fork();

                if (process_id == -1) /* Changed from 1 to -1*/
                {
                    perror("Fork failed");
                    free(user_input);
                    return(-1);
                }
                else if (process_id == 0)
                {
                    /*pid_t pid;*/
                    char *cmd_path = get_path(arguments[0]);
                    if (cmd_path != NULL) 
                    {

                        /* If it is not a built in command, we execute it*/

                        /* This is the child process*/


                        /* We execute the command with execve*/
                        execve(cmd_path, arguments, environ);

                        /* Check if evecve fails*/
                        err_msg(arguments[0]);
                        free(user_input); /* Free allocated memory */
                        exit(1);
                    }

                }
                else
                {
                    /* This is the parent process*/

                    int status;
                    waitpid(process_id, &status, 0);

                    if (WIFEXITED(status) && WEXITSTATUS(status) != 0)
                    {
                        printf("\nChild process %d exited with non-zero status %d\n", process_id, WEXITSTATUS(status));
                    }
                }
            }
        }/* loop ends end*/

    }
    free(user_input); /* Free allocated memory */
    printf("Is a TTY: %d\n", isatty(STDIN_FILENO));
    if (isatty(STDIN_FILENO) == 1)
    {
        printf("Inside isatty condition\n");
        write(1, "\n", 1);
    }
    return(0);
}

