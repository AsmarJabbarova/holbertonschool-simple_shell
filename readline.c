#include "shell.h"


char *readline(void)
{
	char *line = NULL;
	size_t line_size = NULL;

	if (getline(&line, &line_size, stdin) == 1)
	{
		free(line);
		return (NULL);
	}

	return (line);
}
