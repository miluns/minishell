#include <stdio.h>
#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t		src_len;
	const char	*srcrf;
	char		*destrf;

	src_len = ft_strlen(src);
	srcrf = src;
	destrf = dest;
	if (size == 0)
		return (src_len);
	while (size > 1 && *srcrf != '\0')
	{
		*destrf = *srcrf;
		destrf++;
		srcrf++;
		size--;
	}
	if (size > 0)
		*destrf = '\0';
	return (src_len);
}
