#include <stdio.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*s1rf;
	unsigned char	*s2rf;

	s1rf = (unsigned char *)s1;
	s2rf = (unsigned char *)s2;
	while (n > 0)
	{
		if (*s1rf != *s2rf)
			return (*s1rf - *s2rf);
		s1rf++;
		s2rf++;
		n--;
	}
	return (0);
}
