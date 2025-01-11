#include "../includes/libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*str;
	int		len;
	int		i;
	int		j;

	i = -1;
	j = 0;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	str = (char *)malloc(sizeof(str) * (len + 1));
	if (!(str))
		return (NULL);
	while (++i < ft_strlen(s1))
		str[i] = s1[i];
	while (j < ft_strlen(s2))
		str[i++] = s2[j++];
	str[i] = '\0';
	return (str);
}
