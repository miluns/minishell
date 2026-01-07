#include "ft_printf.h"

static int	ft_puthex_ptr(unsigned long num);

int	ft_putptr_r(void *ptr)
{
	int	sum;

	sum = 0;
	if (!ptr)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	sum += ft_putstr_r("0x");
	sum += ft_puthex_ptr((unsigned long)ptr);
	return (sum);
}

static int	ft_puthex_ptr(unsigned long num)
{
	int		sum;
	char	*base;

	sum = 0;
	base = "0123456789abcdef";
	if (num >= 16)
		sum += ft_puthex_ptr(num / 16);
	sum++;
	write(1, &base[num % 16], 1);
	return (sum);
}
