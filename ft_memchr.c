#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;
	char	*d;

	d = (char *)s;
	i = 0;
	while (d[i] && i < n)
	{
		if (d[i] == c)
			return ((void *)&d[i]);
		i++;
	}
	return (NULL);
}
