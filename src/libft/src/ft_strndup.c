#include "../includes/libft.h"

char	*ft_strndup(const char *str, int n)
{
	char	*dup;
	int		i;
	int		len;

	i = 0;
	len = ft_strlen(str);
	if (n > len)
		n = len;
	dup = (char *)malloc(sizeof(char) * (n + 1));
	if (!dup)
		return (NULL);
	while (i < n)
	{
		dup[i] = str[i];
		i++;
	}
	dup[n] = '\0';
	return (dup);
}
