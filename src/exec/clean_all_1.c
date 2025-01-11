#include "../../includes/minishell.h"

// token seul
void	clean_token(t_token *token)
{
	if (token->value)
		free(token->value);
	free(token);
}

// chaine de tokens
void	clean_tokens(t_token *tokens)
{
	t_token	*current;
	t_token	*next;

	current = tokens;
	while (current)
	{
		next = current->next;
		clean_token(current);
		current = next;
	}
}

// node seule
void	clean_node(t_node *node)
{
	if (node->value)
		free(node->value);
	free(node);
}

// chaines de nodes
void	clean_nodes(t_node *head)
{
	t_node	*current;
	t_node	*next;

	current = head;
	while (current)
	{
		next = current->next;
		clean_node(current);
		current = next;
	}
}
