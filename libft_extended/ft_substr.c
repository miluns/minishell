#include <stdlib.h>
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	sublen;
	size_t	slen;
	char	*sub;

	if (!s)
		return (NULL);
	slen = ft_strlen(s);
	if (start >= slen || len == 0)
		return (ft_strdup(""));
	if (slen - start < len)
		sublen = slen - start;
	else
		sublen = len;
	sub = malloc((sublen + 1) * sizeof(char));
	if (!sub)
		return (NULL);
	ft_strlcpy(sub, s + start, sublen + 1);
	return (sub);
}
