#include <stdio.h>

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	char	*s1rf;
	char	*s2rf;
	size_t	counter;
	size_t	checker;

	s1rf = (char *)s1;
	s2rf = (char *)s2;
	checker = 0;
	if (*s2rf == '\0')
		return (s1rf);
	while (*s1rf && checker < n)
	{
		counter = 0;
		while (*(s1rf + counter) == *(s2rf + counter))
		{
			counter++;
			if (*(s2rf + counter) == '\0')
				return (s1rf);
			if (counter == n - checker || *(s1rf + counter) == '\0')
				return (NULL);
		}
		checker++;
		s1rf++;
	}
	return (NULL);
}
