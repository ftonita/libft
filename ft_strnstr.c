#include "libft.h"

size_t	ft_strnlen(const char *s, size_t maxlen)
{
	size_t	i;

	if (maxlen == 0)
		return (0);
	i = 0;
	maxlen++;
	while (*s && maxlen)
	{
		i++;
		maxlen--;
		s++;
	}
	return (i);
}

char	*ft_strnstr(const char *haystack, const char *needle, size_t qzlen)
{
	size_t	i;
	size_t	nlen;

	nlen = ft_strnlen(needle, qzlen);
	if (ft_strlen(needle) == 0)
		return ((char *)haystack);
	if (nlen == 0)
		return (NULL);
	i = 0;
	while (i <= (qzlen - nlen))
	{
		if (haystack[0] == needle[0] && !ft_strncmp(haystack, needle, nlen))
			return ((char *)haystack);
		haystack++;
		i++;
	}
	return (NULL);
}
