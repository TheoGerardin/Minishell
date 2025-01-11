#include "../../includes/minishell.h"

int	ft_cd(char *path)
{
	char	*home;

	if (!path)
	{
		home = getenv("HOME");
		if (!home)
			free_and_error(NULL, NULL, "Home not set", 1);
		if (chdir(home) == -1)
			free_and_error(NULL, NULL, "cd: Home nout found", 1);
		return (0);
	}
	if (chdir(path) == -1)
	{
		perror("cd");
		free(path);
	}
	return (0);
}
