#include "../../includes/minishell.h"

void	ft_env(char ***envp)
{
	int	i;

	if (!*envp)
		free_and_error(NULL, NULL, "env: Env not set", 1);
	i = -1;
	while ((*envp)[++i])
		printf("%s\n", (*envp)[i]);
}
