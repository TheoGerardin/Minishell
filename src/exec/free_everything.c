#include "../../includes/minishell.h"

void	free_everything(char **env, t_node *head)
{
	clear_history();
	rl_clear_history();
	signal(SIGINT, SIG_DFL);
	signal(SIGQUIT, SIG_DFL);
	if (head)
		clean_nodes(head);
	if (env)
		ft_free_array(env);
	rl_reset_terminal(NULL);
}
