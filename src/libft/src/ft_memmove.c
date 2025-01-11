#include "../includes/libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*a;
	unsigned char	*b;
	unsigned int	i;

	a = (unsigned char *)dst;
	b = (unsigned char *)src;
	i = -1;
	if (a == b)
		return (dst);
	if (a < b || a > b + len)
	{
		while (++i < len)
			a[i] = b[i];
	}
	else
	{
		i = len + 1;
		while (--i)
			a[i - 1] = b[i - 1];
	}
	return (dst);
}
