#include <stdlib.h>
#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*sdup;

	sdup = malloc((ft_strlen(s) + 1) * sizeof(char));
	if (!sdup)
		return (NULL);
	ft_strlcpy(sdup, s, ft_strlen(s) + 1);
	return (sdup);
}
