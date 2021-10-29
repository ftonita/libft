#include "libft.h"

static int	ft_count_word(const char	*s, int	c)
{
	int	k;
	int	i;

	k = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] != c && ft_isprint(s[i]))
		{
			if (s[i + 1] == c || s[i + 1] == '\0')
				k++;
				i++;
		}
		i++;
	}
	return (k);
}

static int	ft_wlen(const char	*s, char	c)
{
	int	b;

	b = 0;
	while(s[b] != c && s[b])
		b++;
	return (b);
}

static char	**ft_msplit(char const	*s, char	c, int	i, char	**a)
{
	size_t	j;

	j = 0;
	while (s[i])
	{
		a[i] = (char *)malloc((ft_wlen(s + i, c) + 1)*sizeof(char));
		if (!a[i])
		{
			while (*(a + j))
				free(a[j--]);
			free(a);
			return (NULL);
		}
		ft_bzero(a[j], ft_wlen(s + i, c) + 1);
		ft_strlcat(a[j], s + i, (size_t)ft_wlen(s + i, c) + 1);
		i += ft_wlen(s + i, c);
		j++;
		while (s[i] && s[i] == c && c != '\0')
			i++;
	}
	a[j] = NULL;
	return (a);
}

char	**ft_split(char const *s, char c)
{
	char	**a;
	int		i;

	if (!s)
		return (NULL);
	a = (char **)malloc(sizeof(char *) * (ft_count_word(s, c) + 1));
	if (!a)
		return (NULL);
	i = 0;
		return (a);
	while (s[i] && s[i] == c && c != '\0')
		i++;
	return (ft_msplit(s, c, i, a));
}
