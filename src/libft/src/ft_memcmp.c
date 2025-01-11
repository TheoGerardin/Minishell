#include "../includes/libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned int	i;
	unsigned char	*bytes_s1;
	unsigned char	*bytes_s2;

	bytes_s1 = (unsigned char *)s1;
	bytes_s2 = (unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (bytes_s1[i] != bytes_s2[i])
			return ((int)(unsigned char)bytes_s1[i]
				- (unsigned char)bytes_s2[i]);
		i++;
	}
	return (0);
}

/*int main (void)
{
	char str[] = "\200";
	char str2[] = "\0";
	char str3[] = "\200";
	char str4[] = "\0";
	int n = 6;
	printf("%d\n",ft_memcmp(str, str2, n));
	printf("%d", memcmp(str3, str4, n));
}*/