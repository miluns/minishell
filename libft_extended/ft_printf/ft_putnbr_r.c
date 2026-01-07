#include "ft_printf.h"

int	ft_putnbr_r(int num)
{
	unsigned int	number;
	char			numchar;
	int				sum;

	numchar = 0;
	sum = 0;
	if (num < 0)
	{
		write(1, "-", 1);
		sum++;
		number = -num;
	}
	else
		number = num;
	if (number > 9)
		sum += ft_putnbr_r(number / 10);
	numchar = number % 10 + '0';
	sum++;
	write(1, &numchar, 1);
	return (sum);
}
