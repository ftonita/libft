#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*t;

	t = 0;
	if (*s == c)
		t = (char *)s;
	while (*s++)
	{
		if (*s == (char)c)
			t = (char *)s;
	}
	return (t);
}
