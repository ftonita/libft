#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char s;

	s = 0;
	if (n == 0)
		write(fd, "0", 1);
	while (n / 10 != 0)
	{
		s = n % 10;
		write (fd, &s, 1);
		n = n / 10;
	}
}
