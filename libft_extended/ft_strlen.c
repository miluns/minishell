#include <stdio.h>

size_t	ft_strlen(const char *s)
{
	unsigned int	counter;
	const char		*refer;

	if (!s)
		return (0);
	refer = s;
	counter = 0;
	while (*refer)
	{
		counter++;
		refer++;
	}
	return (counter);
}
