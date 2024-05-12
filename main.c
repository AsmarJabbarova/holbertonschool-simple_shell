#include "shell.h"

/**
 * main - Base functionality of shell.
 *
 * Return: Always 0.
 */
int main(void)
{
	int i = 0, turn = 0;
	char *line = NULL;
	char **args = NULL;

	while (1)
	{
		line = readline();
		if (!line)
			break;
		args = parse_line(line, " \n\t");
		free(line);
		if (!args[0])
		{
			for (i = 0; args[i]; i++)
				free(args[i]);
			free(args);
			continue; }
		else if
