#include "main.h"

/**
 * Function: get_path
 * -------------------
 * Searches through the PATH environment variable to find the executable path of a command.
 * 
 * command: The command whose path is to be found.
 * 
 * Returns: The full path of the command if found, otherwise returns the command itself.
 */
char *get_path(char *command)
{
  char *path = getenv("PATH");
  char *path_copy = strdup(path);
  char command_path[1024];
  char *dir = strtok(path_copy, ":");
  
  /* Loop through each directory in the PATH */
  while (dir != NULL) 
  {
    strcpy(command_path, dir);
    
    /* Append '/' if it's not already present */
    if (command_path[strlen(command_path) - 1] != '/')
    {
      strcat(command_path, "/");
    }

    /* Append the command to the path */
    strcat(command_path, command);

    /* Check if the command exists in the directory */
    if (access(command_path, X_OK) == 0)
    {
      free(path_copy);
      return (strdup(command_path));
    }

    /* Move to the next directory */
    dir = strtok(NULL, ":");
  }
  free(path_copy);
  return (command);
}

