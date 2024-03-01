#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

#include <sys/stat.h>
#include <signal.h>
#include <errno.h>
#include <stdbool.h>
#include <unistd.h>



#define MAX_ARGS 100
#define MAX_INPUT 1024

extern char **environ;

extern char *global_buffer;

/*used in our_getline*/

/*our_putchar*/
int our_putchar(char c);

/*our_getline*/
int our_getline(char **input, size_t *bufsize, FILE *stream);

/*our_strlen*/
size_t our_strlen(const char *str);

/*simple_shell*/

void display_prompt(void);
void read_execute_loop(void);
void execute_command_or_process(int argc, char *argv[]);
void handle_other_commands(int argc __attribute__((unused)), char *argv[]);

/*child_process*/
int child_process(char **av, char *shell, char *p, int *exit_status);


/*our_env*/
void our_env(void);
/*our_printf*/
int our_printf(const char *format, ...);

int write_strings(char *str);
int write_numbers(int nums);
/*arguments*/
int parse_arguments(char *input, char **args);
char *get_arguments(char **buffer, char **av, char *p);

/*signal handler*/
void sigint_handler(int sig);

/*execute commands*/
void execute_command(char *command, char **args);
void handle_error(const char *error_msg, char *command);
void int_to_str(int num, char *str);

/*print_hsh_error*/
void print_hsh_error(const char *message, const char *
shell_name);

int path(char **av);
int tokenize(char *s, char c);
int path_free(char **path, int num, int return_value);
void put_paths(char **path, const int num, char *tok);
int handle_path(char *command, char **args);




/*our_strdup*/
char *our_strdup(const char *s);
/*our_atoi*/
int our_atoi(const char *str);

/*our_strncmp*/
int our_strncmp(const char *s1, const char *s2, size_t n);
/*comments*/

void get_comments(char *buffer);
/*get_variable*/
void get_variables(char **tokens, int *exit_status);

int our_strcmp(const char *s1, const char *s2);
/*our_strcat*/
void our_strcat(char *dest, const char *src);
/*our_strcpy*/
void our_strcpy(char *dest, const char *src);
/*get_variable*/
void get_variables(char **tokens, int *exit_status);


#endif
