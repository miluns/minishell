#include <stdlib.h>
#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*buffer;
	size_t	size_max;

	size_max = (size_t)-1;
	buffer = NULL;
	if (nmemb == 0 || size == 0)
		return (malloc(1));
	if (size > size_max / nmemb)
		return (NULL);
	buffer = malloc(nmemb * size);
	if (!buffer)
		return (NULL);
	ft_bzero(buffer, nmemb * size);
	return (buffer);
}
