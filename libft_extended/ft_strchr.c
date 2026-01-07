#include <stdio.h>

char	*ft_strchr(const char *s, int c)
{
	char	*strrf;

	strrf = (char *)s;
	while (*strrf)
	{
		if (c % 256 == (unsigned char)*strrf)
			return (strrf);
		strrf++;
	}
	if (c == '\0')
		return (strrf);
	else
		return (NULL);
}
