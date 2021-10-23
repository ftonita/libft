#include "libft.h"
#include <stdio.h>
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

static int	*ft_wlen(const char	*s, int	c, int	n)
{
	int	k;
	int	*b;
	int	i;

	b = (int *)malloc(n * sizeof(int));
	k = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			b[k] = 0;
			while (s[i] != c)
			{
				b[k]++;
				i++;
			}
			k++;
		}
		i++;
	}
	/*i = 0;
	while (i < n)
	{
		printf("b[%d] = %d\n", i, b[i]);
		i++;
	}*/
	return (b);
}

char	**ft_split(char const	*s, char	c)
{
	char	**a;
	int		*w;
	int		n;
	int		i;
	int		k;

	n = ft_count_word(s, c);
	a = (char **) malloc(n * sizeof(char *));
	w = (int *)malloc(n * sizeof(int));
	w = ft_wlen(s, c, n);
	i = 0;
	while (i < n)
	{
		a[i] = (char *)malloc(w[i]*sizeof(char) + 1);
		i++;
	}
	i = 0;
	k = 0;
	while (s[i])
	{
		if (s[i] != c )
		{
			ft_strlcpy(a[k], &s[i], w[k]+1);
			a[k][w[k] + 1] = '\0';
			i += w[k];
			k++;
		}
		i++;
	}
	return (a);
}/*

int main(void)
{
	ft_split("     b bqwer asf   sdf    adsfad dfssgd ,,, , .,. ", ' ');
	return 0;
}*/