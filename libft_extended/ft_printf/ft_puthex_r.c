#include "ft_printf.h"

int	ft_puthex_r(unsigned int num, char specifier)
{
	int		sum;
	char	*base;

	sum = 0;
	if (specifier == 'x')
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	if (num >= 16)
		sum += ft_puthex_r(num / 16, specifier);
	sum++;
	write(1, &base[num % 16], 1);
	return (sum);
}
