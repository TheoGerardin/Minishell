#include "../../includes/minishell.h"

void	ft_pwd(void)
{
	char	wd[1000];

	printf("%s\n", getcwd(wd, sizeof(wd)));
}
