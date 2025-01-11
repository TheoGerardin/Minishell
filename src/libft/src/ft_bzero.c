#include "../includes/libft.h"

void	*ft_bzero(void *b, size_t len)
{
	unsigned int	i;
	unsigned char	*bytes;

	bytes = (unsigned char *)b;
	i = 0;
	while (i < len)
	{
		bytes[i] = 0;
		i++;
	}
	return (b);
}
