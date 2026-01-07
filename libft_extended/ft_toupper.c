#include <stdio.h>
#include "libft.h"

int	ft_toupper(int c)
{
	if (ft_isalpha(c) == 0)
		return (c);
	if (c >= 'a' && c <= 'z')
		return (c + ('A' - 'a'));
	return (c);
}
