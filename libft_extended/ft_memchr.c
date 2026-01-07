#include <stdio.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*strrf;

	strrf = (unsigned char *)s;
	while (n > 0)
	{
		if ((unsigned char)(c % 256) == (unsigned char)*strrf)
			return ((void *)strrf);
		strrf++;
		n--;
	}
	return (NULL);
}
