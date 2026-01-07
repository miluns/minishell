#include <stdio.h>

void	ft_bzero(void *buffer, size_t n)
{
	unsigned char	*refer;

	refer = (unsigned char *)buffer;
	while (n > 0)
	{
		*refer = 0;
		refer++;
		n--;
	}
}
