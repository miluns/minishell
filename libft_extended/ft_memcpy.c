#include <stdio.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*destrf;
	unsigned char	*srcrf;

	destrf = (unsigned char *)dest;
	srcrf = (unsigned char *)src;
	while (n > 0)
	{
		*destrf = *srcrf;
		srcrf++;
		destrf++;
		n--;
	}
	return (dest);
}
