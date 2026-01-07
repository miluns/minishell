#include <unistd.h>
#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char			numchar;
	unsigned int	abs_n;

	numchar = 0;
	if (n < 0)
	{
		write(fd, "-", 1);
		abs_n = -n;
	}
	else
		abs_n = n;
	if (abs_n > 9)
		ft_putnbr_fd((abs_n / 10), fd);
	numchar = abs_n % 10 + '0';
	write(fd, &numchar, 1);
}
