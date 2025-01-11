#include "../includes/libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;
	size_t	len;

	len = count * size;
	ptr = malloc(len);
	if (ptr != NULL)
		ft_bzero(ptr, len);
	return (ptr);
}
