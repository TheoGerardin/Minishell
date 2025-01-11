#include "../../includes/minishell.h"

static void	cleanup_redirections(t_redirection *redir)
{
	t_redirection	*current;
	t_redirection	*next;

	current = redir;
	while (current)
	{
		next = current->next;
		if (current->filename)
			free(current->filename);
		free(current);
		current = next;
	}
}

void	cleanup_cmd(t_node *cmd)
{
	if (!cmd)
		return ;
	if (cmd)
	{
		if (cmd->inputs)
			cleanup_redirections(cmd->inputs);
		if (cmd->outputs)
			cleanup_redirections(cmd->outputs);
		if (cmd->value)
			free(cmd->value);
		if (cmd->value)
			ft_free_array(&cmd->value);
	}
	signal(SIGINT, SIG_DFL);
	signal(SIGQUIT, SIG_DFL);
}
