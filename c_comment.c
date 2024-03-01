#include "main.h"

/**
*get_comments-replaces first appearance of '#' with '\0'
*@buffer:string to modify
*Return:0;
*/
void get_comments(char *buffer)
{
int i;
for (i = 0; buffer[i] != '\0'; i++)
if (buffer[i] == '#' && (!i || buffer[i - 1] == ' '))
{
buffer[i] = '\0';
break;
}
}

