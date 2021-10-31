#include "libft.h"

static char	*ft_mitoa(int	n, int	i, int	c)
{
	char	*s;

	s = (char *)malloc((i + 2) * sizeof(char));
	if (!s)
	{
		free(s);
		return (NULL);
	}
	ft_bzero(s, i + 2);
	if (n >= 0)
		while (i >= c)
		{
			s[i - c] = n % 10 + 48;
			n = n / 10;
			c++;
		}
	else
		while (i > c)
		{
			s[i - c] = -(n % 10) + '0';
			n = n / 10;
			s[0] = '-';
			c++;
		}
	return (s);
}
char	*ft_itoa(int n)
{
	char	*a;
	int		i;
	int		c;

	i = 0;
	c = n;
	while ((c = c / 10) != 0 && ++i)
		;
	if (n < 0)
		i++;
	a = (char *)malloc((i + 2) * sizeof(char));
	if (!a)
	{	
		free(a);
		return (NULL);
	}
	ft_bzero(a, i + 2);
	a = ft_mitoa(n, i, c);
	return (a);
}
