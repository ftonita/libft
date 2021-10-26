#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*s;
	int		l;

	if (!s1 || !set)
		return (NULL);
	while (*s1 && ft_strchr(set, *s1))
		s1++;
	l = ft_strlen(s1);
	while (ft_strchr(set, *(s1 + l)) && l)
		l--;
	l++;
	s = ft_substr(s1, 0, l);
	return (s);
}
