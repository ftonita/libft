#include "libft.h"
#include <stdio.h>

size_t	ft_strlcpy(char	*dst, const char	*src, size_t	dstsize)
{
	size_t	i;
	size_t	c;

	i = 0;
	c = 0;
	while (src[c] != '\0')
		c++;
	if (dstsize < 1)
		return (c);
	while (i < (dstsize - 1) && i < c)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (c);
}
