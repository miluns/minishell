#include <stdio.h>

void	*ft_memset(void *buffer, int c, size_t n)
{
	unsigned char	*refer;
	unsigned char	i;

	refer = (unsigned char *)buffer;
	i = (unsigned char)c;
	while (n > 0)
	{
		*refer = i;
		refer++;
		n--;
	}
	return (buffer);
}
