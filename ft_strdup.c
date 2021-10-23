#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*s;
	size_t	i;

	s = (char *)malloc(sizeof(char) * (ft_strlen(s1) + 1));
	i = 0;
	while (i <= ft_strlen(s1))
	{
		s[i] = s1[i];
		i++;
	}
	return (s);
}
