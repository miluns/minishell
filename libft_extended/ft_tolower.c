#include <stdio.h>
#include "libft.h"

int	ft_tolower(int c)
{
	if (ft_isalpha(c) == 0)
		return (c);
	if (c >= 'A' && c <= 'Z')
		return (c + ('a' - 'A'));
	return (c);
}
