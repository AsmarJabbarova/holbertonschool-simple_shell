#include <string.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

extern char **environ;


void
run_non_interactive()
{
	char **cpargv;
	ssize_t nread;
	size_t len;
	int status;

	cpargv = malloc(sizeof(char *) * 2);
	cpargv[1] = NULL;

	while ((nread = getline(&cpargv[0], &len, stdin)) != -1)
	{
		(cpargv[0])[nread - 1] = '\0';

		if (fork() > 0)
			wait(&status);
		else
		{
			execve(strtok(cpargv[0], " "), cpargv, environ);
			dprintf(STDERR_FILENO ,
				"%s: No such file or directory\n", cpargv[0]);
			free(cpargv[0]);
			free(cpargv);
			exit(EXIT_FAILURE);
		}
	}

	free(cpargv[0]);
	free(cpargv);
	exit(EXIT_SUCCESS);
}

int
main(__attribute__((unused)) int ac, char **argv, char **env)
{
	char **param = malloc(sizeof(char *) * 2);
	ssize_t nread;
	size_t len;
	int status;

	if (!isatty(STDIN_FILENO))
		run_non_interactive();

	param[1] = NULL;
	while (1)
	{
		printf("#cisfun$ ");
		fflush(stdout);

		if((nread = getline(&param[0], &len, stdin)) == -1)
			break;

		(param[0])[nread - 1] = '\0';

		if (fork() > 0)
			wait(&status);
		else
		{
			execve(strtok(param[0], " "), param, env);
			dprintf(STDERR_FILENO ,
				"%s: No such file or directory\n", argv[0]);
			exit(EXIT_FAILURE);
		}
	}

	free(param[0]);
	free(param);
	exit(EXIT_SUCCESS);
}
