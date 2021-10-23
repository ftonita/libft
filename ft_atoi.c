#include "libft.h"

int	ft_isspace(char c)
{
	if (c == 32 || (c >= 9 && c <= 13))
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	int			i;
	long int	n;
	int			c[2];

	i = 0;
	c[0] = 0;
	c[1] = 0;
	n = 0;
	while (!ft_isdigit(str[i]))
	{
		if (str[i] == '-')
			c[0]++;
		if (str[i] == '+')
			c[1]++;
		if ((!ft_isspace(str[i]) && str[i] != '-' && str[i] != '+')
			|| (c[0] + c[1] > 1))
			return (0);
		i++;
	}
	i--;
	while (ft_isdigit(str[++i]) && str[i])
		n = n * 10 + ((long int)str[i] - 48);
	if (c[0] == 1)
		n = -n;
	return (n);
}
