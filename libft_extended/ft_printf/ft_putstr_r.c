#include "ft_printf.h"

int	ft_putstr_r(char *str)
{
	int	sum;

	sum = 0;
	if (!str)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (*str)
	{
		sum += ft_putchar_r(*str);
		str++;
	}
	return (sum);
}
