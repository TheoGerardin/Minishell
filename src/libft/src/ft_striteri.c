#include "../includes/libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	int	i;

	i = 0;
	while (s[0] != '\0')
	{
		f(i, s);
		i++;
		s++;
	}
}
