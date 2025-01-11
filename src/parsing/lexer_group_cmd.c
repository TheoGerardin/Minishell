#include "../../includes/minishell.h"

char	*group_consecutive_cmd_tokens(t_token **temp, size_t *grouped_len)
{
	char	*grouped_value;

	grouped_value = ft_strdup((*temp)->value);
	*grouped_len = ft_strlen(grouped_value);
	while ((*temp)->next && (*temp)->next->type == CMD)
	{
		*temp = (*temp)->next;
		*grouped_len += ft_strlen((*temp)->value) + 1;
		grouped_value = (char *)realloc(grouped_value, *grouped_len + 1);
		ft_strcat(grouped_value, " ");
		ft_strcat(grouped_value, (*temp)->value);
	}
	return (grouped_value);
}

t_token	*group_cmd_tokens(t_token *head)
{
	t_token	*grouped_head;
	t_token	*temp;
	char	*grouped_value;
	size_t	grouped_len;
	t_token	*new_cmd_token;

	grouped_head = NULL;
	temp = head;
	while (temp)
	{
		if (temp->type == CMD)
		{
			grouped_value = group_consecutive_cmd_tokens(&temp, &grouped_len);
			new_cmd_token = create_token(grouped_value, CMD);
			append_token(&grouped_head, new_cmd_token);
			free(grouped_value);
		}
		else
			append_token(&grouped_head, create_token(temp->value, temp->type));
		temp = temp->next;
	}
	return (grouped_head);
}
