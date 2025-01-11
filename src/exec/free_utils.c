#include "../../includes/minishell.h"

void	ft_free_array(char **array)
{
	size_t	i;

	if (!array)
		return ;
	i = 0;
	while (array[i])
	{
		free(array[i]);
		array[i] = NULL;
		i++;
	}
	free(array);
}

void	ft_free(void *ptr)
{
	free(ptr);
}

void	free_and_error(char *ptr, char **ptr2, char *msg, bool error)
{
	if (ptr)
		ft_free(ptr);
	if (ptr2)
		ft_free_array(ptr2);
	if (error)
	{
		printf("%s\n", msg);
		exit(EXIT_FAILURE);
	}
	exit(EXIT_SUCCESS);
}

void	free_triple_pointer(char ***array)
{
	int	i;
	int	j;

	i = -1;
	j = -1;
	if (array == NULL)
		return ;
	while (array[++i])
	{
		while (array[i][++j])
			free(array[i][j]);
		free(array[i]);
	}
	free(array);
}
