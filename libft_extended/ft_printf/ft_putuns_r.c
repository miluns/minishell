#include "ft_printf.h"

int	ft_putuns_r(unsigned int num)
{
	int		sum;
	char	numchar;

	sum = 0;
	numchar = 0;
	if (num > 9)
		sum += ft_putuns_r(num / 10);
	sum++;
	numchar = num % 10 + '0';
	write(1, &numchar, 1);
	return (sum);
}
