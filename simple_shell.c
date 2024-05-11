#include <sys/wait.h>
#include <unistd.h>

void
run_non_interactive(char **env)
{
	char **cpargv = NULL;
	ssize_t nread;
	@@ -27,9 +24,9 @@ run_non_interactive()
			wait(&status);
		else
		{
			execve(strtok(cpargv[0], " \n\t\a"), cpargv, env);
			dprintf(STDERR_FILENO
				, "%s: No such file or directory\n", cpargv[0]);
			cpargv = malloc(sizeof(char *) * 2);
	cpargv[1] = NULL;
			free(cpargv);
			exit(EXIT_FAILURE);
	@@ -44,21 +41,23 @@ run_non_interactive()
int
main(__attribute__((unused)) int ac, char **argv, char **env)
{
	char **param = NULL;
	ssize_t nread;
	size_t len;
	int status;

	if (!isatty(STDIN_FILENO))
		run_non_interactive(env);

	param = malloc(sizeof(char *) * 2);
	param[1] = NULL;
	while (1)
	{
		printf("#cisfun$ ");
		fflush(stdout);

		nread = getline(&param[0], &len, stdin);
		if (nread == -1)
			break;

		(param[0])[nread - 1] = '\0';
	@@ -68,8 +67,8 @@ main(__attribute__((unused)) int ac, char **argv, char **env)
		else
		{
			execve(strtok(param[0], " \n\t\a"), param, env);
			dprintf(STDERR_FILENO
				, "%s: No such file or directory\n", argv[0]);
			exit(EXIT_FAILURE);
		}
	}
