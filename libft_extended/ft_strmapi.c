#include <stdlib.h>
#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	index;
	char	*result;

	if (!s || !f)
		return (NULL);
	index = 0;
	result = malloc((ft_strlen(s) + 1) * sizeof(char));
	if (!result)
		return (NULL);
	while (s[index])
	{
		result[index] = f(index, s[index]);
		index++;
	}
	result[index] = '\0';
	return (result);
}
